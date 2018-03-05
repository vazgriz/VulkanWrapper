#include "VulkanWrapper/VulkanWrapper.h"

void vk::SemaphoreCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
    m_info.pNext = next == nullptr ? nullptr : &next->info();
    m_info.flags = 0;
}

vk::Semaphore::Semaphore(Device& device, const SemaphoreCreateInfo& info) : m_device(device) {
    info.marshal();

    VKW_CHECK(vkCreateSemaphore(device.handle(), &info.info(), device.instance().callbacks(), &m_sempahore));
}

vk::Semaphore::~Semaphore() {
    vkDestroySemaphore(m_device.handle(), m_sempahore, m_device.instance().callbacks());
}