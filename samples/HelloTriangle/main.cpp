#include <iostream>
#include <string>
#include <memory>
#include <set>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <VulkanWrapper/Instance.h>
#include <VulkanWrapper/PhysicalDevice.h>
#include <VulkanWrapper/Device.h>
#include <VulkanWrapper/Surface.h>
#include <VulkanWrapper/Queue.h>

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

    HelloTriangle(GLFWwindow* window, int width, int height) {
        this->window = window;
    }

    void run() {
        createInstance();
        createSurface();
        pickPhysicalDevice();
        createDevice();
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

        return requestedExtensions.empty();
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

        device = std::make_unique<vk::Device>(*physicalDevice, info);

        graphicsQueue = &device->getQueue(graphicsQueueIndex, 0);
        presentQueue = &device->getQueue(presentQueueIndex, 0);
    }

    void mainLoop() {
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
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