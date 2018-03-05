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
        Queue(Device& device, VkQueue queue);

        VkQueue handle() const { return m_queue; }
        Device& device() const { return m_device; }
    private:
        VkQueue m_queue;
        Device& m_device;
    };
}