#include "VulkanWrapper/CommandBuffer.h"
#include "VulkanWrapper/CommandPool.h"
#include "VulkanWrapper/RenderPass.h"
#include "VulkanWrapper/Framebuffer.h"
#include "VulkanWrapper/GraphicsPipeline.h"
#include "VulkanWrapper/Buffer.h"
#include "VulkanWrapper/Device.h"

void vk::CommandBufferInheritanceInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.renderPass = renderPass->handle();
    m_info.subpass = subpass;
    m_info.framebuffer = framebuffer->handle();
    m_info.occlusionQueryEnable = occlusionQueryEnable;
    m_info.queryFlags = static_cast<VkQueryControlFlags>(queryFlags);
    m_info.pipelineStatistics = static_cast<VkQueryPipelineStatisticFlags>(pipelineStatistics);
}

void vk::CommandBufferBeginInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkCommandBufferUsageFlags>(flags);
    
    if (inheritanceInfo != nullptr) {
        m_info.pInheritanceInfo = inheritanceInfo->getInfo();
    } else {
        m_info.pInheritanceInfo = nullptr;
    }
}

void vk::CommandBufferAllocateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.commandPool = commandPool->handle();
    m_info.commandBufferCount = static_cast<uint32_t>(commandBufferCount);
    m_info.level = static_cast<VkCommandBufferLevel>(level);
}

void vk::RenderPassBeginInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.renderPass = renderPass->handle();
    m_info.framebuffer = framebuffer->handle();
    m_info.renderArea = renderArea;
    m_info.clearValueCount = static_cast<uint32_t>(clearValues.size());
    m_info.pClearValues = clearValues.data();
}

vk::CommandBuffer::CommandBuffer(CommandPool& commandPool, VkCommandBuffer commandBuffer) : m_commandPool(commandPool) {
    m_commandBuffer = commandBuffer;
    m_destructorEnabled = false;
}

vk::CommandBuffer::CommandBuffer(CommandBuffer&& other) : m_commandPool(other.pool()) {
    m_commandBuffer = other.m_commandBuffer;
    m_destructorEnabled = other.m_destructorEnabled;
    other.m_commandBuffer = VK_NULL_HANDLE;
}

vk::CommandBuffer::~CommandBuffer() {
    if (m_destructorEnabled) vkFreeCommandBuffers(m_commandPool.device().handle(), m_commandPool.handle(), 1, &m_commandBuffer);
}

void vk::CommandBuffer::begin(const vk::CommandBufferBeginInfo& info) const {
    info.marshal();

    VKW_CHECK(vkBeginCommandBuffer(m_commandBuffer, info.getInfo()));
}

void vk::CommandBuffer::end() const {
    VKW_CHECK(vkEndCommandBuffer(m_commandBuffer));
}

void vk::CommandBuffer::beginRenderPass(const vk::RenderPassBeginInfo& info, SubpassContents contents) const {
    info.marshal();

    vkCmdBeginRenderPass(m_commandBuffer, info.getInfo(), static_cast<VkSubpassContents>(contents));
}

void vk::CommandBuffer::endRenderPass() const {
    vkCmdEndRenderPass(m_commandBuffer);
}

void vk::CommandBuffer::draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const {
    vkCmdDraw(m_commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

void vk::CommandBuffer::bindVertexBuffers(uint32_t firstBinding, ArrayProxy<const std::reference_wrapper<vk::Buffer>> buffers, ArrayProxy<const vk::DeviceSize> offsets) const {
    std::vector<VkBuffer> vkBuffers;
    vkBuffers.reserve(buffers.size());
    for (const vk::Buffer& buffer : buffers) {
        vkBuffers.push_back(buffer.handle());
    }
    vkCmdBindVertexBuffers(m_commandBuffer, firstBinding, static_cast<uint32_t>(vkBuffers.size()), vkBuffers.data(), offsets.data());
}

void vk::CommandBuffer::bindIndexBuffer(vk::Buffer& buffer, vk::DeviceSize offset, vk::IndexType indexType) const {
    vkCmdBindIndexBuffer(m_commandBuffer, buffer.handle(), offset, static_cast<VkIndexType>(indexType));
}

void vk::CommandBuffer::bindPipeline(vk::PipelineBindPoint pipelineBindPoint, const vk::Pipeline& pipeline) const {
    vkCmdBindPipeline(m_commandBuffer, static_cast<VkPipelineBindPoint>(pipelineBindPoint), pipeline.handle());
}

void vk::CommandBuffer::copy(vk::Buffer& src, vk::Buffer& dst, ArrayProxy<const vk::BufferCopy> copy) {
    vkCmdCopyBuffer(m_commandBuffer, src.handle(), dst.handle(), static_cast<uint32_t>(copy.size()), copy.data());
}