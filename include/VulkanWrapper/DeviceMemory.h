#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;

    class MemoryAllocateInfo : public CreateInfo<VkMemoryAllocateInfo> {
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
        DeviceMemory(DeviceMemory&& other) = default;
        ~DeviceMemory();

        VkDeviceMemory handle() const { return m_deviceMemory; }
        Device& device() const { return m_device; }

        size_t size() const { return m_size; }
        uint32_t typeIndex() const { return m_typeIndex; }
        size_t mappingOffset() const { return m_mappingOffset; }
        size_t mappingSize() const { return m_mappingSize; }

        void* map(size_t offset, size_t size);
        void unmap();

    private:
        VkDeviceMemory m_deviceMemory;
        Device& m_device;
        size_t m_size;
        uint32_t m_typeIndex;
        void* m_mapping;
        size_t m_mappingOffset;
        size_t m_mappingSize;
    };
}