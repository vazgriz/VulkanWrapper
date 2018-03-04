#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/Instance.h"
#include "VulkanWrapper/PhysicalDevice.h"

namespace vk {
    class DeviceQueueCreateInfo : public CreateInfo<VkDeviceQueueCreateInfo> {
    public:
        VkDeviceQueueCreateFlags flags;
        uint32_t queueFamilyIndex;
        uint32_t queueCount;
        std::vector<float> queuePriorities;

        void marshal() const;
    };

    class DeviceCreateInfo : public CreateInfo<VkDeviceCreateInfo> {
    public:
        DeviceCreateFlags flags;
        std::vector<DeviceQueueCreateInfo> queueCreateInfos;
        std::vector<std::string> enabledLayerNames;
        std::vector<std::string> enabledExtensionNames;
        const PhysicalDeviceFeatures* enabledFeatures;

        void marshal() const;

    private:
        mutable std::vector<VkDeviceQueueCreateInfo> m_queueInfos;
        mutable std::vector<const char*> m_layers;
        mutable std::vector<const char*> m_extensions;
    };

    class Device {
    public:
        Device(const PhysicalDevice& physicalDevice, const DeviceCreateInfo& info);
        ~Device();

        const VkDevice& handle() const { return m_device; }
        const Instance& instance() const { return m_instance; }
        const std::vector<std::string>& layers() const { return m_instance.layers(); }
        const std::vector<std::string>& extensions() const { return m_extensions; }

    private:
        VkDevice m_device;
        const Instance& m_instance;
        std::vector<std::string> m_extensions;
    };
}