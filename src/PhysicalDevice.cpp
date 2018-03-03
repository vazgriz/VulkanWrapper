#include "VulkanWrapper/PhysicalDevice.h"
#include <cstring>

vk::PhysicalDevice::PhysicalDevice(VkPhysicalDevice physicalDevice) {
    m_physicalDevice = physicalDevice;

    getProperties();
    getFeatures();
}

void vk::PhysicalDevice::getProperties() {
    VkPhysicalDeviceProperties properties;
    vkGetPhysicalDeviceProperties(m_physicalDevice, &properties);

    m_properties.apiVersion = properties.apiVersion;
    m_properties.driverVersion = properties.driverVersion;
    m_properties.vendorID = properties.vendorID;
    m_properties.deviceID = properties.deviceID;
    m_properties.deviceType = static_cast<PhysicalDeviceType>(properties.deviceType);
    m_properties.deviceName = properties.deviceName;
    std::memcpy(&m_properties.pipelineCacheUUID[VK_UUID_SIZE], properties.pipelineCacheUUID, VK_UUID_SIZE);
    m_properties.limits = properties.limits;
    m_properties.sparseProperties = properties.sparseProperties;
}

void vk::PhysicalDevice::getFeatures() {
    vkGetPhysicalDeviceFeatures(m_physicalDevice, &m_features);
}