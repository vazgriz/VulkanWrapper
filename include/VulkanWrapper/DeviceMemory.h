#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;

    class MemoryAllocateInfo : public InfoMixin<MemoryAllocateInfo, VkMemoryAllocateInfo> {
    public:
        DeviceSize allocationSize;
        uint32_t memoryTypeIndex;

        void marshal() const;
    };

    class DeviceMemory {
    public:
        DeviceMemory(Device& device, const MemoryAllocateInfo& info);
        DeviceMemory(const DeviceMemory& other) = delete;
        DeviceMemory& operator & (const DeviceMemory& other) = delete;
        DeviceMemory(DeviceMemory&& other);
        DeviceMemory& operator = (DeviceMemory&& other);
        ~DeviceMemory();

        VkDeviceMemory handle() const { return m_deviceMemory; }
        Device& device() const { return *m_device; }

        size_t size() const { return m_info.allocationSize; }
        uint32_t typeIndex() const { return m_info.memoryTypeIndex; }
        void* mapping() const { return m_mapping; }
        size_t mappingOffset() const { return m_mappingOffset; }
        size_t mappingSize() const { return m_mappingSize; }

        void* map(size_t offset, size_t size);
        void unmap();

    private:
        VkDeviceMemory m_deviceMemory;
        Device* m_device;
        MemoryAllocateInfo m_info;
        void* m_mapping;
        size_t m_mappingOffset;
        size_t m_mappingSize;
    };
}