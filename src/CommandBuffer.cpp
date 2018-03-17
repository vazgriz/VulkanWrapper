#include "VulkanWrapper/CommandBuffer.h"
#include "VulkanWrapper/CommandPool.h"
#include "VulkanWrapper/RenderPass.h"
#include "VulkanWrapper/Framebuffer.h"
#include "VulkanWrapper/GraphicsPipeline.h"
#include "VulkanWrapper/Buffer.h"
#include "VulkanWrapper/Image.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/PipelineLayout.h"
#include "VulkanWrapper/DescriptorSet.h"

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

void vk::MemoryBarrier::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.srcAccessMask = static_cast<VkAccessFlags>(srcAccessMask);
    m_info.dstAccessMask = static_cast<VkAccessFlags>(dstAccessMask);
}

void vk::BufferMemoryBarrier::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.srcAccessMask = static_cast<VkAccessFlags>(srcAccessMask);
    m_info.dstAccessMask = static_cast<VkAccessFlags>(dstAccessMask);
    m_info.srcQueueFamilyIndex = srcQueueFamilyIndex;
    m_info.dstQueueFamilyIndex = dstQueueFamilyIndex;
    m_info.buffer = buffer->handle();
    m_info.offset = offset;
    m_info.size = size;
}

void vk::ImageMemoryBarrier::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.srcAccessMask = static_cast<VkAccessFlags>(srcAccessMask);
    m_info.dstAccessMask = static_cast<VkAccessFlags>(dstAccessMask);
    m_info.oldLayout = static_cast<VkImageLayout>(oldLayout);
    m_info.newLayout = static_cast<VkImageLayout>(newLayout);
    m_info.srcQueueFamilyIndex = srcQueueFamilyIndex;
    m_info.dstQueueFamilyIndex = dstQueueFamilyIndex;
    m_info.image = image->handle();
    m_info.subresourceRange = *reinterpret_cast<const VkImageSubresourceRange*>(&subresourceRange);
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

void vk::CommandBuffer::drawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, uint32_t vertexOffset, uint32_t firstInstance) const {
    vkCmdDrawIndexed(m_commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
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

void vk::CommandBuffer::bindDescriptorSets(
    vk::PipelineBindPoint pipelineBindPoint,
    const vk::PipelineLayout& pipelineLayout,
    uint32_t firstSet,
    vk::ArrayProxy<const std::reference_wrapper<vk::DescriptorSet>> descriptorSets,
    vk::ArrayProxy<const uint32_t> dynamicOffsets) const
{
    std::vector<VkDescriptorSet> vkSets;
    vkSets.reserve(descriptorSets.size());
    for (const vk::DescriptorSet& set : descriptorSets) {
        vkSets.push_back(set.handle());
    }
    vkCmdBindDescriptorSets(m_commandBuffer,
        static_cast<VkPipelineBindPoint>(pipelineBindPoint),
        pipelineLayout.handle(),
        firstSet,
        static_cast<uint32_t>(vkSets.size()),
        vkSets.data(),
        dynamicOffsets.size(),
        dynamicOffsets.data()
    );
}

void vk::CommandBuffer::copy(vk::Buffer& src, vk::Buffer& dst, ArrayProxy<const vk::BufferCopy> copy) {
    vkCmdCopyBuffer(m_commandBuffer, src.handle(), dst.handle(), static_cast<uint32_t>(copy.size()), copy.data());
}

void vk::CommandBuffer::copyBufferToImage(vk::Buffer& src, vk::Image& dst, ImageLayout dstLayout, vk::ArrayProxy<const vk::BufferImageCopy> copies) {
    vkCmdCopyBufferToImage(m_commandBuffer, src.handle(), dst.handle(), static_cast<VkImageLayout>(dstLayout), copies.size(), reinterpret_cast<const VkBufferImageCopy*>(copies.data()));
}

void vk::CommandBuffer::pipelineBarrier(
    vk::PipelineStageFlags srcStageMask,
    vk::PipelineStageFlags dstStageMask,
    vk::DependencyFlags dependencyFlags,
    vk::ArrayProxy<const vk::MemoryBarrier> memoryBarriers,
    vk::ArrayProxy<const vk::BufferMemoryBarrier> bufferMemoryBarriers,
    vk::ArrayProxy<const vk::ImageMemoryBarrier> imageMemoryBarriers)
{
    std::vector<VkMemoryBarrier> vkMemoryBarriers;
    vkMemoryBarriers.reserve(memoryBarriers.size());
    std::vector<VkBufferMemoryBarrier> vkBufferMemoryBarriers;
    vkBufferMemoryBarriers.reserve(bufferMemoryBarriers.size());
    std::vector<VkImageMemoryBarrier> vkImageMemoryBarriers;
    vkImageMemoryBarriers.reserve(imageMemoryBarriers.size());

    for (auto& memoryBarrier : memoryBarriers) {
        memoryBarrier.marshal();
        vkMemoryBarriers.push_back(*memoryBarrier.getInfo());
    }

    for (auto& bufferMemoryBarrier : bufferMemoryBarriers) {
        bufferMemoryBarrier.marshal();
        vkBufferMemoryBarriers.push_back(*bufferMemoryBarrier.getInfo());
    }

    for (auto& imageMemoryBarrier : imageMemoryBarriers) {
        imageMemoryBarrier.marshal();
        vkImageMemoryBarriers.push_back(*imageMemoryBarrier.getInfo());
    }

    vkCmdPipelineBarrier(m_commandBuffer, static_cast<VkPipelineStageFlags>(srcStageMask), static_cast<VkPipelineStageFlags>(dstStageMask), static_cast<VkDependencyFlags>(dependencyFlags),
        memoryBarriers.size(), vkMemoryBarriers.data(),
        bufferMemoryBarriers.size(), vkBufferMemoryBarriers.data(),
        imageMemoryBarriers.size(), vkImageMemoryBarriers.data());
}