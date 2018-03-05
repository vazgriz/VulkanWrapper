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
        Queue(const Device& device, VkQueue queue);

        VkQueue handle() const { return m_queue; }
    private:
        VkQueue m_queue;
        const Device& m_device;
    };
}