#include "VulkanWrapper/Event.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

void EventCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }
}

Event::Event(Device& device, const EventCreateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateEvent(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_event));
    m_device = &device;
}

Event::Event(Event&& other) {
    m_device = other.m_device;
    m_event = other.m_event;
    m_info = std::move(other.m_info);
    other.m_event = VK_NULL_HANDLE;
}

Event& Event::operator = (Event&& other) {
    vkDestroyEvent(m_device->handle(), m_event, device().instance().callbacks());
    m_device = other.m_device;
    m_event = other.m_event;
    m_info = std::move(other.m_info);
    other.m_event = VK_NULL_HANDLE;
    return *this;
}

Event::~Event() {
    vkDestroyEvent(m_device->handle(), m_event, device().instance().callbacks());
}

Result Event::getStatus() const {
    VkResult result = vkGetEventStatus(m_device->handle(), m_event);
    if (result == VK_EVENT_SET || result == VK_EVENT_RESET) {
        return static_cast<Result>(result);
    } else {
        throw std::runtime_error(toString(result));
    }
}

void Event::reset() {
    VKW_CHECK(vkResetEvent(m_device->handle(), m_event));
}