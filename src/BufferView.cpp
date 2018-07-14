#include "VulkanWrapper/BufferView.h"
#include "VulkanWrapper/Buffer.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

void BufferViewCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkBufferViewCreateFlags>(flags);
    m_info.buffer = buffer->handle();
    m_info.format = static_cast<VkFormat>(format);
    m_info.offset = offset;
    m_info.range = range;
}

BufferView::BufferView(Device& device, const BufferViewCreateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateBufferView(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_bufferView));
    m_device = &device;
}

BufferView::BufferView(BufferView&& other) {
    *this = std::move(other);
}

BufferView& BufferView::operator = (BufferView&& other) {
    m_device = other.m_device;
    m_bufferView = other.m_bufferView;
    m_info = std::move(other.m_info);
    other.m_bufferView = VK_NULL_HANDLE;
    return *this;
}

BufferView::~BufferView() {
    vkDestroyBufferView(m_device->handle(), m_bufferView, device().instance().callbacks());
}