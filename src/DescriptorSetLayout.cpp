#include "VulkanWrapper/DescriptorSetLayout.h"
#include "VulkanWrapper/Sampler.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

void DescriptorSetLayoutBinding::marshal() const {
    m_info.binding = binding;
    m_info.descriptorType = static_cast<VkDescriptorType>(descriptorType);
    m_info.descriptorCount = descriptorCount;
    m_info.stageFlags = static_cast<VkShaderStageFlags>(stageFlags);

    m_samplers.reserve(immutableSamplers.size());
    for (const Sampler& sampler : immutableSamplers) {
        m_samplers.push_back(sampler.handle());
    }
}

void DescriptorSetLayoutCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkDescriptorSetLayoutCreateFlags>(flags);

    m_bindings.reserve(bindings.size());
    for (auto& binding : bindings) {
        binding.marshal();
        m_bindings.push_back(*binding.getInfo());
    }

    m_info.bindingCount = static_cast<uint32_t>(m_bindings.size());
    m_info.pBindings = m_bindings.data();
}

DescriptorSetLayout::DescriptorSetLayout(Device& device, const DescriptorSetLayoutCreateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateDescriptorSetLayout(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_descriptorSetLayout));
    m_device = &device;
}

DescriptorSetLayout::DescriptorSetLayout(DescriptorSetLayout&& other) {
    m_device = other.m_device;
    m_descriptorSetLayout = other.m_descriptorSetLayout;
    m_info = std::move(other.m_info);
    other.m_descriptorSetLayout = VK_NULL_HANDLE;
}

DescriptorSetLayout& DescriptorSetLayout::operator = (DescriptorSetLayout&& other) {
    vkDestroyDescriptorSetLayout(m_device->handle(), m_descriptorSetLayout, device().instance().callbacks());
    m_device = other.m_device;
    m_descriptorSetLayout = other.m_descriptorSetLayout;
    m_info = std::move(other.m_info);
    other.m_descriptorSetLayout = VK_NULL_HANDLE;
    return *this;
}

DescriptorSetLayout::~DescriptorSetLayout() {
    vkDestroyDescriptorSetLayout(m_device->handle(), m_descriptorSetLayout, device().instance().callbacks());
}