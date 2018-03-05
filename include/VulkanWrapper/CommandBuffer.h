#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class CommandBufferAllocateInfo : public CreateInfo<VkCommandBufferAllocateInfo> {
    public:
        CommandPool& commandPool;
        CommandBufferLevel level;
        uint32_t commandBufferCount;

        void marshal() const;
    };

    class CommandBuffer {
    public:
        CommandBuffer(CommandPool& commandPool, VkCommandBuffer commandBuffer);

        VkCommandBuffer handle() const { return m_commandBuffer; }
        CommandPool& pool() const { return m_commandPool; }

    private:
        VkCommandBuffer m_commandBuffer;
        CommandPool& m_commandPool;
    };
}