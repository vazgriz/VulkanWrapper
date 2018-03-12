#include "VulkanWrapper/DescriptorPool.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"
#include "VulkanWrapper/DescriptorSet.h"

void vk::DescriptorPoolCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkDescriptorPoolCreateFlags>(flags);
    m_info.maxSets = maxSets;
    m_info.poolSizeCount = static_cast<uint32_t>(poolSizes.size());
    m_info.pPoolSizes = reinterpret_cast<const VkDescriptorPoolSize*>(poolSizes.data());
}

vk::DescriptorPool::DescriptorPool(Device& device, const DescriptorPoolCreateInfo& info) : m_device(device) {
    info.marshal();

    VKW_CHECK(vkCreateDescriptorPool(device.handle(), info.getInfo(), device.instance().callbacks(), &m_descriptorPool));
}

vk::DescriptorPool::DescriptorPool(vk::DescriptorPool&& other) : m_device(other.device()) {
    m_descriptorPool = other.m_descriptorPool;
    other.m_descriptorPool = VK_NULL_HANDLE;
}

vk::DescriptorPool::~DescriptorPool() {
    vkDestroyDescriptorPool(m_device.handle(), m_descriptorPool, m_device.instance().callbacks());
}

std::vector<vk::DescriptorSet> vk::DescriptorPool::allocate(const vk::DescriptorSetAllocateInfo& info) {
    info.marshal();
    std::vector<VkDescriptorSet> sets;
    sets.reserve(info.setLayouts.size());

    VKW_CHECK(vkAllocateDescriptorSets(m_device.handle(), info.getInfo(), sets.data()));

    std::vector<vk::DescriptorSet> result;
    result.reserve(sets.size());
    for (auto set : sets) {
        result.emplace_back(m_device, *this, set);
    }

    return result;
}