#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <set>
#include <chrono>
#include <sstream>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <VulkanWrapper/VulkanWrapper.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

const std::vector<std::string> validationLayers = {
    "VK_LAYER_LUNARG_standard_validation"
};

const std::vector<std::string> deviceExtensions = {
    "VK_KHR_swapchain"
};

struct Uniform {
    glm::mat4 projView;
    glm::mat4 model;
};

struct Vertex {
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 uv;

    static std::vector<vk::VertexInputBindingDescription> getBindingDescription() {
        vk::VertexInputBindingDescription binding = {};
        binding.binding = 0;
        binding.inputRate = vk::VertexInputRate::Vertex;
        binding.stride = sizeof(Vertex);

        return { binding };
    }

    static std::vector<vk::VertexInputAttributeDescription> getAttributeDescriptions() {
        vk::VertexInputAttributeDescription attribute0 = {};
        attribute0.binding = 0;
        attribute0.location = 0;
        attribute0.offset = offsetof(Vertex, position);
        attribute0.format = vk::Format::R32G32B32_Sfloat;

        vk::VertexInputAttributeDescription attribute1 = {};
        attribute1.binding = 0;
        attribute1.location = 1;
        attribute1.offset = offsetof(Vertex, color);
        attribute1.format = vk::Format::R32G32B32_Sfloat;

        vk::VertexInputAttributeDescription attribute2 = {};
        attribute2.binding = 0;
        attribute2.location = 2;
        attribute2.offset = offsetof(Vertex, uv);
        attribute2.format = vk::Format::R32G32_Sfloat;

        return { attribute0, attribute1, attribute2 };
    }
};

