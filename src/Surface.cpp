#include "VulkanWrapper/Surface.h"
#include "VulkanWrapper/PhysicalDevice.h"

vk::Surface::Surface(const vk::Instance& instance, VkSurfaceKHR surface) : m_instance(instance) {
    m_surface = surface;
}

bool vk::Surface::supported(const vk::PhysicalDevice& physicalDevice, uint32_t queueFamilyIndex) const {
    VkBool32 result;
    vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice.handle(), queueFamilyIndex, m_surface, &result);
    return result == VK_TRUE;
}