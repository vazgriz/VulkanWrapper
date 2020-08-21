#include "VulkanWrapper/PhysicalDevice.h"

using namespace vk;

void PhysicalDeviceFeatures2::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
    features11.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
    features12.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;

    m_info.pNext = &features11;
    features11.pNext = &features12;
    features12.pNext = nullptr;

    memcpy(&m_info.features, &features, sizeof(VkPhysicalDeviceFeatures));
}

void PhysicalDeviceFeatures2::unmarshal()  {
    memcpy(&features, &m_info.features, sizeof(VkPhysicalDeviceFeatures));
}

MemoryType::MemoryType(VkMemoryType type) {
    propertyFlags = static_cast<MemoryPropertyFlags>(type.propertyFlags);
    heapIndex = type.heapIndex;
}

MemoryHeap::MemoryHeap(VkMemoryHeap heap) {
    size = heap.size;
    flags = static_cast<MemoryHeapFlags>(heap.flags);
}

PhysicalDeviceProperties::PhysicalDeviceProperties(VkPhysicalDeviceProperties properties) {
    apiVersion = properties.apiVersion;
    driverVersion = properties.driverVersion;
    vendorID = properties.vendorID;
    deviceID = properties.deviceID;
    deviceType = static_cast<PhysicalDeviceType>(properties.deviceType);
    deviceName = properties.deviceName;
    std::memcpy(&pipelineCacheUUID[0], properties.pipelineCacheUUID, VK_UUID_SIZE);
    limits = properties.limits;
    sparseProperties = properties.sparseProperties;
}

QueueFamilyProperties::QueueFamilyProperties(VkQueueFamilyProperties properties) {
    queueFlags = static_cast<QueueFlags>(properties.queueFlags);
    queueCount = properties.queueCount;
    timestampValidBits = properties.timestampValidBits;
    minImageTransferGranularity = properties.minImageTransferGranularity;
}

PhysicalDevice::PhysicalDevice(Instance& instance, VkPhysicalDevice physicalDevice) {
    m_physicalDevice = physicalDevice;
    m_instanceRef = &instance;

    getProperties();
    getFeatures();
    getQueueFamilies();
    getLayers();
    getExtensions();
    getMemoryProperties();
}

void PhysicalDevice::getProperties() {
    VkPhysicalDeviceProperties properties;
    vkGetPhysicalDeviceProperties(m_physicalDevice, &properties);

    m_properties = PhysicalDeviceProperties(properties);
}

void PhysicalDevice::getFeatures() {
    m_features.marshal();
    vkGetPhysicalDeviceFeatures2(m_physicalDevice, m_features.getMutableInfo());
    m_features.unmarshal();
}

void PhysicalDevice::getQueueFamilies() {
    uint32_t count;
    vkGetPhysicalDeviceQueueFamilyProperties(m_physicalDevice, &count, nullptr);
    std::vector<VkQueueFamilyProperties> properties(count);
    vkGetPhysicalDeviceQueueFamilyProperties(m_physicalDevice, &count, properties.data());

    m_families.reserve(count);
    for (uint32_t i = 0; i < count; i++) {
        m_families.emplace_back(properties[i]);
    }
}

void PhysicalDevice::getLayers() {
    uint32_t count;
    vkEnumerateDeviceLayerProperties(m_physicalDevice, &count, nullptr);
    std::vector<VkLayerProperties> properties(count);
    vkEnumerateDeviceLayerProperties(m_physicalDevice, &count, properties.data());

    m_layers.reserve(count);
    for (auto& prop : properties) {
        m_layers.emplace_back(prop);
    }
}

void PhysicalDevice::getExtensions(const std::string& layerName) {
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

void PhysicalDevice::getExtensions() {
    std::vector<std::string> layerNames = { "" };   //start with empty string

    for (auto& layer : m_layers) {
        layerNames.push_back(layer.layerName);
    }

    for (auto& layerName : layerNames) {
        getExtensions(layerName);
    }
}

void PhysicalDevice::getMemoryProperties() {
    VkPhysicalDeviceMemoryProperties properties;
    vkGetPhysicalDeviceMemoryProperties(m_physicalDevice, &properties);

    m_memoryProperties.memoryTypes.reserve(properties.memoryTypeCount);
    for (uint32_t i = 0; i < properties.memoryTypeCount; i++) {
        m_memoryProperties.memoryTypes.push_back(properties.memoryTypes[i]);
    }

    m_memoryProperties.memoryHeaps.reserve(properties.memoryHeapCount);
    for (uint32_t i = 0; i < properties.memoryHeapCount; i++) {
        m_memoryProperties.memoryHeaps.push_back(properties.memoryHeaps[i]);
    }
}

FormatProperties PhysicalDevice::getFormatProperties(Format format) const {
    FormatProperties result;
    vkGetPhysicalDeviceFormatProperties(m_physicalDevice, static_cast<VkFormat>(format), reinterpret_cast<VkFormatProperties*>(&result));
    return result;
}

ImageFormatProperties PhysicalDevice::getImageFormatProperties(
    Format format,
    ImageType type,
    ImageTiling tiling,
    ImageUsageFlags usage,
    ImageCreateFlags flags) const
{
    ImageFormatProperties result;
    vkGetPhysicalDeviceImageFormatProperties(m_physicalDevice,
        static_cast<VkFormat>(format),
        static_cast<VkImageType>(type),
        static_cast<VkImageTiling>(tiling),
        static_cast<VkImageUsageFlags>(usage),
        static_cast<VkImageCreateFlags>(flags),
        reinterpret_cast<VkImageFormatProperties*>(&result)
    );

    return result;
}