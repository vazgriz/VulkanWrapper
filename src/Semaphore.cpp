#include "VulkanWrapper/Semaphore.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

void SemaphoreCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = 0;
}

void SemaphoreTypeCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    }
    else {
        m_info.pNext = nullptr;
    }

    m_info.semaphoreType = static_cast<VkSemaphoreType>(semaphoreType);
    m_info.initialValue = initialValue;
}

void TimelineSemaphoreSubmitInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    }
    else {
        m_info.pNext = nullptr;
    }

    m_info.waitSemaphoreValueCount = static_cast<uint32_t>(waitSemaphoreValues.size());
    m_info.pWaitSemaphoreValues = waitSemaphoreValues.data();
    m_info.signalSemaphoreValueCount = static_cast<uint32_t>(signalSemaphoreValues.size());
    m_info.pSignalSemaphoreValues = signalSemaphoreValues.data();
}

void SemaphoreWaitInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkSemaphoreWaitFlags>(flags);
    m_info.semaphoreCount = static_cast<uint32_t>(semaphores.size());

    m_semaphores.clear();
    for (Semaphore& semaphore : semaphores) {
        m_semaphores.push_back(semaphore.handle());
    }

    m_info.pSemaphores = m_semaphores.data();
    m_info.pValues = values.data();
}

void SemaphoreSignalInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.semaphore = semaphore->handle();
    m_info.value = value;
}

Semaphore::Semaphore(Device& device, const SemaphoreCreateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateSemaphore(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_sempahore));
    m_device = &device;
}

Semaphore::Semaphore(Semaphore&& other) {
    m_device = other.m_device;
    m_sempahore = other.m_sempahore;
    m_info = std::move(other.m_info);
    other.m_sempahore = VK_NULL_HANDLE;
}

Semaphore& Semaphore::operator = (Semaphore&& other) {
    vkDestroySemaphore(m_device->handle(), m_sempahore, device().instance().callbacks());
    m_device = other.m_device;
    m_sempahore = other.m_sempahore;
    m_info = std::move(other.m_info);
    other.m_sempahore = VK_NULL_HANDLE;
    return *this;
}

Semaphore::~Semaphore() {
    vkDestroySemaphore(m_device->handle(), m_sempahore, device().instance().callbacks());
}

vk::Result Semaphore::wait(vk::Device& device, vk::SemaphoreWaitInfo& info, uint64_t timeout) {
    info.marshal();

    VkResult result = vkWaitSemaphores(device.handle(), info.getInfo(), timeout);
    return static_cast<vk::Result>(result);
}

void Semaphore::signal(vk::Device& device, vk::SemaphoreSignalInfo& info) {
    info.marshal();

    VKW_CHECK(vkSignalSemaphore(device.handle(), info.getInfo()));
}