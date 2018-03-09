#include "VulkanWrapper/PipelineLayout.h"
#include "VulkanWrapper/DescriptorSetLayout.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

void vk::PipelineLayoutCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = &next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_setLayouts.reserve(setLayouts.size());
    for (const DescriptorSetLayout& setLayout : setLayouts) {
        m_setLayouts.push_back(setLayout.handle());
    }

    m_info.setLayoutCount = static_cast<uint32_t>(m_setLayouts.size());
    m_info.pSetLayouts = m_setLayouts.data();
    m_info.pushConstantRangeCount = static_cast<uint32_t>(pushConstantRanges.size());
    m_info.pPushConstantRanges = reinterpret_cast<const VkPushConstantRange*>(pushConstantRanges.data());
}

vk::PipelineLayout::PipelineLayout(Device& device, const PipelineLayoutCreateInfo& info) : m_device(device) {
    info.marshal();

    VKW_CHECK(vkCreatePipelineLayout(device.handle(), &info.info(), device.instance().callbacks(), &m_pipelineLayout));
}

vk::PipelineLayout::~PipelineLayout() {
    vkDestroyPipelineLayout(m_device.handle(), m_pipelineLayout, m_device.instance().callbacks());
}