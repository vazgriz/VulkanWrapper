#include "VulkanWrapper/Surface.h"

vk::Surface::Surface(const vk::Instance& instance, VkSurfaceKHR surface) : m_instance(instance) {
    m_surface = surface;
}