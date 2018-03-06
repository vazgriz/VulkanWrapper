#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class RenderPass;
    class Framebuffer;

    class CommandBufferAllocateInfo : public CreateInfo<VkCommandBufferAllocateInfo> {
    public:
        const CommandPool& commandPool;
        CommandBufferLevel level;
        uint32_t commandBufferCount;

        CommandBufferAllocateInfo(const CommandPool& commandPool) : commandPool(commandPool) {}
        void marshal() const;
    };

    class CommandBufferInheritanceInfo : public CreateInfo<VkCommandBufferInheritanceInfo> {
    public:
        const RenderPass& renderPass;
        uint32_t subpass;
        const Framebuffer& framebuffer;
        bool occlusionQueryEnable;
        QueryControlFlags queryFlags;
        QueryPipelineStatisticFlags pipelineStatistics;

        CommandBufferInheritanceInfo(const RenderPass& renderPass, const Framebuffer& framebuffer) : renderPass(renderPass), framebuffer(framebuffer) { }
        void marshal() const;
    };

    class CommandBufferBeginInfo : public CreateInfo<VkCommandBufferBeginInfo> {
    public:
        CommandBufferUsageFlags flags;
        const CommandBufferInheritanceInfo* inheritanceInfo;

        void marshal() const;
    };

    class CommandBuffer {
    public:
        CommandBuffer(CommandPool& commandPool, VkCommandBuffer commandBuffer);

        VkCommandBuffer handle() const { return m_commandBuffer; }
        CommandPool& pool() const { return m_commandPool; }

        void begin(const CommandBufferBeginInfo& info) const;
        void end() const;

    private:
        VkCommandBuffer m_commandBuffer;
        CommandPool& m_commandPool;
    };
}