#include <iostream>
#include <string>
#include <memory>
#include <set>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <VulkanWrapper/VulkanWrapper.h>

const std::vector<std::string> validationLayers = {
    "VK_LAYER_LUNARG_standard_validation"
};

const std::vector<std::string> deviceExtensions = {
    "VK_KHR_swapchain"
};

class HelloTriangle {
public:
    int width;
    int height;
    GLFWwindow* window;

    std::unique_ptr<vk::Instance> instance;
    std::unique_ptr<vk::Surface> surface;
    const vk::PhysicalDevice* physicalDevice;
    uint32_t graphicsQueueIndex;
    uint32_t presentQueueIndex;
    std::unique_ptr<vk::Device> device;
    const vk::Queue* graphicsQueue;
    const vk::Queue* presentQueue;
    std::unique_ptr<vk::Swapchain> swapchain;
    std::vector<vk::ImageView> imageViews;
    std::unique_ptr<vk::RenderPass> renderPass;
    std::vector<vk::Framebuffer> framebuffers;
    std::unique_ptr<vk::CommandPool> commandPool;
    std::vector<vk::CommandBuffer> commandBuffers;
    std::unique_ptr<vk::Semaphore> imageAcquireSemaphore;
    std::unique_ptr<vk::Semaphore> renderSemaphore;
    std::vector<vk::Fence> fences;

    HelloTriangle(GLFWwindow* window, int width, int height) {
        this->window = window;
    }

    void run() {
        createInstance();
        createSurface();
        pickPhysicalDevice();
        createDevice();
        createSwapchain();
        createImageViews();
        createRenderPass();
        createFramebuffers();
        createCommandPool();
        createSemaphores();
        createFences();
        mainLoop();
    }

    bool checkValidationSupport() {
        auto available = vk::Instance::availableLayers();
        std::set<std::string> requestedLayers(validationLayers.begin(), validationLayers.end());

        for (auto& layer : available) {
            requestedLayers.erase(layer.layerName);
        }

        return requestedLayers.empty();
    }

    void createInstance() {
        vk::ApplicationInfo appInfo = {};
        appInfo.applicationName = "Hello Triangle";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;

        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        //GLFW already provides the extensions in a format that the Vulkan API can accept
        std::vector<std::string> extensions(glfwExtensionCount);
        for (uint32_t i = 0; i < glfwExtensionCount; i++) {
            extensions[i] = glfwExtensions[i];
        }

        vk::InstanceCreateInfo info = {};
        info.applicationInfo = &appInfo;
        info.enabledExtensionNames = extensions;

        if (checkValidationSupport()) {
            info.enabledLayerNames = validationLayers;
        }

        instance = std::make_unique<vk::Instance>(info);
    }

    void createSurface() {
        VkSurfaceKHR surface;
        VKW_CHECK(glfwCreateWindowSurface(instance->handle(), window, instance->callbacks(), &surface));
        this->surface = std::make_unique<vk::Surface>(*instance, surface);
    }

    bool checkSwapchainSupport(const vk::PhysicalDevice& physicalDevice) {
        auto& available = physicalDevice.availableExtensions();
        std::set<std::string> requestedExtensions(deviceExtensions.begin(), deviceExtensions.end());

        for (auto& extension : available) {
            requestedExtensions.erase(extension.extensionName);
        }

        std::vector<vk::SurfaceFormat> formats = surface->getFormats(physicalDevice);
        std::vector<vk::PresentMode> modes = surface->getPresentModes(physicalDevice);

        return requestedExtensions.empty() && formats.size() > 0 && modes.size() > 0;
    }

    bool isDeviceSuitable(const vk::PhysicalDevice& physicalDevice, uint32_t& graphicsQueueIndex, uint32_t& presentQueueIndex) {
        if (!checkSwapchainSupport(physicalDevice)) return false;

        bool graphicsFound = false;
        bool presentFound = false;
        auto& families = physicalDevice.queueFamilies();
        for (uint32_t i = 0; i < families.size(); i++) {
            auto& queueFamily = families[i];
            if (queueFamily.queueCount > 0 && (queueFamily.queueFlags & vk::QueueFlags::Graphics) != vk::QueueFlags::None) {
                graphicsFound = true;
                graphicsQueueIndex = i;
            }

            if (surface->supported(physicalDevice, i)) {
                presentFound = true;
                presentQueueIndex = i;
            }

            if (graphicsFound && presentFound) break;
        }

        return graphicsFound;
    }

