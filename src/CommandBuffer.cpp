#include "VulkanWrapper/VulkanWrapper.h"

void vk::CommandBufferAllocateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = &next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.commandPool = commandPool.handle();
    m_info.commandBufferCount = commandBufferCount;
    m_info.level = static_cast<VkCommandBufferLevel>(level);
}

vk::CommandBuffer::CommandBuffer(CommandPool& commandPool, VkCommandBuffer commandBuffer) : m_commandPool(commandPool) {
    m_commandBuffer = commandBuffer;
}