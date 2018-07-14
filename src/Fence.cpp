#include "VulkanWrapper/Fence.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

void FenceCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkFenceCreateFlags>(flags);
}

Fence::Fence(Device& device, const FenceCreateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateFence(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_fence));
    m_device = &device;
}

Fence::~Fence() {
    vkDestroyFence(m_device->handle(), m_fence, device().instance().callbacks());
}

Fence::Fence(Fence&& other) {
    m_device = other.m_device;
    m_fence = other.m_fence;
    m_info = std::move(other.m_info);
    other.m_fence = VK_NULL_HANDLE;
}

Fence& Fence::operator = (Fence&& other) {
    vkDestroyFence(m_device->handle(), m_fence, device().instance().callbacks());
    m_device = other.m_device;
    m_fence = other.m_fence;
    m_info = std::move(other.m_info);
    other.m_fence = VK_NULL_HANDLE;
    return *this;
}

VkResult Fence::wait(uint64_t timeout) const {
    return vkWaitForFences(m_device->handle(), 1, &m_fence, VK_TRUE, timeout);
}

VkResult Fence::wait(const Device& device, ArrayProxy<const Fence> fences, bool waitAll, uint64_t timeout) {
    std::vector<VkFence> vkFences;
    vkFences.reserve(fences.size());

    for (const Fence& fence : fences) {
        vkFences.push_back(fence.handle());
    }

    return vkWaitForFences(device.handle(), static_cast<uint32_t>(vkFences.size()), vkFences.data(), waitAll, timeout);
}

void Fence::reset() {
    VKW_CHECK(vkResetFences(m_device->handle(), 1, &m_fence));
}

void Fence::reset(const Device& device, ArrayProxy<Fence> fences) {
    std::vector<VkFence> vkFences;
    vkFences.reserve(fences.size());

    for (const Fence& fence : fences) {
        vkFences.push_back(fence.handle());
    }

    VKW_CHECK(vkResetFences(device.handle(), static_cast<uint32_t>(vkFences.size()), vkFences.data()));
}