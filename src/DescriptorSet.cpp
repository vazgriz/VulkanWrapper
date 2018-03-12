#include "VulkanWrapper/DescriptorSet.h"
#include "VulkanWrapper/DescriptorPool.h"
#include "VulkanWrapper/DescriptorSetLayout.h"
#include "VulkanWrapper/Device.h"

void vk::DescriptorSetAllocateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.descriptorPool = descriptorPool->handle();
    
    m_layouts.reserve(setLayouts.size());
    for (const DescriptorSetLayout& layout : setLayouts) {
        m_layouts.push_back(layout.handle());
    }

    m_info.descriptorSetCount = static_cast<uint32_t>(m_layouts.size());
    m_info.pSetLayouts = m_layouts.data();
}

vk::DescriptorSet::DescriptorSet(Device& device, vk::DescriptorPool& pool, VkDescriptorSet descriptorSet) : m_device(device), m_pool(pool) {
    m_descriptorSet = descriptorSet;
}

vk::DescriptorSet::DescriptorSet(vk::DescriptorSet&& other) : m_device(other.device()), m_pool(other.pool()) {
    m_descriptorSet = other.m_descriptorSet;
    other.m_descriptorSet = VK_NULL_HANDLE;
}

vk::DescriptorSet::~DescriptorSet() {
    if (m_destructorEnabled) vkFreeDescriptorSets(m_device.handle(), m_pool.handle(), 1, &m_descriptorSet);
}