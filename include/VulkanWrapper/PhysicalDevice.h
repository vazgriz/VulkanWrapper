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
    };

    class PhysicalDevice {
    public:
        PhysicalDevice(VkPhysicalDevice physicalDevice);

        const PhysicalDeviceProperties& properties() const { return m_properties; }
        const PhysicalDeviceFeatures& features() const { return m_features; }

    private:
        void getProperties();
        void getFeatures();

        VkPhysicalDevice m_physicalDevice;
        PhysicalDeviceProperties m_properties;
        PhysicalDeviceFeatures m_features;
    };
}