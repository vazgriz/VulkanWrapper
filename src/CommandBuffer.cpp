#include "VulkanWrapper/VulkanWrapper.h"

void vk::CommandBufferAllocateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    m_info.pNext = next == nullptr ? nullptr : &next->info();
    m_info.commandPool = commandPool.handle();
    m_info.commandBufferCount = commandBufferCount;
}

vk::CommandBuffer::CommandBuffer(CommandPool& commandPool, VkCommandBuffer commandBuffer) : m_commandPool(commandPool) {
    m_commandBuffer = commandBuffer;
}