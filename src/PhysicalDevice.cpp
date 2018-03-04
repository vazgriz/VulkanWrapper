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

vk::QueueFamilyProperties::QueueFamilyProperties(VkQueueFamilyProperties properties, uint32_t i) {
    queueFlags = static_cast<vk::QueueFlags>(properties.queueFlags);
    queueCount = properties.queueCount;
    timestampValidBits = properties.timestampValidBits;
    minImageTransferGranularity = properties.minImageTransferGranularity;
    familyIndex = i;
}

vk::PhysicalDevice::PhysicalDevice(VkPhysicalDevice physicalDevice) {
    m_physicalDevice = physicalDevice;

    getProperties();
    getFeatures();
    getQueueFamilies();
    getLayers();
    getExtensions();
}

void vk::PhysicalDevice::getProperties() {
    VkPhysicalDeviceProperties properties;
    vkGetPhysicalDeviceProperties(m_physicalDevice, &properties);

    m_properties = PhysicalDeviceProperties(properties);
}

void vk::PhysicalDevice::getFeatures() {
    vkGetPhysicalDeviceFeatures(m_physicalDevice, &m_features);
}

void vk::PhysicalDevice::getQueueFamilies() {
    uint32_t count;
    vkGetPhysicalDeviceQueueFamilyProperties(m_physicalDevice, &count, nullptr);
    std::vector<VkQueueFamilyProperties> properties(count);
    vkGetPhysicalDeviceQueueFamilyProperties(m_physicalDevice, &count, properties.data());

    m_families.reserve(count);
    for (uint32_t i = 0; i < count; i++) {
        m_families.push_back(QueueFamilyProperties(properties[i], i));
    }
}

void vk::PhysicalDevice::getLayers() {
    uint32_t count;
    vkEnumerateDeviceLayerProperties(m_physicalDevice, &count, nullptr);
    std::vector<VkLayerProperties> properties(count);
    vkEnumerateDeviceLayerProperties(m_physicalDevice, &count, properties.data());

    m_layers.reserve(count);
    for (auto& prop : properties) {
        m_layers.emplace_back(prop);
    }
}

void vk::PhysicalDevice::getExtensions(const std::string& layerName) {
    const char* pLayerName = nullptr;
    if (layerName.size() > 0) pLayerName = layerName.c_str();

    uint32_t count;
    vkEnumerateDeviceExtensionProperties(m_physicalDevice, pLayerName, &count, nullptr);
    std::vector<VkExtensionProperties> properties(count);
    vkEnumerateDeviceExtensionProperties(m_physicalDevice, pLayerName, &count, properties.data());

    std::vector<ExtensionProperties> result;
    result.reserve(count);
    for (auto& prop : properties) {
        result.emplace_back(prop);
    }

    m_extensionMap.emplace(layerName, std::move(result));
}

void vk::PhysicalDevice::getExtensions() {
    std::vector<std::string> layerNames = { "" };   //start with empty string

    for (auto& layer : m_layers) {
        layerNames.push_back(layer.layerName);
    }

    for (auto& layerName : layerNames) {
        getExtensions(layerName);
    }
}