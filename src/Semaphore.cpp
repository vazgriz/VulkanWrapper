#include "VulkanWrapper/Semaphore.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

void vk::SemaphoreCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = 0;
}

vk::Semaphore::Semaphore(Device& device, const SemaphoreCreateInfo& info) : m_device(device) {
    info.marshal();

    VKW_CHECK(vkCreateSemaphore(device.handle(), info.getInfo(), device.instance().callbacks(), &m_sempahore));
}

vk::Semaphore::Semaphore(vk::Semaphore&& other) : m_device(other.device()) {
    m_sempahore = other.m_sempahore;
    other.m_sempahore = VK_NULL_HANDLE;
}

vk::Semaphore::~Semaphore() {
    vkDestroySemaphore(m_device.handle(), m_sempahore, m_device.instance().callbacks());
}