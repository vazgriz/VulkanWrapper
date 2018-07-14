#include "VulkanWrapper/DeviceMemory.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

void MemoryAllocateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.allocationSize = allocationSize;
    m_info.memoryTypeIndex = memoryTypeIndex;
}

DeviceMemory::DeviceMemory(Device& device, const MemoryAllocateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkAllocateMemory(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_deviceMemory));
    m_device = &device;

    m_mapping = nullptr;
    m_mappingOffset = 0;
    m_mappingSize = 0;
}

DeviceMemory::DeviceMemory(DeviceMemory&& other) {
    m_device = other.m_device;
    m_deviceMemory = other.m_deviceMemory;
    m_info = std::move(other.m_info);
    m_mapping = other.m_mapping;
    m_mappingOffset = other.m_mappingOffset;
    m_mappingSize = other.m_mappingSize;
    other.m_deviceMemory = VK_NULL_HANDLE;
}

DeviceMemory& DeviceMemory::operator = (DeviceMemory&& other) {
    vkFreeMemory(m_device->handle(), m_deviceMemory, device().instance().callbacks());
    m_device = other.m_device;
    m_deviceMemory = other.m_deviceMemory;
    m_info = std::move(other.m_info);
    m_mapping = other.m_mapping;
    m_mappingOffset = other.m_mappingOffset;
    m_mappingSize = other.m_mappingSize;
    other.m_deviceMemory = VK_NULL_HANDLE;
    return *this;
}

DeviceMemory::~DeviceMemory() {
    vkFreeMemory(m_device->handle(), m_deviceMemory, device().instance().callbacks());
}

void* DeviceMemory::map(size_t offset, size_t size) {
    m_mappingOffset = offset;
    if (size == VK_WHOLE_SIZE) {
        m_mappingSize = this->size();
    } else {
        m_mappingSize = size;
    }
    vkMapMemory(m_device->handle(), m_deviceMemory, offset, size, 0, &m_mapping);
    return m_mapping;
}

void DeviceMemory::unmap() {
    vkUnmapMemory(m_device->handle(), m_deviceMemory);
    m_mapping = nullptr;
    m_mappingOffset = 0;
    m_mappingSize = 0;
}