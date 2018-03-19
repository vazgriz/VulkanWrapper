#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class RenderPass;
    class Framebuffer;
    class CommandPool;
    class Pipeline;
    class Buffer;
    class Image;
    class PipelineLayout;
    class DescriptorSet;

    class CommandBufferAllocateInfo : public Info<VkCommandBufferAllocateInfo> {
    public:
        CommandPool* commandPool;
        CommandBufferLevel level;
        uint32_t commandBufferCount;

        void marshal() const;
    };

    class CommandBufferInheritanceInfo : public Info<VkCommandBufferInheritanceInfo> {
    public:
        const RenderPass* renderPass;
        uint32_t subpass;
        const Framebuffer* framebuffer;
        bool occlusionQueryEnable;
        QueryControlFlags queryFlags;
        QueryPipelineStatisticFlags pipelineStatistics;

        void marshal() const;
    };

    class CommandBufferBeginInfo : public Info<VkCommandBufferBeginInfo> {
    public:
        CommandBufferUsageFlags flags;
        const CommandBufferInheritanceInfo* inheritanceInfo;

        void marshal() const;
    };

    class RenderPassBeginInfo : public Info<VkRenderPassBeginInfo> {
    public:
        const RenderPass* renderPass;
        const Framebuffer* framebuffer;
        Rect2D renderArea;
        std::vector<ClearValue> clearValues;

        void marshal() const;
    };

    class MemoryBarrier : public Info<VkMemoryBarrier> {
    public:
        AccessFlags srcAccessMask;
        AccessFlags dstAccessMask;

        void marshal() const;
    };

    class BufferMemoryBarrier : public Info<VkBufferMemoryBarrier> {
    public:
        AccessFlags srcAccessMask;
        AccessFlags dstAccessMask;
        uint32_t srcQueueFamilyIndex;
        uint32_t dstQueueFamilyIndex;
        const Buffer* buffer;
        DeviceSize offset;
        DeviceSize size;

        void marshal() const;
    };

    class ImageMemoryBarrier : public Info<VkImageMemoryBarrier> {
    public:
        AccessFlags srcAccessMask;
        AccessFlags dstAccessMask;
        ImageLayout oldLayout;
        ImageLayout newLayout;
        uint32_t srcQueueFamilyIndex;
        uint32_t dstQueueFamilyIndex;
        const Image* image;
        ImageSubresourceRange subresourceRange;

        void marshal() const;
    };

    class CommandBuffer {
    public:
        CommandBuffer(CommandPool& commandPool, VkCommandBuffer commandBuffer);
        CommandBuffer(const CommandBuffer& other) = delete;
        CommandBuffer& operator = (const CommandBuffer& other) = delete;
        CommandBuffer(CommandBuffer&& other);
        ~CommandBuffer();

        VkCommandBuffer handle() const { return m_commandBuffer; }
        CommandPool& pool() const { return m_commandPool; }
        void setDestructorEnabled(bool value) { m_destructorEnabled = value; }

        void begin(const CommandBufferBeginInfo& info) const;
        void end() const;

        void beginRenderPass(const RenderPassBeginInfo& info, SubpassContents contents) const;
        void endRenderPass() const;

        void bindVertexBuffers(uint32_t firstBinding, ArrayProxy<const std::reference_wrapper<vk::Buffer>> buffers, ArrayProxy<const vk::DeviceSize> offsets) const;
        void bindIndexBuffer(vk::Buffer& buffer, vk::DeviceSize offset, vk::IndexType indexType) const;
        void bindPipeline(PipelineBindPoint pipelineBindPoint, const Pipeline& pipeline) const;
        void bindDescriptorSets(
            vk::PipelineBindPoint pipelineBindPoint,
            const vk::PipelineLayout& pipelineLayout,
            uint32_t firstSet,
            vk::ArrayProxy<const std::reference_wrapper<vk::DescriptorSet>> descriptorSets,
            vk::ArrayProxy<const uint32_t> dynamicOffsets) const;
        void draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const;
        void drawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, uint32_t vertexOffset, uint32_t firstInstance) const;

        void copyBuffer(Buffer& src, Buffer& dst, ArrayProxy<const BufferCopy> copy);
        void copyBufferToImage(Buffer& src, Image& dst, ImageLayout dstLayout, ArrayProxy<const BufferImageCopy> copies);

        void pipelineBarrier(
            PipelineStageFlags srcStageMask,
            PipelineStageFlags dstStageMask,
            DependencyFlags dependencyFlags,
            ArrayProxy<const MemoryBarrier> memoryBarriers,
            ArrayProxy<const BufferMemoryBarrier> bufferMemoryBarriers,
            ArrayProxy<const ImageMemoryBarrier> imageMemoryBarriers);

    private:
        VkCommandBuffer m_commandBuffer;
        CommandPool& m_commandPool;
        bool m_destructorEnabled;
    };
}