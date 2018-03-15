#include "VulkanWrapper/ComputePipeline.h"
#include "VulkanWrapper/PipelineLayout.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

void vk::ComputePipelineCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkPipelineCreateFlags>(flags);

    stage.marshal();

    m_info.stage = *stage.getInfo();
    m_info.layout = layout->handle();

    if (basePipelineHandle != nullptr) {
        m_info.basePipelineHandle = basePipelineHandle->handle();
    }

    m_info.basePipelineIndex = basePipelineIndex;
}

vk::ComputePipeline::ComputePipeline(Device& device, const ComputePipelineCreateInfo& info) : Pipeline(device) {
    info.marshal();

    VKW_CHECK(vkCreateComputePipelines(device.handle(), VK_NULL_HANDLE, 1, info.getInfo(), device.instance().callbacks(), &m_pipeline));
}