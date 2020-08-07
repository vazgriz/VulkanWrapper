#include "VulkanWrapper/ComputePipeline.h"
#include "VulkanWrapper/PipelineLayout.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

void ComputePipelineCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
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

ComputePipeline::ComputePipeline(ComputePipeline&& other) : Pipeline(std::move(other)) {
    *this = std::move(other);
}

ComputePipeline& ComputePipeline::operator = (ComputePipeline&& other) {
    Pipeline::operator =(std::move(other));
    m_info = std::move(other.m_info);
    return *this;
}

ComputePipeline::ComputePipeline(Device& device, const ComputePipelineCreateInfo& info) : Pipeline(device, *info.layout) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateComputePipelines(device.handle(), VK_NULL_HANDLE, 1, m_info.getInfo(), device.instance().callbacks(), &m_pipeline));
}