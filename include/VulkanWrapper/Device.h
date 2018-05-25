#pragma once
#include <vulkan/vulkan.h>
#include <unordered_map>
#include <memory>
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
        DeviceQueueCreateFlags flags;
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
        Instance& instance() const { return *m_instanceRef; }
        const PhysicalDevice& physicalDevice() { return *m_physicalDeviceRef; }

        DeviceCreateFlags flags() const { return m_info.flags; }
        const std::vector<DeviceQueueCreateInfo> queueCreateInfos() const { return m_info.queueCreateInfos; }
        const std::vector<std::string>& layers() const;	//Devices layers are deprecated. Returns instance layers
        const std::vector<std::string>& extensions() const { return m_info.enabledExtensionNames; }
        const PhysicalDeviceFeatures& features() { return m_features; }

        const Queue& getQueue(uint32_t familyIndex, uint32_t queueIndex) const;

        void waitIdle() const;

    private:
        void getQueues(const DeviceCreateInfo& info);

        VkDevice m_device;
        VkInstance m_instance;
        Instance* m_instanceRef;
        VkPhysicalDevice m_physicalDevice;
        const PhysicalDevice* m_physicalDeviceRef;
        DeviceCreateInfo m_info;

        std::unordered_map<uint32_t, std::vector<Queue>> m_queueMap;
        PhysicalDeviceFeatures m_features;
    };
}