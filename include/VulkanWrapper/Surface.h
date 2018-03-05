#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class Instance;
    class PhysicalDevice;

    class Surface {
    public:
        Surface(const Instance& instance, VkSurfaceKHR surface);

        VkSurfaceKHR handle() const { return m_surface; }
        const Instance& instance() const { return m_instance; }

    private:
        VkSurfaceKHR m_surface;
        const Instance& m_instance;
    };
}