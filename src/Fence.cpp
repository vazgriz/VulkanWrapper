#include "VulkanWrapper/Fence.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

void vk::FenceCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkFenceCreateFlags>(flags);
}

vk::Fence::Fence(Device& device, const FenceCreateInfo& info) : m_device(device) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateFence(m_device.handle(), m_info.getInfo(), m_device.instance().callbacks(), &m_fence));
}

vk::Fence::~Fence() {
    vkDestroyFence(m_device.handle(), m_fence, m_device.instance().callbacks());
}

vk::Fence::Fence(Fence&& other) : m_device(other.device()) {
    m_fence = other.m_fence;
    m_info = std::move(other.m_info);
    other.m_fence = VK_NULL_HANDLE;
}

VkResult vk::Fence::wait(uint64_t timeout) const {
    return vkWaitForFences(m_device.handle(), 1, &m_fence, VK_TRUE, timeout);
}

VkResult vk::Fence::wait(const Device& device, ArrayProxy<const Fence> fences, bool waitAll, uint64_t timeout) {
    std::vector<VkFence> vkFences;
    vkFences.reserve(fences.size());

    for (const vk::Fence& fence : fences) {
        vkFences.push_back(fence.handle());
    }

    return vkWaitForFences(device.handle(), static_cast<uint32_t>(vkFences.size()), vkFences.data(), waitAll, timeout);
}

void vk::Fence::reset() {
    VKW_CHECK(vkResetFences(m_device.handle(), 1, &m_fence));
}

void vk::Fence::reset(const Device& device, ArrayProxy<Fence> fences) {
    std::vector<VkFence> vkFences;
    vkFences.reserve(fences.size());

    for (const vk::Fence& fence : fences) {
        vkFences.push_back(fence.handle());
    }

    VKW_CHECK(vkResetFences(device.handle(), static_cast<uint32_t>(vkFences.size()), vkFences.data()));
}