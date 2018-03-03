#include "VulkanWrapper/PhysicalDevice.h"
#include <cstring>

vk::PhysicalDeviceProperties::PhysicalDeviceProperties(VkPhysicalDeviceProperties properties) {
    apiVersion = properties.apiVersion;
    driverVersion = properties.driverVersion;
    vendorID = properties.vendorID;
    deviceID = properties.deviceID;
    deviceType = static_cast<PhysicalDeviceType>(properties.deviceType);
    deviceName = properties.deviceName;
    std::memcpy(&pipelineCacheUUID[VK_UUID_SIZE], properties.pipelineCacheUUID, VK_UUID_SIZE);
    limits = properties.limits;
    sparseProperties = properties.sparseProperties;
}

vk::QueueFamilyProperties::QueueFamilyProperties(VkQueueFamilyProperties properties) {
    queueFlags = static_cast<vk::QueueFlags>(properties.queueFlags);
    queueCount = properties.queueCount;
    timestampValidBits = properties.timestampValidBits;
    minImageTransferGranularity = properties.minImageTransferGranularity;
}

vk::PhysicalDevice::PhysicalDevice(VkPhysicalDevice physicalDevice) {
    m_physicalDevice = physicalDevice;

    getProperties();
    getFeatures();
}

void vk::PhysicalDevice::getProperties() {
    VkPhysicalDeviceProperties properties;
    vkGetPhysicalDeviceProperties(m_physicalDevice, &properties);

    m_properties = PhysicalDeviceProperties(properties);
}

void vk::PhysicalDevice::getFeatures() {
    vkGetPhysicalDeviceFeatures(m_physicalDevice, &m_features);
}