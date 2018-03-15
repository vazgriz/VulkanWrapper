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

    class BufferViewCreateInfo : public Info<VkBufferViewCreateInfo> {
    public:
        BufferViewCreateFlags flags;
        const Buffer* buffer;
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
        ~BufferView();

        VkBufferView handle() const { return m_bufferView; }
        Device& device() const { return m_device; }

    private:
        VkBufferView m_bufferView;
        Device& m_device;
    };
}