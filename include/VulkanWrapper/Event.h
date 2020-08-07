#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class Device;

    class EventCreateInfo : public InfoMixin<EventCreateInfo, VkEventCreateInfo> {
    public:
        void marshal() const;
    };

    class Event {
    public:
        Event(Device& device, const EventCreateInfo& info);
        Event(const Event& other) = delete;
        Event& operator = (const Event& other) = delete;
        Event(Event&& other);
        Event& operator = (Event&& other);
        ~Event();

        VkEvent handle() const { return m_event; }
        Device& device() const { return *m_device; }

        Result getStatus() const;
        void reset();

    private:
        VkEvent m_event;
        Device* m_device;
        EventCreateInfo m_info;
    };
}