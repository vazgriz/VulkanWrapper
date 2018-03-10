#include "VulkanWrapper/DeviceMemory.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

void vk::MemoryAllocateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
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

vk::DeviceMemory::DeviceMemory(DeviceMemory&& other) : m_device(other.device()) {
    m_deviceMemory = other.m_deviceMemory;
    m_size = other.m_size;
    m_typeIndex = other.m_typeIndex;
    m_mapping = other.m_mapping;
    m_mappingOffset = other.m_mappingOffset;
    m_mappingSize = other.m_mappingSize;
    other.m_deviceMemory = VK_NULL_HANDLE;
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