#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    typedef VkPhysicalDeviceLimits PhysicalDeviceLimits;
    typedef VkPhysicalDeviceSparseProperties PhysicalDeviceSparseProperties;
    typedef VkPhysicalDeviceFeatures PhysicalDeviceFeatures;

    struct PhysicalDeviceProperties {
        uint32_t apiVersion;
        uint32_t driverVersion;
        uint32_t vendorID;
        uint32_t deviceID;
        PhysicalDeviceType deviceType;
        std::string deviceName;
        uint8_t pipelineCacheUUID[VK_UUID_SIZE];
        PhysicalDeviceLimits limits;
        PhysicalDeviceSparseProperties sparseProperties;

        PhysicalDeviceProperties() { }
        PhysicalDeviceProperties(VkPhysicalDeviceProperties properties);
    };

    struct QueueFamilyProperties {
        QueueFlags queueFlags;
        uint32_t queueCount;
        uint32_t timestampValidBits;
        VkExtent3D minImageTransferGranularity;

        QueueFamilyProperties(VkQueueFamilyProperties);
    };

    class PhysicalDevice {
    public:
        PhysicalDevice(VkPhysicalDevice physicalDevice);

        const PhysicalDeviceProperties& properties() const { return m_properties; }
        const PhysicalDeviceFeatures& features() const { return m_features; }
        const std::vector<QueueFamilyProperties> queueFamilies() const {return m_families; }

    private:
        void getProperties();
        void getFeatures();
        void getQueueFamilies();

        VkPhysicalDevice m_physicalDevice;
        PhysicalDeviceProperties m_properties;
        PhysicalDeviceFeatures m_features;
        std::vector<QueueFamilyProperties> m_families;
    };
}