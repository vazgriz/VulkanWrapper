#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;
    class DeviceMemory;

    class BufferCreateInfo : public InfoMixin<BufferCreateInfo, VkBufferCreateInfo> {
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
        Buffer(Device& device, VkBuffer handle, bool enableDestructor, const BufferCreateInfo* info = nullptr);
        Buffer(const Buffer& other) = delete;
        Buffer& operator = (const Buffer& other) = delete;
        Buffer(Buffer&& other);
        Buffer& operator = (Buffer&& other);
        ~Buffer();

        VkBuffer handle() const { return m_buffer; }
        Device& device() const { return *m_device; }
        void setInfo(const BufferCreateInfo& info) { m_info = info; }

        void bind(DeviceMemory& memory, size_t offset);

        MemoryRequirements requirements() const { return m_requirements; }

        BufferCreateFlags flags() const { return m_info.flags; }
        size_t size() const { return m_info.size; }
        BufferUsageFlags usage() const { return m_info.usage; }
        SharingMode sharingMode() const { return m_info.sharingMode; }
        const std::vector<uint32_t>& queueFamilyIndices() const { return m_info.queueFamilyIndices; }

    private:
        VkBuffer m_buffer;
        Device* m_device;
        bool m_destructorEnabled;

        BufferCreateInfo m_info;
        MemoryRequirements m_requirements;

        void getRequirements();
    };
}