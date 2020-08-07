#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Buffer;
    class Device;
    struct DeviceRef;

    class BufferViewCreateInfo : public InfoMixin<BufferViewCreateInfo, VkBufferViewCreateInfo> {
    public:
        BufferViewCreateFlags flags;
        Buffer* buffer;
        Format format;
        DeviceSize offset;
        DeviceSize range;

        void marshal() const;
    };

    class BufferView {
    public:
        BufferView(Device& device, const BufferViewCreateInfo& info);
        BufferView(const BufferView& other) = delete;
        BufferView& operator = (const BufferView& other) = delete;
        BufferView(BufferView&& other);
        BufferView& operator = (BufferView&& other);
        ~BufferView();

        VkBufferView handle() const { return m_bufferView; }
        Device& device() const { return *m_device; }

        BufferViewCreateFlags flags() const { return m_info.flags; }
        Buffer& buffer() const { return *m_info.buffer; }
        Format format() const { return m_info.format; }
        size_t offset() const { return m_info.offset; }
        size_t range() const { return m_info.range; }

    private:
        VkBufferView m_bufferView;
        Device* m_device;

        BufferViewCreateInfo m_info;
    };
}