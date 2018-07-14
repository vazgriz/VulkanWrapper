#include "VulkanWrapper/Buffer.h"
#include "VulkanWrapper/DeviceMemory.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

void BufferCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkBufferCreateFlags>(flags);
    m_info.size = size;
    m_info.usage = static_cast<VkBufferUsageFlags>(usage);
    m_info.queueFamilyIndexCount = static_cast<uint32_t>(queueFamilyIndices.size());
    m_info.pQueueFamilyIndices = queueFamilyIndices.data();
}

Buffer::Buffer(Device& device, const BufferCreateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateBuffer(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_buffer));
    m_device = &device;

    getRequirements();
}

Buffer::Buffer(Buffer&& other) {
    *this = std::move(other);
}

Buffer& Buffer::operator = (Buffer&& other) {
    m_device = other.m_device;
    m_buffer = other.m_buffer;
    m_requirements = other.m_requirements;
    m_info = std::move(other.m_info);
    other.m_buffer = VK_NULL_HANDLE;
    return *this;
}

Buffer::~Buffer() {
    vkDestroyBuffer(m_device->handle(), m_buffer, device().instance().callbacks());
}

void Buffer::getRequirements() {
    vkGetBufferMemoryRequirements(m_device->handle(), m_buffer, &m_requirements);
}

void Buffer::bind(DeviceMemory& memory, size_t offset) {
    vkBindBufferMemory(m_device->handle(), m_buffer, memory.handle(), offset);
}