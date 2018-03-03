#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/LayerProperties.h"
#include "VulkanWrapper/ExtensionProperties.h"
#include "VulkanWrapper/PhysicalDevice.h"

namespace vk {
    class ApplicationInfo : public CreateInfo_<VkApplicationInfo> {
    public:
        std::string applicationName;
        uint32_t applicationVersion;
        std::string engineName;
        uint32_t engineVersion;
        uint32_t apiVersion;

        void Write(VkApplicationInfo& info) const;
    };

    class InstanceCreateInfo : public CreateInfo_<VkInstanceCreateInfo> {
    public:
        void Write(void* ptr) const;

        vk::InstanceCreateFlags flags = vk::InstanceCreateFlags::None;
        const vk::ApplicationInfo* applicationInfo = nullptr;
        std::vector<std::string> enabledLayerNames;
        std::vector<std::string> enabledExtensionNames;

    private:
        //holds temporary variables for the life of the InstanceCreateInfo
        mutable std::vector<char> pApplicationInfo;	//holds VkApplicationInfo and structure chain
        mutable std::vector<const char*> ppEnabledLayerNames;
        mutable std::vector<const char*> ppEnabledExtensionNames;
    };

    class Instance {
    public:
        Instance(const InstanceCreateInfo& info, const VkAllocationCallbacks* callbacks = nullptr);
        ~Instance();

        const VkAllocationCallbacks* GetCallbacks() const { return callbacksPtr; }
        const std::vector<PhysicalDevice>& GetPhysicalDevices() const { return physicalDevices; }

        static std::vector<LayerProperties> GetAvailableLayers();
        static std::vector<ExtensionProperties> GetAvailableExtensions(const char* layerName);
    private:
        void EnumeratePhysicalDevices();

        VkInstance instance;
        VkAllocationCallbacks callbacks;
        VkAllocationCallbacks* callbacksPtr = nullptr;
        std::vector<PhysicalDevice> physicalDevices;
    };
}