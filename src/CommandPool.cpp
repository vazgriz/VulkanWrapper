#include "VulkanWrapper/VulkanWrapper.h"

void vk::CommandPoolCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = &next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkCommandPoolCreateFlags>(flags);
    m_info.queueFamilyIndex = queueFamilyIndex;
}

vk::CommandPool::CommandPool(Device& device, const CommandPoolCreateInfo& info) : m_device(device) {
    info.marshal();

    VKW_CHECK(vkCreateCommandPool(m_device.handle(), &info.info(), m_device.instance().callbacks(), &m_commandPool));

    m_queueFamilyIndex = info.queueFamilyIndex;
}

vk::CommandPool::~CommandPool() {
    vkDestroyCommandPool(m_device.handle(), m_commandPool, m_device.instance().callbacks());
}

std::vector<vk::CommandBuffer> vk::CommandPool::allocate(const vk::CommandBufferAllocateInfo& info) {
    info.marshal();
    std::vector<VkCommandBuffer> commandBuffers(info.commandBufferCount);

    VKW_CHECK(vkAllocateCommandBuffers(m_device.handle(), &info.info(), commandBuffers.data()));

    std::vector<vk::CommandBuffer> result;
    result.reserve(info.commandBufferCount);
    for (auto commandBuffer : commandBuffers) {
        result.emplace_back(*this, commandBuffer);
    }

    return result;
}