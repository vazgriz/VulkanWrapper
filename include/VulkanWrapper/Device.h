#pragma once
#include <vulkan/vulkan.h>
#include <unordered_map>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Instance;
    class PhysicalDevice;
    class Queue;

    class DeviceQueueCreateInfo : public Info<VkDeviceQueueCreateInfo> {
    public:
        VkDeviceQueueCreateFlags flags;
        uint32_t queueFamilyIndex;
        uint32_t queueCount;
        std::vector<float> queuePriorities;

        void marshal() const;
    };

    class DeviceCreateInfo : public Info<VkDeviceCreateInfo> {
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
        Device(const Device& other) = delete;
        Device& operator = (const Device& other) = delete;
        Device(Device&& other);
        ~Device();

        const VkDevice& handle() const { return m_device; }
        Instance& instance() const { return m_instance; }
        const PhysicalDevice& physicalDevice() { return m_physicalDevice; }

        const std::vector<std::string>& layers() const;
        const std::vector<std::string>& extensions() const { return m_extensions; }

        const Queue& getQueue(uint32_t familyIndex, uint32_t queueIndex) const;

        void waitIdle() const;

    private:
        void getQueues(const DeviceCreateInfo& info);

        VkDevice m_device;
        Instance& m_instance;
        const PhysicalDevice& m_physicalDevice;
        std::vector<std::string> m_extensions;
        std::unordered_map<uint32_t, std::vector<Queue>> m_queueMap;
    };
}