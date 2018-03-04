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

        void write(void* ptr) const;
    };

    class InstanceCreateInfo : public CreateInfo_<VkInstanceCreateInfo> {
    public:
        void write(void* ptr) const;

        vk::InstanceCreateFlags flags = vk::InstanceCreateFlags::None;
        const vk::ApplicationInfo* applicationInfo = nullptr;
        std::vector<std::string> enabledLayerNames;
        std::vector<std::string> enabledExtensionNames;

    private:
        //holds temporary variables for the life of the InstanceCreateInfo
        mutable std::vector<char> m_applicationInfo;	//holds VkApplicationInfo and structure chain
        mutable std::vector<const char*> m_enabledLayerNames;
        mutable std::vector<const char*> m_enabledExtensionNames;
    };

    class Instance {
    public:
        Instance(const InstanceCreateInfo& info, const VkAllocationCallbacks* callbacks = nullptr);
        ~Instance();

        const VkAllocationCallbacks* callbacks() const { return m_callbacksPtr; }
        const std::vector<PhysicalDevice>& physicalDevices() const { return m_physicalDevices; }

        static std::vector<LayerProperties> availableLayers();
        static std::vector<ExtensionProperties> availableExtensions(const char* layerName);
    private:
        void EnumeratePhysicalDevices();

        VkInstance m_instance;
        VkAllocationCallbacks m_callbacks;
        VkAllocationCallbacks* m_callbacksPtr = nullptr;
        std::vector<PhysicalDevice> m_physicalDevices;
    };
}