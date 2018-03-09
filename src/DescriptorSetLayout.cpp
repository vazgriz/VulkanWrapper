#include "VulkanWrapper/DescriptorSetLayout.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

void vk::DescriptorSetLayoutBinding::marshal() const {
    m_info.binding = binding;
    m_info.descriptorType = static_cast<VkDescriptorType>(descriptorType);
    m_info.descriptorCount = static_cast<uint32_t>(descriptorCount);
    m_info.pImmutableSamplers = nullptr;
}

void vk::DescriptorSetLayoutCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = &next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkDescriptorSetLayoutCreateFlags>(flags);

    m_bindings.reserve(bindings.size());
    for (auto& binding : bindings) {
        binding.marshal();
        m_bindings.push_back(binding.info());
    }

    m_info.bindingCount = static_cast<uint32_t>(m_bindings.size());
    m_info.pBindings = m_bindings.data();
}

vk::DescriptorSetLayout::DescriptorSetLayout(Device& device, const DescriptorSetLayoutCreateInfo& info) : m_device(device) {
    info.marshal();

    VKW_CHECK(vkCreateDescriptorSetLayout(device.handle(), &info.info(), device.instance().callbacks(), &m_descriptorSetLayout));
}

vk::DescriptorSetLayout::~DescriptorSetLayout() {
    vkDestroyDescriptorSetLayout(m_device.handle(), m_descriptorSetLayout, m_device.instance().callbacks());
}