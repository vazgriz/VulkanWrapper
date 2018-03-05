#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class Device;

    class Queue {
    public:
        Queue(Device& device, VkQueue queue, uint32_t index);

        VkQueue handle() const { return m_queue; }
        Device& device() const { return m_device; }

        uint32_t familyIndex() const { return m_familyIndex; }

    private:
        VkQueue m_queue;
        Device& m_device;
        uint32_t m_familyIndex;
    };
}