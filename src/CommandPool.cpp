#include "VulkanWrapper/CommandPool.h"
#include "VulkanWrapper/CommandBuffer.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

void vk::CommandBufferAllocateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.commandPool = commandPool->handle();
    m_info.commandBufferCount = commandBufferCount;
    m_info.level = static_cast<VkCommandBufferLevel>(level);
}

void vk::CommandPoolCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkCommandPoolCreateFlags>(flags);
    m_info.queueFamilyIndex = queueFamilyIndex;
}

vk::CommandPool::CommandPool(Device& device, const CommandPoolCreateInfo& info) : m_device(device) {
    info.marshal();

    VKW_CHECK(vkCreateCommandPool(m_device.handle(), info.getInfo(), m_device.instance().callbacks(), &m_commandPool));

    m_queueFamilyIndex = info.queueFamilyIndex;
}

vk::CommandPool::CommandPool(vk::CommandPool&& other) : m_device(other.device()) {
    m_commandPool = other.m_commandPool;
    m_queueFamilyIndex = other.m_queueFamilyIndex;
    other.m_commandPool = VK_NULL_HANDLE;
}

vk::CommandPool::~CommandPool() {
    vkDestroyCommandPool(m_device.handle(), m_commandPool, m_device.instance().callbacks());
}

std::vector<vk::CommandBuffer> vk::CommandPool::allocate(const vk::CommandBufferAllocateInfo& info) {
    info.marshal();
    std::vector<VkCommandBuffer> commandBuffers(info.commandBufferCount);

    VKW_CHECK(vkAllocateCommandBuffers(info.commandPool->device().handle(), info.getInfo(), commandBuffers.data()));

    std::vector<vk::CommandBuffer> result;
    result.reserve(info.commandBufferCount);
    for (auto commandBuffer : commandBuffers) {
        result.emplace_back(*info.commandPool, commandBuffer);
    }

    return result;
}