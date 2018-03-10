#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;
    class DeviceMemory;

    class BufferCreateInfo : public CreateInfo<VkBufferCreateInfo> {
    public:
        BufferCreateFlags flags;
        DeviceSize size;
        BufferUsageFlags usage;
        SharingMode sharingMode;
        std::vector<uint32_t> queueFamilyIndices;

        void marshal() const;
    };

    class Buffer {
    public:
        Buffer(Device& device, const BufferCreateInfo& info);
        Buffer(const Buffer& other) = delete;
        Buffer& operator = (const Buffer& other) = delete;
        Buffer(Buffer&& other) = default;
        ~Buffer();

        VkBuffer handle() const { return m_buffer; }
        Device& device() const { return m_device; }

        void bind(DeviceMemory& memory, size_t offset);

        MemoryRequirements requirements() const { return m_requirements; }

    private:
        void getRequirements();

        VkBuffer m_buffer;
        Device& m_device;

        MemoryRequirements m_requirements;
    };
}