#include "VulkanWrapper/Pipeline.h"
#include "VulkanWrapper/ShaderModule.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

void SpecializationInfo::marshal() const {
    m_info.dataSize = dataSize;
    m_info.pData = data;
    m_info.mapEntryCount = static_cast<uint32_t>(mapEntries.size());
    m_info.pMapEntries = mapEntries.data();
}

void PipelineShaderStageCreateInfo::marshal() const {
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

    if (specializationInfo != nullptr) {
        specializationInfo->marshal();
        m_info.pSpecializationInfo = specializationInfo->getInfo();
    }
}

Pipeline::Pipeline(Device& device, const PipelineLayout& pipelineLayout) : m_layoutInfo(pipelineLayout) {
    m_device = device.handle();
    m_deviceRef = &device;
}

Pipeline::Pipeline(Pipeline&& other) {
    m_layoutInfo = std::move(other.m_layoutInfo);
    m_device = other.m_device;
    m_deviceRef = other.m_deviceRef;
    m_pipeline = other.m_pipeline;
    other.m_pipeline = VK_NULL_HANDLE;
}

Pipeline& Pipeline::operator = (Pipeline&& other) {
    vkDestroyPipeline(m_device, m_pipeline, device().instance().callbacks());
    m_layoutInfo = std::move(other.m_layoutInfo);
    m_device = other.m_device;
    m_deviceRef = other.m_deviceRef;
    m_pipeline = other.m_pipeline;
    other.m_pipeline = VK_NULL_HANDLE;
    return *this;
}

Pipeline::~Pipeline() {
    vkDestroyPipeline(m_device, m_pipeline, device().instance().callbacks());
}