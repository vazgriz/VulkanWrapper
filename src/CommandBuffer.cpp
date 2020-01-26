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
#include "VulkanWrapper/Event.h"

using namespace vk;

void CommandBufferInheritanceInfo::marshal() const {
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

void CommandBufferBeginInfo::marshal() const {
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

void RenderPassBeginInfo::marshal() const {
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

void MemoryBarrier::marshal() const {
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

void BufferMemoryBarrier::marshal() const {
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

void ImageMemoryBarrier::marshal() const {
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

CommandBuffer::CommandBuffer(CommandPool& commandPool, VkCommandBuffer commandBuffer, const CommandBufferAllocateInfo& info) {
    m_commandBuffer = commandBuffer;
    m_pool = &commandPool;
    m_destructorEnabled = false;
    m_level = info.level;
}

CommandBuffer::CommandBuffer(CommandBuffer&& other) {
    m_pool = other.m_pool;
    m_commandBuffer = other.m_commandBuffer;
    m_destructorEnabled = other.m_destructorEnabled;
    m_level = other.m_level;
    other.m_commandBuffer = VK_NULL_HANDLE;
}

CommandBuffer& CommandBuffer::operator = (CommandBuffer&& other) {
    if (m_destructorEnabled) vkFreeCommandBuffers(pool().device().handle(), m_pool->handle(), 1, &m_commandBuffer);
    m_pool = other.m_pool;
    m_commandBuffer = other.m_commandBuffer;
    m_destructorEnabled = other.m_destructorEnabled;
    m_level = other.m_level;
    other.m_commandBuffer = VK_NULL_HANDLE;
    return *this;
}

CommandBuffer::~CommandBuffer() {
    if (m_destructorEnabled) vkFreeCommandBuffers(pool().device().handle(), m_pool->handle(), 1, &m_commandBuffer);
}

void CommandBuffer::begin(const CommandBufferBeginInfo& info) const {
    info.marshal();

    VKW_CHECK(vkBeginCommandBuffer(m_commandBuffer, info.getInfo()));
}

void CommandBuffer::end() const {
    VKW_CHECK(vkEndCommandBuffer(m_commandBuffer));
}

void CommandBuffer::reset(vk::CommandBufferResetFlags flags) const {
    VKW_CHECK(vkResetCommandBuffer(m_commandBuffer, static_cast<VkCommandBufferResetFlags>(flags)));
}

void CommandBuffer::beginRenderPass(const RenderPassBeginInfo& info, SubpassContents contents) const {
    info.marshal();

    vkCmdBeginRenderPass(m_commandBuffer, info.getInfo(), static_cast<VkSubpassContents>(contents));
}

void CommandBuffer::endRenderPass() const {
    vkCmdEndRenderPass(m_commandBuffer);
}

void CommandBuffer::draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const {
    vkCmdDraw(m_commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

void CommandBuffer::drawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, uint32_t vertexOffset, uint32_t firstInstance) const {
    vkCmdDrawIndexed(m_commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

void CommandBuffer::bindVertexBuffers(uint32_t firstBinding, ArrayProxy<const std::reference_wrapper<const Buffer>> buffers, ArrayProxy<const DeviceSize> offsets) const {
    std::vector<VkBuffer> vkBuffers;
    vkBuffers.reserve(buffers.size());
    for (const Buffer& buffer : buffers) {
        vkBuffers.push_back(buffer.handle());
    }
    vkCmdBindVertexBuffers(m_commandBuffer, firstBinding, static_cast<uint32_t>(vkBuffers.size()), vkBuffers.data(), offsets.data());
}

void CommandBuffer::bindIndexBuffer(const Buffer& buffer, DeviceSize offset, IndexType indexType) const {
    vkCmdBindIndexBuffer(m_commandBuffer, buffer.handle(), offset, static_cast<VkIndexType>(indexType));
}

void CommandBuffer::bindPipeline(PipelineBindPoint pipelineBindPoint, const Pipeline& pipeline) const {
    vkCmdBindPipeline(m_commandBuffer, static_cast<VkPipelineBindPoint>(pipelineBindPoint), pipeline.handle());
}

void CommandBuffer::bindDescriptorSets(
    PipelineBindPoint pipelineBindPoint,
    const PipelineLayout& pipelineLayout,
    uint32_t firstSet,
    ArrayProxy<const std::reference_wrapper<const DescriptorSet>> descriptorSets,
    ArrayProxy<const uint32_t> dynamicOffsets) const
{
    std::vector<VkDescriptorSet> vkSets;
    vkSets.reserve(descriptorSets.size());
    for (const DescriptorSet& set : descriptorSets) {
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

void CommandBuffer::copyBuffer(const Buffer& src, const Buffer& dst, ArrayProxy<const BufferCopy> copy) {
    vkCmdCopyBuffer(m_commandBuffer, src.handle(), dst.handle(), static_cast<uint32_t>(copy.size()), copy.data());
}

void CommandBuffer::copyBufferToImage(const Buffer& src, const Image& dst, ImageLayout dstLayout, ArrayProxy<const BufferImageCopy> copies) {
    vkCmdCopyBufferToImage(m_commandBuffer, src.handle(), dst.handle(), static_cast<VkImageLayout>(dstLayout), copies.size(), reinterpret_cast<const VkBufferImageCopy*>(copies.data()));
}

void CommandBuffer::blitImage(const Image& srcImage, vk::ImageLayout srcImageLayout, const Image& dstImage, vk::ImageLayout dstImageLayout, ArrayProxy<const ImageBlit> regions, vk::Filter filter) {
    vkCmdBlitImage(m_commandBuffer, srcImage.handle(), static_cast<VkImageLayout>(srcImageLayout), dstImage.handle(), static_cast<VkImageLayout>(dstImageLayout), regions.size(), reinterpret_cast<const VkImageBlit*>(regions.data()), static_cast<VkFilter>(filter));
}

void CommandBuffer::pipelineBarrier(
    PipelineStageFlags srcStageMask,
    PipelineStageFlags dstStageMask,
    DependencyFlags dependencyFlags,
    ArrayProxy<const MemoryBarrier> memoryBarriers,
    ArrayProxy<const BufferMemoryBarrier> bufferMemoryBarriers,
    ArrayProxy<const ImageMemoryBarrier> imageMemoryBarriers) const
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

void CommandBuffer::pushConstants(const vk::PipelineLayout& pipelineLayout, vk::ShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* data) const {
    vkCmdPushConstants(m_commandBuffer, pipelineLayout.handle(), static_cast<VkShaderStageFlags>(stageFlags), offset, size, data);
}

void CommandBuffer::dispatch(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const {
    vkCmdDispatch(m_commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void CommandBuffer::setEvent(const Event& event, PipelineStageFlags stageMask) {
    vkCmdSetEvent(m_commandBuffer, event.handle(), static_cast<VkPipelineStageFlags>(stageMask));
}

void CommandBuffer::resetEvent(const Event& event, PipelineStageFlags stageMask) {
    vkCmdResetEvent(m_commandBuffer, event.handle(), static_cast<VkPipelineStageFlags>(stageMask));
}

void CommandBuffer::waitEvents(
    ArrayProxy<const std::reference_wrapper<Event>> events,
    PipelineStageFlags srcStageMask,
    PipelineStageFlags dstStageMask,
    ArrayProxy<const MemoryBarrier> memoryBarriers,
    ArrayProxy<const BufferMemoryBarrier> bufferMemoryBarriers,
    ArrayProxy<const ImageMemoryBarrier> imageMemoryBarriers) const
{
    std::vector<VkEvent> vkEvents;
    vkEvents.reserve(events.size());
    std::vector<VkMemoryBarrier> vkMemoryBarriers;
    vkMemoryBarriers.reserve(memoryBarriers.size());
    std::vector<VkBufferMemoryBarrier> vkBufferMemoryBarriers;
    vkBufferMemoryBarriers.reserve(bufferMemoryBarriers.size());
    std::vector<VkImageMemoryBarrier> vkImageMemoryBarriers;
    vkImageMemoryBarriers.reserve(imageMemoryBarriers.size());

    for (const Event& event : events) {
        vkEvents.push_back(event.handle());
    }

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

    vkCmdWaitEvents(m_commandBuffer, static_cast<uint32_t>(vkEvents.size()), vkEvents.data(),
        static_cast<VkPipelineStageFlags>(srcStageMask), static_cast<VkPipelineStageFlags>(dstStageMask),
        memoryBarriers.size(), vkMemoryBarriers.data(),
        bufferMemoryBarriers.size(), vkBufferMemoryBarriers.data(),
        imageMemoryBarriers.size(), vkImageMemoryBarriers.data());
}

void CommandBuffer::setViewport(uint32_t firstViewport, ArrayProxy<const Viewport> viewports) {
    vkCmdSetViewport(m_commandBuffer, firstViewport, viewports.size(), viewports.data());
}

void CommandBuffer::setScissor(uint32_t firstScissor, ArrayProxy<const Rect2D> scissors) {
    vkCmdSetScissor(m_commandBuffer, firstScissor, scissors.size(), scissors.data());
}