    void pickPhysicalDevice() {
        auto& physicalDevices = instance->physicalDevices();
        if (physicalDevices.size() == 0) throw std::runtime_error("Failed to find physical devices");

        for (auto& physicalDevice : physicalDevices) {
            uint32_t graphicsQueueIndex;
            uint32_t presentQueueIndex;

            if (isDeviceSuitable(physicalDevice, graphicsQueueIndex, presentQueueIndex)) {
                this->physicalDevice = &physicalDevice;
                this->graphicsQueueIndex = graphicsQueueIndex;
                this->presentQueueIndex = presentQueueIndex;
                break;
            }
        }

        if (physicalDevice == nullptr) {
            throw std::runtime_error("Failed to find a suitable physical device");
        }
    }

    void createDevice() {
        std::set<uint32_t> indices = { graphicsQueueIndex, presentQueueIndex };
        std::vector<vk::DeviceQueueCreateInfo> queueInfos;

        for (auto i : indices) {
            vk::DeviceQueueCreateInfo info = {};
            info.queueFamilyIndex = i;
            info.queueCount = 1;
            info.queuePriorities = { 1 };
            queueInfos.push_back(info);
        }
        
        vk::PhysicalDeviceFeatures deviceFeatures = {};

        vk::DeviceCreateInfo info = {};
        info.queueCreateInfos = queueInfos;
        info.enabledFeatures = &deviceFeatures;
        info.enabledExtensionNames = deviceExtensions;

        device = std::make_unique<vk::Device>(*physicalDevice, info);

        graphicsQueue = &device->getQueue(graphicsQueueIndex, 0);
        presentQueue = &device->getQueue(presentQueueIndex, 0);
    }
    
    vk::SurfaceFormat chooseSurfaceFormat(const std::vector<vk::SurfaceFormat>& formats) {
        if (formats.size() == 1 && formats[0].format == vk::Format::Undefined) {
            return { vk::Format::R8G8B8A8_Unorm, vk::ColorSpace::SrgbNonlinear };
        }

        for (auto& format : formats) {
            if (format.colorSpace == vk::ColorSpace::SrgbNonlinear
                && (format.format == vk::Format::R8G8B8A8_Unorm || format.format == vk::Format::B8G8R8A8_Unorm)) {
                return format;
            }
        }

        return formats[0];
    }

    vk::PresentMode choosePresentMode(const std::vector<vk::PresentMode>& modes) {
        for (auto mode : modes) {
            if (mode == vk::PresentMode::Fifo) {
                return mode;
            }
        }

        for (auto mode : modes) {
            if (mode == vk::PresentMode::Immediate) {
                return mode;
            }
        }

        throw std::runtime_error("Failed to find presentation mode");
    }

    vk::Extent2D chooseExtent(const vk::SurfaceCapabilities& capabilities) {
        if (capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max()) {
            return capabilities.currentExtent;
        } else {
            VkExtent2D actualExtent = { static_cast<uint32_t>(width), static_cast<uint32_t>(height) };

            actualExtent.width = std::max(capabilities.minImageExtent.width, std::min(capabilities.maxImageExtent.width, actualExtent.width));
            actualExtent.height = std::max(capabilities.minImageExtent.height, std::min(capabilities.maxImageExtent.height, actualExtent.height));

            return actualExtent;
        }
    }

    void createSwapchain() {
        auto capabilities = surface->getCapabilities(*physicalDevice);
        auto formats = surface->getFormats(*physicalDevice);
        auto presentModes = surface->getPresentModes(*physicalDevice);

        auto format = chooseSurfaceFormat(formats);
        auto presentMode = choosePresentMode(presentModes);
        auto extent = chooseExtent(capabilities);

        uint32_t imageCount = 2;
        if (capabilities.maxImageCount > 0 && imageCount > capabilities.maxImageCount) {
            imageCount = capabilities.maxImageCount;
        }

        vk::SwapchainCreateInfo info(*surface);
        info.flags = vk::SwapchainCreateFlags::None;
        info.minImageCount = imageCount;
        info.imageFormat = format.format;
        info.imageColorSpace = format.colorSpace;
        info.imageExtent = extent;
        info.imageArrayLayers = 1;
        info.imageUsage = vk::ImageUsageFlags::ColorAttachment;

        if (graphicsQueue->familyIndex() != presentQueue->familyIndex()) {
            info.imageSharingMode = vk::SharingMode::Concurrent;
            info.queueFamilyIndices = { graphicsQueueIndex, presentQueueIndex };
        } else {
            info.imageSharingMode = vk::SharingMode::Exclusive;
        }

        info.preTransform = capabilities.currentTransform;
        info.compositeAlpha = vk::CompositeAlphaFlags::Opaque;
        info.presentMode = presentMode;
        info.clipped = true;
        info.oldSwapchain = nullptr;

        swapchain = std::make_unique<vk::Swapchain>(*device, info);
    }

