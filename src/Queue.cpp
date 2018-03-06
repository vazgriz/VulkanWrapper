#include "VulkanWrapper/VulkanWrapper.h"

void vk::SubmitInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = &next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_waitSemaphores.reserve(waitSemaphores.size());
    for (vk::Semaphore& semaphore : waitSemaphores) {
        m_waitSemaphores.push_back(semaphore.handle());
    }

    m_info.waitSemaphoreCount = static_cast<uint32_t>(waitSemaphores.size());
    m_info.pWaitSemaphores = m_waitSemaphores.data();
    m_info.pWaitDstStageMask = reinterpret_cast<const VkPipelineStageFlags*>(waitDstStageMask.data());

    m_commandBuffers.reserve(commandBuffers.size());
    for (vk::CommandBuffer& commandBuffer : commandBuffers) {
        m_commandBuffers.push_back(commandBuffer.handle());
    }

    m_info.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());
    m_info.pCommandBuffers = m_commandBuffers.data();

    m_signalSemaphores.reserve(signalSemaphores.size());
    for (vk::Semaphore& semaphore : signalSemaphores) {
        m_signalSemaphores.push_back(semaphore.handle());
    }

    m_info.signalSemaphoreCount = static_cast<uint32_t>(signalSemaphores.size());
    m_info.pSignalSemaphores = m_signalSemaphores.data();
}

void vk::PresentInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = &next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_waitSemaphores.reserve(waitSemaphores.size());
    for (vk::Semaphore& semaphore : waitSemaphores) {
        m_waitSemaphores.push_back(semaphore.handle());
    }

    m_info.waitSemaphoreCount = static_cast<uint32_t>(waitSemaphores.size());
    m_info.pWaitSemaphores = m_waitSemaphores.data();

    m_swapchains.reserve(swapchains.size());
    for (vk::Swapchain& swapchain : swapchains) {
        m_swapchains.push_back(swapchain.handle());
    }
    
    m_info.swapchainCount = static_cast<uint32_t>(swapchains.size());
    m_info.pSwapchains = m_swapchains.data();
    m_info.pImageIndices = imageIndices.data();

    m_results.resize(swapchains.size());

    m_info.pResults = m_results.data();
}

void vk::PresentInfo::unmarshal() {
    results.reserve(m_results.size());
    for (auto result : m_results) {
        results.push_back(static_cast<vk::Result>(result));
    }
}

vk::Queue::Queue(Device& device, VkQueue queue, uint32_t index) : m_device(device) {
    m_queue = queue;
    m_familyIndex = index;
}

void vk::Queue::submit(ArrayProxy<const SubmitInfo> infos, const Fence* fence) const {
    std::vector<VkSubmitInfo> vkInfos;
    vkInfos.reserve(infos.size());

    for (const SubmitInfo& info : infos) {
        info.marshal();
        vkInfos.push_back(info.info());
    }

    VKW_CHECK(vkQueueSubmit(m_queue, static_cast<uint32_t>(vkInfos.size()), vkInfos.data(), fence == nullptr ? VK_NULL_HANDLE : fence->handle()));
}

vk::Result vk::Queue::present(PresentInfo& info) const {
    info.marshal();
    VkResult result = vkQueuePresentKHR(m_queue, &info.info());
    if (result < 0) throw std::runtime_error(vk::toString(result));

    info.unmarshal();
    return static_cast<vk::Result>(result);
}