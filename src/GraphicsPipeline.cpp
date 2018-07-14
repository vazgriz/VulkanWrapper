#include "VulkanWrapper/GraphicsPipeline.h"
#include "VulkanWrapper/ShaderModule.h"
#include "VulkanWrapper/PipelineLayout.h"
#include "VulkanWrapper/RenderPass.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

void PipelineVertexInputStateCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.vertexBindingDescriptionCount = static_cast<uint32_t>(vertexBindingDescriptions.size());
    m_info.pVertexBindingDescriptions = reinterpret_cast<const VkVertexInputBindingDescription*>(vertexBindingDescriptions.data());
    m_info.vertexAttributeDescriptionCount = static_cast<uint32_t>(vertexAttributeDescriptions.size());
    m_info.pVertexAttributeDescriptions = reinterpret_cast<const VkVertexInputAttributeDescription*>(vertexAttributeDescriptions.data());
}

void PipelineInputAssemblyStateCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkPipelineInputAssemblyStateCreateFlags>(flags);
    m_info.topology = static_cast<VkPrimitiveTopology>(topology);
    m_info.primitiveRestartEnable = primitiveRestartEnable;
}

void PipelineTessellationStateCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkPipelineTessellationStateCreateFlags>(flags);
    m_info.patchControlPoints = patchControlPoints;
}

void PipelineViewportStateCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkPipelineViewportStateCreateFlags>(flags);
    m_info.viewportCount = static_cast<uint32_t>(viewports.size());
    m_info.pViewports = viewports.data();
    m_info.scissorCount = static_cast<uint32_t>(scissors.size());
    m_info.pScissors = scissors.data();
}

void PipelineRasterizationStateCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkPipelineRasterizationStateCreateFlags>(flags);
    m_info.depthClampEnable = depthClampEnable;
    m_info.rasterizerDiscardEnable = rasterizerDiscardEnable;
    m_info.polygonMode = static_cast<VkPolygonMode>(polygonMode);
    m_info.cullMode = static_cast<VkCullModeFlags>(cullMode);
    m_info.frontFace = static_cast<VkFrontFace>(frontFace);
    m_info.depthBiasEnable = depthBiasEnable;
    m_info.depthBiasConstantFactor = depthBiasConstantFactor;
    m_info.depthBiasClamp = depthBiasClamp;
    m_info.depthBiasSlopeFactor = depthBiasSlopeFactor;
    m_info.lineWidth = lineWidth;
}

void PipelineMultisampleStateCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkPipelineMultisampleStateCreateFlags>(flags);
    m_info.rasterizationSamples = static_cast<VkSampleCountFlagBits>(rasterizationSamples);
    m_info.sampleShadingEnable = sampleShadingEnable;
    m_info.pSampleMask = sampleMask.size() > 0 ? sampleMask.data() : nullptr;
    m_info.alphaToCoverageEnable = alphaToCoverageEnable;
    m_info.alphaToOneEnable = alphaToOneEnable;
}

void PipelineDepthStencilStateCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkPipelineDepthStencilStateCreateFlags>(flags);
    m_info.depthTestEnable = depthTestEnable;
    m_info.depthWriteEnable = depthWriteEnable;
    m_info.depthCompareOp = static_cast<VkCompareOp>(depthCompareOp);
    m_info.depthBoundsTestEnable = depthBoundsTestEnable;
    m_info.stencilTestEnable = stencilTestEnable;
    m_info.front = *reinterpret_cast<const VkStencilOpState*>(&front);
    m_info.back = *reinterpret_cast<const VkStencilOpState*>(&back);
    m_info.minDepthBounds = minDepthBounds;
    m_info.maxDepthBounds = maxDepthBounds;
}

void PipelineColorBlendStateCreateInfo::marshal() const {
    m_attachments.clear();

    m_info.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkPipelineColorBlendStateCreateFlags>(flags);
    m_info.logicOpEnable = logicOpEnable;
    m_info.logicOp = static_cast<VkLogicOp>(logicOp);

    m_attachments.reserve(attachments.size());
    for (auto& attachment : attachments) {
        attachment.marshal();
        m_attachments.push_back(attachment.info());
    }

    m_info.attachmentCount = static_cast<uint32_t>(m_attachments.size());
    m_info.pAttachments = m_attachments.data();
    std::memcpy(m_info.blendConstants, blendConstants, sizeof(blendConstants));
}

void PipelineDynamicStateCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkPipelineDynamicStateCreateFlags>(flags);
    m_info.dynamicStateCount = static_cast<uint32_t>(dynamicStates.size());
    m_info.pDynamicStates = reinterpret_cast<const VkDynamicState*>(dynamicStates.data());
}

void GraphicsPipelineCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkPipelineCreateFlags>(flags);

    m_stages.reserve(stages.size());
    for (auto& stage : stages) {
        stage.marshal();
        m_stages.push_back(*stage.getInfo());
    }

    m_info.stageCount = static_cast<uint32_t>(m_stages.size());
    m_info.pStages = m_stages.data();

    vertexInputState->marshal();
    inputAssemblyState->marshal();
    if (tessellationState != nullptr) tessellationState->marshal();
    if (viewportState != nullptr) viewportState->marshal();
    rasterizationState->marshal();
    if (multisampleState != nullptr) multisampleState->marshal();
    if (depthStencilState != nullptr) depthStencilState->marshal();
    if (colorBlendState != nullptr) colorBlendState->marshal();
    if (dynamicState != nullptr) dynamicState->marshal();

    m_info.pVertexInputState = vertexInputState->getInfo();
    m_info.pInputAssemblyState = inputAssemblyState->getInfo();
    m_info.pTessellationState = tessellationState != nullptr ? tessellationState->getInfo() : nullptr;
    m_info.pViewportState = viewportState != nullptr ? viewportState->getInfo() : nullptr;
    m_info.pRasterizationState = rasterizationState->getInfo();
    m_info.pMultisampleState = multisampleState != nullptr ? multisampleState->getInfo() : nullptr;
    m_info.pDepthStencilState = depthStencilState != nullptr ? depthStencilState->getInfo() : nullptr;
    m_info.pColorBlendState = colorBlendState != nullptr ? colorBlendState->getInfo() : nullptr;
    m_info.pDynamicState = dynamicState != nullptr ? dynamicState->getInfo() : nullptr;
    m_info.layout = layout->handle();
    m_info.renderPass = renderPass->handle();
    m_info.subpass = subpass;
    m_info.basePipelineHandle = basePipelineHandle != nullptr ? basePipelineHandle->handle() : VK_NULL_HANDLE;
    m_info.basePipelineIndex = basePipelineIndex;
}

GraphicsPipeline::GraphicsPipeline(Device& device, const GraphicsPipelineCreateInfo& info) : Pipeline(device, *info.layout) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateGraphicsPipelines(device.handle(), VK_NULL_HANDLE, 1, m_info.getInfo(), device.instance().callbacks(), &m_pipeline));
}

GraphicsPipeline::GraphicsPipeline(GraphicsPipeline&& other) : Pipeline(std::move(other)) {
    *this = std::move(other);
}

GraphicsPipeline& GraphicsPipeline::operator = (GraphicsPipeline&& other) {
    Pipeline::operator =(std::move(other));
    m_info = std::move(other.m_info);
    return *this;
}