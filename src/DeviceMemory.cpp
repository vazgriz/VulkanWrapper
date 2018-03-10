#include "VulkanWrapper/DeviceMemory.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

void vk::MemoryAllocateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = &next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.allocationSize = allocationSize;
    m_info.memoryTypeIndex = memoryTypeIndex;
}

vk::DeviceMemory::DeviceMemory(Device& device, const MemoryAllocateInfo& info) : m_device(device) {
    info.marshal();

    VKW_CHECK(vkAllocateMemory(device.handle(), &info.info(), device.instance().callbacks(), &m_deviceMemory));

    m_size = info.allocationSize;
    m_mapping = nullptr;
    m_mappingOffset = 0;
    m_mappingSize = 0;
}

vk::DeviceMemory::~DeviceMemory() {
    vkFreeMemory(m_device.handle(), m_deviceMemory, m_device.instance().callbacks());
}

void* vk::DeviceMemory::map(size_t offset, size_t size) {
    m_mappingOffset = offset;
    m_mappingSize = size;
    vkMapMemory(m_device.handle(), m_deviceMemory, offset, size, 0, &m_mapping);
    return m_mapping;
}

void vk::DeviceMemory::unmap() {
    vkUnmapMemory(m_device.handle(), m_deviceMemory);
    m_mapping = nullptr;
    m_mappingOffset = 0;
    m_mappingSize = 0;
}