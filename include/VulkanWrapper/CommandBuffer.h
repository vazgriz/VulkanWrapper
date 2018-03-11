#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
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

    class CommandBufferAllocateInfo : public CreateInfo<VkCommandBufferAllocateInfo> {
    public:
        const CommandPool* commandPool;
        CommandBufferLevel level;
        size_t commandBufferCount;

        void marshal() const;
    };

    class CommandBufferInheritanceInfo : public CreateInfo<VkCommandBufferInheritanceInfo> {
    public:
        const RenderPass* renderPass;
        uint32_t subpass;
        const Framebuffer* framebuffer;
        bool occlusionQueryEnable;
        QueryControlFlags queryFlags;
        QueryPipelineStatisticFlags pipelineStatistics;

        void marshal() const;
    };

    class CommandBufferBeginInfo : public CreateInfo<VkCommandBufferBeginInfo> {
    public:
        CommandBufferUsageFlags flags;
        const CommandBufferInheritanceInfo* inheritanceInfo;

        void marshal() const;
    };

    class RenderPassBeginInfo : public CreateInfo<VkRenderPassBeginInfo> {
    public:
        const RenderPass* renderPass;
        const Framebuffer* framebuffer;
        Rect2D renderArea;
        std::vector<ClearValue> clearValues;

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
        void draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const;

        void copy(Buffer& src, Buffer& dst, ArrayProxy<const BufferCopy> copy);

    private:
        VkCommandBuffer m_commandBuffer;
        CommandPool& m_commandPool;
        bool m_destructorEnabled;
    };
}