std::vector<Vertex> vertices = {
    { { -0.5f, -0.5f,  0.0f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 0.0f } },
    { {  0.5f, -0.5f,  0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f } },
    { {  0.5f,  0.5f,  0.0f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f } },
    { { -0.5f,  0.5f,  0.0f }, { 1.0f, 1.0f, 1.0f }, { 1.0f, 1.0f } },
    
    { { -0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 0.0f } },
    { {  0.5f, -0.5f, -0.5f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f } },
    { {  0.5f,  0.5f, -0.5f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f } },
    { { -0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, { 1.0f, 1.0f } }
};

std::vector<uint32_t> indices = {
    0, 1, 2, 2, 3, 0,
    4, 5, 6, 6, 7, 4
};

class HelloTriangle {
public:
    int width;
    int height;
    GLFWwindow* window;
    bool resizeFlag = false;

    std::unique_ptr<vk::Instance> instance;
    std::unique_ptr<vk::Surface> surface;
    const vk::PhysicalDevice* physicalDevice;
    uint32_t graphicsQueueIndex;
    uint32_t presentQueueIndex;
    std::unique_ptr<vk::Device> device;
    const vk::Queue* graphicsQueue;
    const vk::Queue* presentQueue;
    std::unique_ptr<vk::Buffer> vertexBuffer;
    std::unique_ptr<vk::DeviceMemory> vertexBufferMemory;
    std::unique_ptr<vk::Buffer> indexBuffer;
    std::unique_ptr<vk::DeviceMemory> indexBufferMemory;
    std::unique_ptr<vk::Buffer> uniformBuffer;
    std::unique_ptr<vk::DeviceMemory> uniformBufferMemory;
    void* uniformMapping;
    std::unique_ptr<vk::Image> texture;
    std::unique_ptr<vk::DeviceMemory> textureMemory;
    std::unique_ptr<vk::ImageView> textureImageView;
    std::unique_ptr<vk::Sampler> sampler;
    std::unique_ptr<vk::DescriptorSetLayout> descriptorSetLayout;
    std::unique_ptr<vk::DescriptorPool> descriptorPool;
    std::unique_ptr<vk::DescriptorSet> descriptorSet;
    std::unique_ptr<vk::Swapchain> swapchain;
    std::vector<vk::ImageView> imageViews;
    vk::Format depthFormat;
    std::unique_ptr<vk::Image> depthImage;
    std::unique_ptr<vk::DeviceMemory> depthImageMemory;
    std::unique_ptr<vk::ImageView> depthImageView;
    std::unique_ptr<vk::RenderPass> renderPass;
    std::vector<vk::Framebuffer> framebuffers;
    std::unique_ptr<vk::PipelineLayout> pipelineLayout;
    std::unique_ptr<vk::Pipeline> pipeline;
    std::unique_ptr<vk::CommandPool> commandPool;
    std::vector<vk::CommandBuffer> commandBuffers;
    std::unique_ptr<vk::Semaphore> imageAcquireSemaphore;
    std::unique_ptr<vk::Semaphore> renderSemaphore;
    std::vector<vk::Fence> fences;

    HelloTriangle(GLFWwindow* window, int width, int height) {
        this->window = window;
        this->width = width;
        this->height = height;
    }

    ~HelloTriangle() {
        device->waitIdle();
    }

    void run() {
        initWindow();
        createInstance();
        createSurface();
        pickPhysicalDevice();
        createDevice();
        createCommandPool();
        createVertexBuffer();
        createIndexBuffer();
        createUniformBuffer();
        createTexture();
        createTextureImageView();
        createSampler();
        createDescriptorSetLayout();
        createDescriptorPool();
        createDescriptorSet();
        createPipelineLayout();
        recreateSwapchain();
        createSemaphores();
        createFences();
        mainLoop();
    }

    static void resize_callback(GLFWwindow* window, int width, int height) {
        HelloTriangle& hello = *reinterpret_cast<HelloTriangle*>(glfwGetWindowUserPointer(window));
        hello.resize(width, height);
    }

    void resize(int width, int height) {
        if (glfwGetWindowAttrib(window, GLFW_ICONIFIED) != 1 && (width != this->width || height != this->height)) {
            resizeFlag = true;
            this->width = width;
            this->height = height;
        }
    }

    void initWindow() {
        glfwSetWindowUserPointer(window, this);
        glfwSetWindowSizeCallback(window, &resize_callback);
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
        const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

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

    vk::CommandBuffer getSingleUseCommandBuffer() {
        vk::CommandBufferAllocateInfo info = {};
        info.commandPool = commandPool.get();
        info.commandBufferCount = 1;

        vk::CommandBuffer commandBuffer(std::move(commandPool->allocate(info)[0]));
        commandBuffer.setDestructorEnabled(true);

        vk::CommandBufferBeginInfo beginInfo = {};
        beginInfo.flags = vk::CommandBufferUsageFlags::OneTimeSubmit;
        commandBuffer.begin(beginInfo);

        return commandBuffer;
    }

    void submitSingleUseCommandBuffer(vk::CommandBuffer& commandBuffer) {
        commandBuffer.end();

        vk::SubmitInfo info = {};
        info.commandBuffers = { commandBuffer };

        graphicsQueue->submit(info, nullptr);
        graphicsQueue->waitIdle();
    }

    uint32_t findMemoryType(uint32_t memoryBits, vk::MemoryPropertyFlags flags) {
        const std::vector<vk::MemoryType>& types = physicalDevice->memoryProperties().memoryTypes;
        for (uint32_t i = 0; i < static_cast<uint32_t>(types.size()); i++) {
            if ((memoryBits & (1 << i)) && (types[i].propertyFlags & flags) == flags) {
                return i;
            }
        }

        throw std::runtime_error("Failed to find suitable memory type");
    }

    vk::DeviceMemory allocate(vk::MemoryRequirements& requirements, vk::MemoryPropertyFlags flags) {
        vk::MemoryAllocateInfo info = {};
        info.allocationSize = requirements.size;
        info.memoryTypeIndex = findMemoryType(requirements.memoryTypeBits, flags);

        return vk::DeviceMemory(*device, info);
    }

    vk::Buffer createBuffer(size_t size, vk::BufferUsageFlags usage) {
        vk::BufferCreateInfo info = {};
        info.size = size;
        info.usage = usage;

        return vk::Buffer(*device, info);
    }

    void copy(vk::Buffer& dst, void* src, size_t size) {
        vk::Buffer staging = createBuffer(size, vk::BufferUsageFlags::TransferSrc);
        vk::DeviceMemory stagingMemory = allocate(staging.requirements(), vk::MemoryPropertyFlags::HostVisible | vk::MemoryPropertyFlags::HostCoherent);
        staging.bind(stagingMemory, 0);
        void* ptr = stagingMemory.map(0, stagingMemory.size());

        std::memcpy(ptr, src, size);

        vk::CommandBuffer commandBuffer = getSingleUseCommandBuffer();

        vk::BufferCopy copy = {};
        copy.size = size;

        commandBuffer.copyBuffer(staging, dst, copy);

        submitSingleUseCommandBuffer(commandBuffer);
    }

    void createVertexBuffer() {
        vertexBuffer = std::make_unique<vk::Buffer>(
            createBuffer(sizeof(Vertex) * vertices.size(), vk::BufferUsageFlags::VertexBuffer | vk::BufferUsageFlags::TransferDst)
        );

        vertexBufferMemory = std::make_unique<vk::DeviceMemory>(
            allocate(vertexBuffer->requirements(), vk::MemoryPropertyFlags::DeviceLocal)
        );

        vertexBuffer->bind(*vertexBufferMemory, 0);

        copy(*vertexBuffer, vertices.data(), sizeof(Vertex) * vertices.size());
    }

    void createIndexBuffer() {
        indexBuffer = std::make_unique<vk::Buffer>(
            createBuffer(sizeof(uint32_t) * indices.size(), vk::BufferUsageFlags::IndexBuffer | vk::BufferUsageFlags::TransferDst)
        );

        indexBufferMemory = std::make_unique<vk::DeviceMemory>(
            allocate(indexBuffer->requirements(), vk::MemoryPropertyFlags::DeviceLocal)
        );

        indexBuffer->bind(*indexBufferMemory, 0);

        copy(*indexBuffer, indices.data(), sizeof(uint32_t) * indices.size());
    }

    void createUniformBuffer() {
        uniformBuffer = std::make_unique<vk::Buffer>(
            createBuffer(sizeof(Uniform), vk::BufferUsageFlags::UniformBuffer)
        );

        uniformBufferMemory = std::make_unique<vk::DeviceMemory>(
            allocate(uniformBuffer->requirements(), vk::MemoryPropertyFlags::HostVisible | vk::MemoryPropertyFlags::HostCoherent)
        );

        uniformBuffer->bind(*uniformBufferMemory, 0);

        uniformMapping = uniformBufferMemory->map(0, sizeof(Uniform));
    }

    vk::Image createImage(vk::Extent3D extent, vk::Format format, vk::ImageUsageFlags usage) {
        vk::ImageCreateInfo info = {};
        info.imageType = vk::ImageType::_2D;
        info.extent = extent;
        info.mipLevels = 1;
        info.arrayLayers = 1;
        info.format = format;
        info.tiling = vk::ImageTiling::Optimal;
        info.initialLayout = vk::ImageLayout::Undefined;
        info.usage = usage;
        info.samples = vk::SampleCountFlags::_1;

        return vk::Image(*device, info);
    }

    void copy(vk::Image& dst, void* src, vk::Extent3D extent) {
        size_t size = extent.width * extent.height * 4;
        vk::Buffer staging = createBuffer(size, vk::BufferUsageFlags::TransferSrc);
        vk::DeviceMemory stagingMemory = allocate(staging.requirements(), vk::MemoryPropertyFlags::HostVisible | vk::MemoryPropertyFlags::HostCoherent);
        staging.bind(stagingMemory, 0);
        void* ptr = stagingMemory.map(0, stagingMemory.size());

        std::memcpy(ptr, src, size);

        vk::CommandBuffer commandBuffer = getSingleUseCommandBuffer();

        vk::ImageMemoryBarrier barrier = {};
        barrier.srcAccessMask = vk::AccessFlags::None;
        barrier.dstAccessMask = vk::AccessFlags::TransferWrite;
        barrier.oldLayout = vk::ImageLayout::Undefined;
        barrier.newLayout = vk::ImageLayout::TransferDstOptimal;
        barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        barrier.image = texture.get();
        barrier.subresourceRange.aspectMask = vk::ImageAspectFlags::Color;
        barrier.subresourceRange.baseMipLevel = 0;
        barrier.subresourceRange.levelCount = 1;
        barrier.subresourceRange.baseArrayLayer = 0;
        barrier.subresourceRange.layerCount = 1;

        commandBuffer.pipelineBarrier(
            vk::PipelineStageFlags::TopOfPipe, vk::PipelineStageFlags::Transfer, vk::DependencyFlags::None,
            {}, {}, { barrier });

        vk::BufferImageCopy copy = {};
        copy.imageSubresource.aspectMask = vk::ImageAspectFlags::Color;
        copy.imageSubresource.mipLevel = 0;
        copy.imageSubresource.baseArrayLayer = 0;
        copy.imageSubresource.layerCount = 1;
        copy.imageExtent = extent;

        commandBuffer.copyBufferToImage(staging, dst, vk::ImageLayout::TransferDstOptimal, copy);

        barrier.srcAccessMask = vk::AccessFlags::TransferWrite;
        barrier.dstAccessMask = vk::AccessFlags::ShaderRead;
        barrier.oldLayout = vk::ImageLayout::TransferDstOptimal;
        barrier.newLayout = vk::ImageLayout::ShaderReadOnlyOptimal;

        commandBuffer.pipelineBarrier(
            vk::PipelineStageFlags::Transfer, vk::PipelineStageFlags::FragmentShader, vk::DependencyFlags::None,
            {}, {}, { barrier });

        submitSingleUseCommandBuffer(commandBuffer);
    }

    vk::ImageView createImageView(const vk::Image& image, vk::Format format) {
        vk::ImageViewCreateInfo info = {};
        info.image = &image;
        info.viewType = vk::ImageViewType::_2D;
        info.format = format;
        if (format == vk::Format::D32_Sfloat || format == vk::Format::D32_Sfloat_S8_Uint || format == vk::Format::D24_Unorm_S8_Uint) {
            info.subresourceRange.aspectMask = vk::ImageAspectFlags::Depth;
            if (hasStencilComponent(format)) {
                info.subresourceRange.aspectMask |= vk::ImageAspectFlags::Stencil;
            }
        } else {
            info.subresourceRange.aspectMask = vk::ImageAspectFlags::Color;
        }
        info.subresourceRange.baseMipLevel = 0;
        info.subresourceRange.levelCount = 1;
        info.subresourceRange.baseArrayLayer = 0;
        info.subresourceRange.layerCount = 1;

        return vk::ImageView(*device, info);
    }

    void createTexture() {
        int width;
        int height;
        int components;
        stbi_uc* data = stbi_load("texture.jpg", &width, &height, &components, 4);
        vk::Extent3D extent = { static_cast<uint32_t>(width), static_cast<uint32_t>(height), 1 };

        texture = std::make_unique<vk::Image>(
            createImage(extent, vk::Format::R8G8B8A8_Unorm, vk::ImageUsageFlags::Sampled | vk::ImageUsageFlags::TransferDst)
        );

        textureMemory = std::make_unique<vk::DeviceMemory>(
            allocate(texture->requirements(), vk::MemoryPropertyFlags::DeviceLocal)
        );

        texture->bind(*textureMemory, 0);
        copy(*texture, data, extent);

        stbi_image_free(data);
    }

    void createTextureImageView() {
        textureImageView = std::make_unique<vk::ImageView>(createImageView(*texture, vk::Format::R8G8B8A8_Unorm));
    }

    void createSampler() {
        vk::SamplerCreateInfo info = {};
        info.magFilter = vk::Filter::Nearest;
        info.minFilter = vk::Filter::Nearest;
        info.mipmapMode = vk::SamplerMipmapMode::Nearest;
        info.addressModeU = vk::SamplerAddressMode::ClampToEdge;
        info.addressModeV = vk::SamplerAddressMode::ClampToEdge;
        info.addressModeW = vk::SamplerAddressMode::ClampToEdge;
        info.maxAnisotropy = 1.0f;

        sampler = std::make_unique < vk::Sampler>(*device, info);
    }

    void createDescriptorSetLayout() {
        vk::DescriptorSetLayoutBinding binding0 = {};
        binding0.binding = 0;
        binding0.descriptorType = vk::DescriptorType::UniformBuffer;
        binding0.descriptorCount = 1;
        binding0.stageFlags = vk::ShaderStageFlags::Vertex;

        vk::DescriptorSetLayoutBinding binding1 = {};
        binding1.binding = 1;
        binding1.descriptorType = vk::DescriptorType::CombinedImageSampler;
        binding1.descriptorCount = 1;
        binding1.stageFlags = vk::ShaderStageFlags::Fragment;

        vk::DescriptorSetLayoutCreateInfo info = {};
        info.bindings = { binding0, binding1 };

        descriptorSetLayout = std::make_unique<vk::DescriptorSetLayout>(*device, info);
    }

    void createDescriptorPool() {
        vk::DescriptorPoolSize poolSize0 = {};
        poolSize0.type = vk::DescriptorType::UniformBuffer;
        poolSize0.descriptorCount = 1;

        vk::DescriptorPoolSize poolSize1 = {};
        poolSize1.type = vk::DescriptorType::CombinedImageSampler;
        poolSize1.descriptorCount = 1;

        vk::DescriptorPoolCreateInfo info = {};
        info.poolSizes = { poolSize0, poolSize1 };
        info.maxSets = 1;

        descriptorPool = std::make_unique<vk::DescriptorPool>(*device, info);
    }

    void createDescriptorSet() {
        vk::DescriptorSetAllocateInfo info = {};
        info.descriptorPool = descriptorPool.get();
        info.setLayouts = { *descriptorSetLayout };
        
        descriptorSet = std::make_unique<vk::DescriptorSet>(std::move(descriptorPool->allocate(info)[0]));

        vk::DescriptorBufferInfo bufferInfo = {};
        bufferInfo.buffer = uniformBuffer.get();
        bufferInfo.range = sizeof(Uniform);

        vk::WriteDescriptorSet write0 = {};
        write0.dstSet = descriptorSet.get();
        write0.descriptorType = vk::DescriptorType::UniformBuffer;
        write0.dstBinding = 0;
        write0.bufferInfo = { bufferInfo };

        vk::DescriptorImageInfo imageInfo = {};
        imageInfo.imageLayout = vk::ImageLayout::ShaderReadOnlyOptimal;
        imageInfo.imageView = textureImageView.get();
        imageInfo.sampler = sampler.get();

        vk::WriteDescriptorSet write1 = {};
        write1.dstSet = descriptorSet.get();
        write1.descriptorType = vk::DescriptorType::CombinedImageSampler;
        write1.dstBinding = 1;
        write1.imageInfo = { imageInfo };

        vk::DescriptorSet::update(*device, { write0, write1 }, {});
    }

    void createPipelineLayout() {
        vk::PipelineLayoutCreateInfo info = {};
        info.setLayouts = { *descriptorSetLayout };

        pipelineLayout = std::make_unique<vk::PipelineLayout>(*device, info);
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

    void recreateSwapchain() {
        createSwapchain();
        createImageViews();
        createDepthBuffer();
        createRenderPass();
        createFramebuffers();
        createPipeline();
        recordCommands();
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

        vk::SwapchainCreateInfo info = {};
        info.surface = surface.get();
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
        info.oldSwapchain = swapchain.get();

        swapchain = std::make_unique<vk::Swapchain>(*device, info);
    }

    void createImageViews() {
        imageViews.clear();
        imageViews.reserve(swapchain->images().size());
        for (auto& image : swapchain->images()) {

            imageViews.emplace_back(createImageView(image, swapchain->format()));
        }
    }

    vk::Format findDepthFormat() {
        vk::Format formats[] = { vk::Format::D32_Sfloat, vk::Format::D32_Sfloat_S8_Uint, vk::Format::D24_Unorm_S8_Uint };
        for (auto format : formats) {
            auto properties = physicalDevice->getFormatProperties(format);
            if ((properties.optimalTilingFeatures & vk::FormatFeatureFlags::DepthStencilAttachment) == vk::FormatFeatureFlags::DepthStencilAttachment) {
                return format;
            }
        }

        throw std::runtime_error("Failed to find depth buffer format");
    }

    bool hasStencilComponent(vk::Format format) {
        return format == vk::Format::D32_Sfloat_S8_Uint || format == vk::Format::D24_Unorm_S8_Uint;
    }

    void createDepthBuffer() {
        vk::Format format = findDepthFormat();
        vk::Extent3D extent = {};
        extent.width = swapchain->extent().width;
        extent.height = swapchain->extent().height;
        extent.depth = 1;

        depthImage = std::make_unique<vk::Image>(
            createImage(extent, format, vk::ImageUsageFlags::DepthStencilAttachment)
            );

        depthImageMemory = std::make_unique<vk::DeviceMemory>(
            allocate(depthImage->requirements(), vk::MemoryPropertyFlags::DeviceLocal)
            );

        depthImage->bind(*depthImageMemory, 0);

        depthImageView = std::make_unique<vk::ImageView>(
            createImageView(*depthImage, format)
            );

        depthFormat = format;
        initDepthBuffer();
    }

    void initDepthBuffer() {
        auto commandBuffer = getSingleUseCommandBuffer();

        vk::ImageMemoryBarrier barrier = {};
        barrier.image = depthImage.get();
        barrier.oldLayout = vk::ImageLayout::Undefined;
        barrier.newLayout = vk::ImageLayout::DepthStencilAttachmentOptimal;
        barrier.srcAccessMask = vk::AccessFlags::None;
        barrier.dstAccessMask = vk::AccessFlags::DepthStencilAttachmentRead | vk::AccessFlags::DepthStencilAttachmentWrite;
        barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        barrier.subresourceRange.aspectMask = vk::ImageAspectFlags::Depth;
        if (hasStencilComponent(depthFormat)) barrier.subresourceRange.aspectMask |= vk::ImageAspectFlags::Stencil;
        barrier.subresourceRange.baseMipLevel = 0;
        barrier.subresourceRange.levelCount = 1;
        barrier.subresourceRange.baseArrayLayer = 0;
        barrier.subresourceRange.layerCount = 1;

        commandBuffer.pipelineBarrier(
            vk::PipelineStageFlags::TopOfPipe, vk::PipelineStageFlags::EarlyFragmentTests, vk::DependencyFlags::None,
            {}, {}, { barrier });

        submitSingleUseCommandBuffer(commandBuffer);
    }

    void createRenderPass() {
        vk::AttachmentDescription colorAttachment = {};
        colorAttachment.format = swapchain->format();
        colorAttachment.samples = vk::SampleCountFlags::_1;
        colorAttachment.loadOp = vk::AttachmentLoadOp::Clear;
        colorAttachment.storeOp = vk::AttachmentStoreOp::Store;
        colorAttachment.initialLayout = vk::ImageLayout::Undefined;
        colorAttachment.finalLayout = vk::ImageLayout::PresentSrcKhr;

        vk::AttachmentDescription depthAttachment = {};
        depthAttachment.format = depthFormat;
        depthAttachment.samples = vk::SampleCountFlags::_1;
        depthAttachment.loadOp = vk::AttachmentLoadOp::Clear;
        depthAttachment.storeOp = vk::AttachmentStoreOp::Store;
        depthAttachment.stencilLoadOp = vk::AttachmentLoadOp::DontCare;
        depthAttachment.stencilStoreOp = vk::AttachmentStoreOp::DontCare;
        depthAttachment.initialLayout = vk::ImageLayout::DepthStencilAttachmentOptimal;
        depthAttachment.finalLayout = vk::ImageLayout::DepthStencilAttachmentOptimal;

        vk::AttachmentReference colorAttachmentRef = {};
        colorAttachmentRef.attachment = 0;
        colorAttachmentRef.layout = vk::ImageLayout::ColorAttachmentOptimal;

        vk::AttachmentReference depthAttachmentRef = {};
        depthAttachmentRef.attachment = 1;
        depthAttachmentRef.layout = vk::ImageLayout::DepthStencilAttachmentOptimal;

        vk::SubpassDescription subpass = {};
        subpass.pipelineBindPoint = vk::PipelineBindPoint::Graphics;
        subpass.colorAttachments = { colorAttachmentRef };
        subpass.depthStencilAttachments = { depthAttachmentRef };

        vk::RenderPassCreateInfo info = {};
        info.attachments = { colorAttachment, depthAttachment };
        info.subpasses = { subpass };

        renderPass = std::make_unique<vk::RenderPass>(*device, info);
    }

    void createFramebuffers() {
        framebuffers.clear();
        framebuffers.reserve(swapchain->images().size());
        for (size_t i = 0; i < swapchain->images().size(); i++) {
            vk::FramebufferCreateInfo info = {};
            info.renderPass = renderPass.get();
            info.attachments = { imageViews[i], *depthImageView };
            info.width = swapchain->extent().width;
            info.height = swapchain->extent().height;
            info.layers = 1;

            framebuffers.emplace_back(*device, info);
        }
    }

    std::vector<char> readFile(const std::string& fileName) {
        std::ifstream file(fileName, std::ios::binary | std::ios::ate);
        if (!file) throw std::runtime_error("Failed to open file");

        std::vector<char> result(file.tellg());
        file.seekg(0, std::ios::beg);
        file.read(result.data(), result.size());

        return result;
    }

    vk::ShaderModule createShader(const std::string& fileName) {
        vk::ShaderModuleCreateInfo info = {};
        info.code = readFile(fileName);

        return vk::ShaderModule(*device, info);
    }

    void createPipeline() {
        vk::ShaderModule vertShader = createShader("shader.vert.spv");
        vk::ShaderModule fragShader = createShader("shader.frag.spv");

        vk::PipelineShaderStageCreateInfo vertStage = {};
        vertStage.stage = vk::ShaderStageFlags::Vertex;
        vertStage.module = &vertShader;
        vertStage.name = "main";

        vk::PipelineShaderStageCreateInfo fragStage = {};
        fragStage.stage = vk::ShaderStageFlags::Fragment;
        fragStage.module = &fragShader;
        fragStage.name = "main";

        vk::PipelineVertexInputStateCreateInfo vertexInputInfo = {};
        vertexInputInfo.vertexBindingDescriptions = Vertex::getBindingDescription();
        vertexInputInfo.vertexAttributeDescriptions = Vertex::getAttributeDescriptions();

        vk::PipelineInputAssemblyStateCreateInfo inputAssembly = {};
        inputAssembly.topology = vk::PrimitiveTopology::TriangleList;

        vk::Viewport viewport = {};
        viewport.width = static_cast<float>(swapchain->extent().width);
        viewport.height = static_cast<float>(swapchain->extent().height);
        viewport.minDepth = 0.0f;
        viewport.maxDepth = 1.0f;

        vk::Rect2D scissor = { {}, swapchain->extent() };

        vk::PipelineViewportStateCreateInfo viewportState = {};
        viewportState.viewports = { viewport };
        viewportState.scissors = { scissor };

        vk::PipelineRasterizationStateCreateInfo rasterizer = {};
        rasterizer.polygonMode = vk::PolygonMode::Fill;
        rasterizer.lineWidth = 1.0f;
        rasterizer.cullMode = vk::CullModeFlags::Back;
        rasterizer.frontFace = vk::FrontFace::CounterClockwise;

        vk::PipelineMultisampleStateCreateInfo multisampling = {};
        multisampling.rasterizationSamples = vk::SampleCountFlags::_1;

        vk::PipelineColorBlendAttachmentState colorBlendAttachment = {};
        colorBlendAttachment.colorWriteMask = vk::ColorComponentFlags::R
                                            | vk::ColorComponentFlags::G
                                            | vk::ColorComponentFlags::B
                                            | vk::ColorComponentFlags::A;

        vk::PipelineColorBlendStateCreateInfo colorBlending = {};
        colorBlending.attachments = { colorBlendAttachment };

        vk::PipelineDepthStencilStateCreateInfo depth = {};
        depth.depthTestEnable = true;
        depth.depthWriteEnable = true;
        depth.depthCompareOp = vk::CompareOp::Less;

        vk::GraphicsPipelineCreateInfo info = {};
        info.stages = { vertStage, fragStage };
        info.vertexInputState = &vertexInputInfo;
        info.inputAssemblyState = &inputAssembly;
        info.viewportState = &viewportState;
        info.rasterizationState = &rasterizer;
        info.multisampleState = &multisampling;
        info.colorBlendState = &colorBlending;
        info.depthStencilState = &depth;
        info.layout = pipelineLayout.get();
        info.renderPass = renderPass.get();
        info.subpass = 0;

        pipeline = std::make_unique<vk::GraphicsPipeline>(*device, info);
    }

    void createCommandPool() {
        vk::CommandPoolCreateInfo info = {};
        info.queueFamilyIndex = graphicsQueueIndex;

        commandPool = std::make_unique<vk::CommandPool>(*device, info);
    }

    void recordCommands() {
        vk::CommandBufferAllocateInfo allocInfo = {};
        allocInfo.commandPool = commandPool.get();
        allocInfo.commandBufferCount = swapchain->images().size();
        allocInfo.level = vk::CommandBufferLevel::Primary;

        commandBuffers = commandPool->allocate(allocInfo);
        for (size_t i = 0; i < commandBuffers.size(); i++) {
            recordCommands(commandBuffers[i], i);
            commandBuffers[i].setDestructorEnabled(true);
        }
    }

    void recordCommands(const vk::CommandBuffer& commandBuffer, size_t index) {
        vk::CommandBufferBeginInfo beginInfo = {};
        commandBuffer.begin(beginInfo);

        vk::RenderPassBeginInfo info = {};
        info.renderPass = renderPass.get();
        info.framebuffer = &framebuffers[index];
        info.renderArea = { {}, swapchain->extent() };
        info.clearValues = { {}, {} };
        info.clearValues[1].depthStencil = { 1.0f, 0 };

        commandBuffer.beginRenderPass(info, vk::SubpassContents::Inline);
        
        commandBuffer.bindVertexBuffers(0, { *vertexBuffer }, 0ull);
        commandBuffer.bindIndexBuffer(*indexBuffer, 0, vk::IndexType::Uint32);
        commandBuffer.bindPipeline(vk::PipelineBindPoint::Graphics, *pipeline);
        commandBuffer.bindDescriptorSets(vk::PipelineBindPoint::Graphics, *pipelineLayout, 0, { *descriptorSet }, {});
        commandBuffer.drawIndexed(static_cast<uint32_t>(indices.size()), 1, 0, 0, 0);

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

    void updateUniform(float time) {
        Uniform& uniform = *reinterpret_cast<Uniform*>(uniformMapping);
        glm::mat4 proj = glm::perspective(glm::radians(45.0f), static_cast<float>(swapchain->extent().width) / static_cast<float>(swapchain->extent().height), 0.1f, 10.0f);
        proj[1][1] *= -1;
        glm::mat4 view = glm::lookAt(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        uniform.projView = proj * view;
        uniform.model = glm::rotate(glm::mat4(1.0f), time * glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    }

    void mainLoop() {
        auto startTime = std::chrono::high_resolution_clock::now();
        auto last = startTime;
        size_t frames = 0;

        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();

            if (resizeFlag) {
                device->waitIdle();
                recreateSwapchain();
                resizeFlag = false;
            }

            auto now = std::chrono::high_resolution_clock::now();
            float elapsed = std::chrono::duration<float, std::chrono::seconds::period>(now - last).count();
            float totalElapsed = std::chrono::duration<float, std::chrono::seconds::period>(now - startTime).count();
            updateUniform(totalElapsed);

            uint32_t index = swapchain->acquireNextImage(~0ull, imageAcquireSemaphore.get(), nullptr);

            vk::SubmitInfo submitInfo = {};
            submitInfo.commandBuffers = { commandBuffers[index] };
            submitInfo.waitSemaphores = { *imageAcquireSemaphore };
            submitInfo.waitDstStageMask = { vk::PipelineStageFlags::TopOfPipe };
            submitInfo.signalSemaphores = { *renderSemaphore };

            fences[index].wait();
            fences[index].reset();
            graphicsQueue->submit(submitInfo, &fences[index]);

            vk::PresentInfo presentInfo = {};
            presentInfo.swapchains = { *swapchain };
            presentInfo.imageIndices = { index };
            presentInfo.waitSemaphores = { *renderSemaphore };

            presentQueue->present(presentInfo);

            frames++;
            if (elapsed > 0.25f) {
                std::stringstream title;
                title.precision(0);
                title.setf(std::ios::fixed, std::ios::floatfield);
                title << "Hello Triangle (" << (frames / elapsed) << " fps)";
                glfwSetWindowTitle(window, title.str().c_str());
                last = now;
                frames = 0;
            }
        }
    }
};

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Triangle", nullptr, nullptr);
    glfwSetWindowSizeLimits(window, 1, 1, GLFW_DONT_CARE, GLFW_DONT_CARE);

    HelloTriangle app(window, 800, 600);
    app.run();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}