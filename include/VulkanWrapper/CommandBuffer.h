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

    class CommandBufferAllocateInfo : public CreateInfo<VkCommandBufferAllocateInfo> {
    public:
        const CommandPool* commandPool;
        CommandBufferLevel level;
        uint32_t commandBufferCount;

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
        CommandBuffer(CommandBuffer&& other) = default;

        VkCommandBuffer handle() const { return m_commandBuffer; }
        CommandPool& pool() const { return m_commandPool; }

        void begin(const CommandBufferBeginInfo& info) const;
        void end() const;

        void beginRenderPass(const RenderPassBeginInfo& info, SubpassContents contents) const;
        void endRenderPass() const;

    private:
        VkCommandBuffer m_commandBuffer;
        CommandPool& m_commandPool;
    };
}