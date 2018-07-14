#include "VulkanWrapper/CommandPool.h"
#include "VulkanWrapper/CommandBuffer.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

void CommandBufferAllocateInfo::marshal() const {
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

void CommandPoolCreateInfo::marshal() const {
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

CommandPool::CommandPool(Device& device, const CommandPoolCreateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateCommandPool(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_commandPool));
    m_device = &device;
}

CommandPool::CommandPool(CommandPool&& other) {
    m_device = other.m_device;
    m_commandPool = other.m_commandPool;
    m_info = std::move(other.m_info);
    other.m_commandPool = VK_NULL_HANDLE;
}

CommandPool& CommandPool::operator = (CommandPool&& other) {
    vkDestroyCommandPool(m_device->handle(), m_commandPool, device().instance().callbacks());
    m_device = other.m_device;
    m_commandPool = other.m_commandPool;
    m_info = std::move(other.m_info);
    other.m_commandPool = VK_NULL_HANDLE;
    return *this;
}

CommandPool::~CommandPool() {
    vkDestroyCommandPool(m_device->handle(), m_commandPool, device().instance().callbacks());
}

std::vector<CommandBuffer> CommandPool::allocate(const CommandBufferAllocateInfo& info) {
    info.marshal();
    std::vector<VkCommandBuffer> commandBuffers(info.commandBufferCount);

    VKW_CHECK(vkAllocateCommandBuffers(info.commandPool->device().handle(), info.getInfo(), commandBuffers.data()));

    std::vector<CommandBuffer> result;
    result.reserve(info.commandBufferCount);
    for (auto commandBuffer : commandBuffers) {
        result.emplace_back(*info.commandPool, commandBuffer, info);
    }

    return result;
}