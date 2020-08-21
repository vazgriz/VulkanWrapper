#pragma once
#include <unordered_map>
#include <vulkan/vulkan.h>
#include <memory>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/structs.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/LayerProperties.h"
#include "VulkanWrapper/ExtensionProperties.h"

namespace vk {
    class Instance;
    class Surface;

    class PhysicalDeviceFeatures2 : public InfoMixin<PhysicalDeviceFeatures2, VkPhysicalDeviceFeatures2> {
    public:
        PhysicalDeviceFeatures features;
        mutable PhysicalDeviceVulkan11Features features11;
        mutable PhysicalDeviceVulkan12Features features12;

        void marshal() const;
        void unmarshal();
    };

    struct MemoryType {
        MemoryPropertyFlags propertyFlags;
        uint32_t heapIndex;

        MemoryType(VkMemoryType type);
    };

    struct MemoryHeap {
        DeviceSize size;
        MemoryHeapFlags flags;

        MemoryHeap(VkMemoryHeap heap);
    };

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

        QueueFamilyProperties(VkQueueFamilyProperties properties);
    };

    struct MemoryProperties {
        std::vector<MemoryType> memoryTypes;
        std::vector<MemoryHeap> memoryHeaps;
    };

    class PhysicalDevice {
    public:
        PhysicalDevice(Instance& instance, VkPhysicalDevice physicalDevice);
        PhysicalDevice& operator = (const PhysicalDevice& other) = delete;

        VkPhysicalDevice handle() const { return m_physicalDevice; }
        Instance& instance() const { return *m_instanceRef; }

        const PhysicalDeviceProperties& properties() const { return m_properties; }
        const PhysicalDeviceFeatures2& features() const { return m_features; }
        const std::vector<QueueFamilyProperties>& queueFamilies() const { return m_families; }
        const std::vector<LayerProperties>& availableLayers() const { return m_layers; }
        const std::vector<ExtensionProperties>& availableExtensions(const std::string& layerName = "") const { return m_extensionMap.at(layerName); }
        const MemoryProperties& memoryProperties() const { return m_memoryProperties; }

        FormatProperties getFormatProperties(Format format) const;
        ImageFormatProperties getImageFormatProperties(
            Format format,
            ImageType type,
            ImageTiling tiling,
            ImageUsageFlags usage,
            ImageCreateFlags flags) const;

    private:
        void getProperties();
        void getFeatures();
        void getQueueFamilies();
        void getLayers();
        void getExtensions(const std::string& layerName);
        void getExtensions();
        void getMemoryProperties();

        Instance* m_instanceRef;
        VkPhysicalDevice m_physicalDevice;
        PhysicalDeviceProperties m_properties;
        PhysicalDeviceFeatures2 m_features;
        std::vector<QueueFamilyProperties> m_families;
        std::vector<LayerProperties> m_layers;
        std::unordered_map<std::string, std::vector<ExtensionProperties>> m_extensionMap;
        MemoryProperties m_memoryProperties;
    };
}