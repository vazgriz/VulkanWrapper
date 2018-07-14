#include "VulkanWrapper/DescriptorPool.h"
#include "VulkanWrapper/DescriptorSetLayout.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"
#include "VulkanWrapper/DescriptorSet.h"

using namespace vk;

void DescriptorSetAllocateInfo::marshal() const {
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

void DescriptorPoolCreateInfo::marshal() const {
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

DescriptorPool::DescriptorPool(Device& device, const DescriptorPoolCreateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateDescriptorPool(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_descriptorPool));
    m_device = &device;
}

DescriptorPool::DescriptorPool(DescriptorPool&& other) {
    m_device = other.m_device;
    m_descriptorPool = other.m_descriptorPool;
    m_info = std::move(other.m_info);
    other.m_descriptorPool = VK_NULL_HANDLE;
}

DescriptorPool& DescriptorPool::operator = (DescriptorPool&& other) {
    vkDestroyDescriptorPool(m_device->handle(), m_descriptorPool, device().instance().callbacks());
    m_device = other.m_device;
    m_descriptorPool = other.m_descriptorPool;
    m_info = std::move(other.m_info);
    other.m_descriptorPool = VK_NULL_HANDLE;
    return *this;
}

DescriptorPool::~DescriptorPool() {
    vkDestroyDescriptorPool(m_device->handle(), m_descriptorPool, device().instance().callbacks());
}

std::vector<DescriptorSet> DescriptorPool::allocate(const DescriptorSetAllocateInfo& info) {
    auto l_info = info;
    std::vector<DescriptorSetLayoutCreateInfo> layoutInfos;
    layoutInfos.reserve(l_info.setLayouts.size());

    for (const DescriptorSetLayout& layout : l_info.setLayouts) {
        DescriptorSetLayoutCreateInfo layoutInfo = {};
        layoutInfo.flags = layout.flags();
        layoutInfo.bindings = layout.bindings();
        layoutInfos.emplace_back(layoutInfo);
    }

    l_info.marshal();
    std::vector<VkDescriptorSet> sets;
    sets.resize(l_info.setLayouts.size());

    VKW_CHECK(vkAllocateDescriptorSets(m_device->handle(), l_info.getInfo(), sets.data()));

    std::vector<DescriptorSet> result;
    result.reserve(sets.size());
    for (auto set : sets) {
        result.emplace_back(device(), *this, set, layoutInfos);
    }

    return result;
}