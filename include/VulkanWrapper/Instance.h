#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/LayerProperties.h"
#include "VulkanWrapper/ExtensionProperties.h"
#include "VulkanWrapper/PhysicalDevice.h"

namespace vk {
    class ApplicationInfo : public InfoMixin<ApplicationInfo, VkApplicationInfo> {
    public:
        std::string applicationName;
        uint32_t applicationVersion;
        std::string engineName;
        uint32_t engineVersion;
        uint32_t apiVersion;

        void marshal() const;
    };

    class InstanceCreateInfo : public InfoMixin<InstanceCreateInfo, VkInstanceCreateInfo> {
    public:
        void marshal() const;

        vk::InstanceCreateFlags flags;
        const vk::ApplicationInfo* applicationInfo = nullptr;
        std::vector<std::string> enabledLayerNames;
        std::vector<std::string> enabledExtensionNames;

    private:
        //holds temporary variables for the life of the InstanceCreateInfo
        mutable std::vector<const char*> m_layers;
        mutable std::vector<const char*> m_extensions;
    };

    class Instance {
    public:
        Instance(const InstanceCreateInfo& info, const VkAllocationCallbacks* callbacks = nullptr);
        Instance(const Instance& other) = delete;
        Instance& operator = (const Instance& other) = delete;
        Instance(Instance&& other);
        Instance& operator = (Instance&& other);
        ~Instance();

        VkInstance handle() const { return m_instance; }

        const VkAllocationCallbacks* callbacks() const { return m_callbacksPtr; }
        const std::vector<PhysicalDevice>& physicalDevices() const { return m_physicalDevices; }
        const std::vector<std::string>& layers() const { return m_info.enabledLayerNames; }
        const std::vector<std::string>& extensions() const { return m_info.enabledExtensionNames; }

        static std::vector<LayerProperties> availableLayers();
        static std::vector<ExtensionProperties> availableExtensions(const std::string& layerName = "");
    private:
        void EnumeratePhysicalDevices();

        VkInstance m_instance;
        VkAllocationCallbacks m_callbacks;
        VkAllocationCallbacks* m_callbacksPtr = nullptr;
        std::vector<PhysicalDevice> m_physicalDevices;

        InstanceCreateInfo m_info;
    };
}