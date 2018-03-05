#pragma once
#include <unordered_map>
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/LayerProperties.h"
#include "VulkanWrapper/ExtensionProperties.h"
#include "VulkanWrapper/Surface.h"

namespace vk {
    class Instance;
    typedef VkPhysicalDeviceLimits PhysicalDeviceLimits;
    typedef VkPhysicalDeviceSparseProperties PhysicalDeviceSparseProperties;
    typedef VkPhysicalDeviceFeatures PhysicalDeviceFeatures;
    typedef VkMemoryType MemoryType;
    typedef VkMemoryHeap MemoryHeap;

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
        uint32_t familyIndex;

        QueueFamilyProperties(VkQueueFamilyProperties properties, uint32_t index);
    };

    struct MemoryProperties {
        std::vector<MemoryType> memoryTypes;
        std::vector<MemoryHeap> memoryHeaps;
    };

    class PhysicalDevice {
    public:
        PhysicalDevice(const Instance& instance, VkPhysicalDevice physicalDevice);

        const Instance& instance() const { return m_instance; }
        VkPhysicalDevice handle() const { return m_physicalDevice; }

        const PhysicalDeviceProperties& properties() const { return m_properties; }
        const PhysicalDeviceFeatures& features() const { return m_features; }
        const std::vector<QueueFamilyProperties>& queueFamilies() const { return m_families; }
        const std::vector<LayerProperties>& availableLayers() const { return m_layers; }
        const std::vector<ExtensionProperties>& availableExtensions(const std::string& layerName = "") const { return m_extensionMap.at(layerName); }
        const MemoryProperties& memoryProperties() const { return m_memoryProperties; }

        bool supports(const Surface& surface, uint32_t queueFamilyIndex) const;

    private:
        void getProperties();
        void getFeatures();
        void getQueueFamilies();
        void getLayers();
        void getExtensions(const std::string& layerName);
        void getExtensions();
        void getMemoryProperties();

        const Instance& m_instance;
        VkPhysicalDevice m_physicalDevice;
        PhysicalDeviceProperties m_properties;
        PhysicalDeviceFeatures m_features;
        std::vector<QueueFamilyProperties> m_families;
        std::vector<LayerProperties> m_layers;
        std::unordered_map<std::string, std::vector<ExtensionProperties>> m_extensionMap;
        MemoryProperties m_memoryProperties;
    };
}