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

Semaphore::Semaphore(Device& device, const SemaphoreCreateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateSemaphore(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_sempahore));
    m_device = device.handle();
    m_deviceRef = &device;
}

Semaphore::Semaphore(Semaphore&& other) {
    m_device = other.m_device;
    m_deviceRef = other.m_deviceRef;
    m_sempahore = other.m_sempahore;
    m_info = std::move(other.m_info);
    other.m_sempahore = VK_NULL_HANDLE;
}

Semaphore::~Semaphore() {
    vkDestroySemaphore(m_device, m_sempahore, device().instance().callbacks());
}