    void createImageViews() {
        imageViews.reserve(swapchain->images().size());
        for (auto& image : swapchain->images()) {
            vk::ImageViewCreateInfo info(image);
            info.format = swapchain->format();
            info.viewType = vk::ImageViewType::_2D;
            info.components = {};
            info.subresourceRange.aspectMask = vk::ImageAspectFlags::Color;
            info.subresourceRange.baseArrayLayer = 0;
            info.subresourceRange.layerCount = 1;
            info.subresourceRange.baseMipLevel = 0;
            info.subresourceRange.levelCount = 1;

            imageViews.emplace_back(*device, info);
        }
    }

    void createRenderPass() {
        vk::AttachmentDescription colorAttachment = {};
        colorAttachment.format = swapchain->format();
        colorAttachment.samples = vk::SampleCountFlags::_1;
        colorAttachment.loadOp = vk::AttachmentLoadOp::Clear;
        colorAttachment.storeOp = vk::AttachmentStoreOp::Store;
        colorAttachment.initialLayout = vk::ImageLayout::Undefined;
        colorAttachment.finalLayout = vk::ImageLayout::PresentSrcKhr;

        vk::AttachmentReference colorAttachmentRef = {};
        colorAttachmentRef.attachment = 0;
        colorAttachmentRef.layout = vk::ImageLayout::ColorAttachmentOptimal;

        vk::SubpassDescription subpass = {};
        subpass.pipelineBindPoint = vk::PipelineBindPoint::Graphics;
        subpass.colorAttachments = { colorAttachmentRef };

        vk::RenderPassCreateInfo info = {};
        info.attachments = { colorAttachment };
        info.subpasses = { subpass };

        renderPass = std::make_unique<vk::RenderPass>(*device, info);
    }

    void createFramebuffers() {
        framebuffers.reserve(swapchain->images().size());
        for (size_t i = 0; i < swapchain->images().size(); i++) {
            vk::FramebufferCreateInfo info(*renderPass);
            info.attachments = { imageViews[i] };
            info.width = swapchain->extent().width;
            info.height = swapchain->extent().height;
            info.layers = 1;

            framebuffers.emplace_back(*device, info);
        }
    }

    void createCommandPool() {
        vk::CommandPoolCreateInfo info = {};
        info.queueFamilyIndex = graphicsQueueIndex;

        commandPool = std::make_unique<vk::CommandPool>(*device, info);

        vk::CommandBufferAllocateInfo allocInfo(*commandPool);
        allocInfo.commandBufferCount = static_cast<uint32_t>(swapchain->images().size());
        allocInfo.level = vk::CommandBufferLevel::Primary;

        commandBuffers = commandPool->allocate(allocInfo);

        for (size_t i = 0; i < commandBuffers.size(); i++) {
            recordCommands(commandBuffers[i], i);
        }
    }

    void recordCommands(const vk::CommandBuffer& commandBuffer, size_t index) {
        vk::CommandBufferBeginInfo beginInfo = {};
        commandBuffer.begin(beginInfo);

        vk::RenderPassBeginInfo info = {};
        info.renderPass = renderPass.get();
        info.framebuffer = &framebuffers[index];
        info.renderArea = { {}, swapchain->extent() };
        info.clearValues = { {} };

        commandBuffer.beginRenderPass(info, vk::SubpassContents::Inline);
        commandBuffer.endRenderPass();

        commandBuffer.end();
    }

    void createSemaphores() {
        vk::SemaphoreCreateInfo info = {};
        imageAcquireSemaphore = std::make_unique<vk::Semaphore>(*device, info);
        renderSemaphore = std::make_unique<vk::Semaphore>(*device, info);
    }

    void createFences() {
        vk::FenceCreateInfo info = {};
        info.flags = vk::FenceCreateFlags::Signaled;

        fences.reserve(swapchain->images().size());
        for (size_t i = 0; i < swapchain->images().size(); i++) {
            fences.emplace_back(*device, info);
        }
    }

    void mainLoop() {
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();

            uint32_t index = swapchain->acquireNextImage(~0ull, imageAcquireSemaphore.get(), nullptr);

            vk::SubmitInfo submitInfo = {};
            submitInfo.commandBuffers = { commandBuffers[index] };
            submitInfo.waitSemaphores = { *imageAcquireSemaphore };
            submitInfo.waitDstStageMask = { vk::PipelineStageFlags::TopOfPipe };
            submitInfo.signalSemaphores = { *renderSemaphore };

            fences[index].wait();
            fences[index].reset();
            graphicsQueue->submit({ submitInfo }, &fences[index]);

            vk::PresentInfo presentInfo = {};
            presentInfo.swapchains = { *swapchain };
            presentInfo.imageIndices = { index };
            presentInfo.waitSemaphores = { *renderSemaphore };

            presentQueue->present(presentInfo);
        }
    }
};

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Triangle", nullptr, nullptr);

    HelloTriangle app(window, 800, 600);
    app.run();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}