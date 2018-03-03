#include "VulkanWrapper/PhysicalDevice.h"
#include <cstring>

vk::PhysicalDevice::PhysicalDevice(VkPhysicalDevice physicalDevice) {
    this->physicalDevice = physicalDevice;

    VkPhysicalDeviceProperties properties;
    vkGetPhysicalDeviceProperties(physicalDevice, &properties);

    this->properties.apiVersion = properties.apiVersion;
    this->properties.driverVersion = properties.driverVersion;
    this->properties.vendorID = properties.vendorID;
    this->properties.deviceID = properties.deviceID;
    this->properties.deviceType = static_cast<PhysicalDeviceType>(properties.deviceType);
    this->properties.deviceName = properties.deviceName;
    std::memcpy(&this->properties.pipelineCacheUUID[VK_UUID_SIZE], properties.pipelineCacheUUID, VK_UUID_SIZE);
    std::memcpy(&this->properties.limits, &properties.limits, sizeof(PhysicalDeviceLimits));
    std::memcpy(&this->properties.sparseProperties, &properties.sparseProperties, sizeof(PhysicalDeviceSparseProperties));

    vkGetPhysicalDeviceFeatures(physicalDevice, &features);
}