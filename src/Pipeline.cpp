#include "VulkanWrapper/Pipeline.h"
#include "VulkanWrapper/ShaderModule.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

void vk::PipelineShaderStageCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkPipelineShaderStageCreateFlags>(flags);
    m_info.stage = static_cast<VkShaderStageFlagBits>(stage);
    m_info.module = module->handle();
    m_info.pName = name.c_str();
    m_info.pSpecializationInfo = specializationInfo;
}

vk::Pipeline::Pipeline(Device& device, const PipelineLayout& pipelineLayout) : m_device(device), m_layoutInfo(pipelineLayout) { }

vk::Pipeline::Pipeline(vk::Pipeline&& other) : m_device(other.device()), m_layoutInfo(std::move(other.m_layoutInfo)) {
    m_pipeline = other.m_pipeline;
    other.m_pipeline = VK_NULL_HANDLE;
}

vk::Pipeline::~Pipeline() {
    vkDestroyPipeline(m_device.handle(), m_pipeline, m_device.instance().callbacks());
}