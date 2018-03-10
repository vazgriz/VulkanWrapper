#include "VulkanWrapper/Buffer.h"
#include "VulkanWrapper/DeviceMemory.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

void vk::BufferCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = &next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkBufferCreateFlags>(flags);
    m_info.size = size;
    m_info.usage = static_cast<VkBufferUsageFlags>(usage);
    m_info.queueFamilyIndexCount = static_cast<uint32_t>(queueFamilyIndices.size());
    m_info.pQueueFamilyIndices = queueFamilyIndices.data();
}

vk::Buffer::Buffer(Device& device, const BufferCreateInfo& info) : m_device(device) {
    info.marshal();

    VKW_CHECK(vkCreateBuffer(device.handle(), &info.info(), device.instance().callbacks(), &m_buffer));

    getRequirements();
}

vk::Buffer::Buffer(vk::Buffer&& other) : m_device(other.device()) {
    m_buffer = other.m_buffer;
    m_requirements = other.m_requirements;
    other.m_buffer = VK_NULL_HANDLE;
}

vk::Buffer::~Buffer() {
    vkDestroyBuffer(m_device.handle(), m_buffer, m_device.instance().callbacks());
}

void vk::Buffer::getRequirements() {
    vkGetBufferMemoryRequirements(m_device.handle(), m_buffer, &m_requirements);
}

void vk::Buffer::bind(DeviceMemory& memory, size_t offset) {
    vkBindBufferMemory(m_device.handle(), m_buffer, memory.handle(), offset);
}