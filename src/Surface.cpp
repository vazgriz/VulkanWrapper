#include "VulkanWrapper/Surface.h"
#include "VulkanWrapper/PhysicalDevice.h"

vk::SurfaceFormat::SurfaceFormat(VkSurfaceFormatKHR surfaceFormat) {
    colorSpace = static_cast<ColorSpaceKHR>(surfaceFormat.colorSpace);
    format = static_cast<Format>(surfaceFormat.format);
}

vk::SurfaceCapabilities::SurfaceCapabilities(VkSurfaceCapabilitiesKHR capabilities) {
   minImageCount = capabilities.minImageCount;
   maxImageCount = capabilities.maxImageCount;
   currentExtent = capabilities.currentExtent;
   minImageExtent = capabilities.minImageExtent;
   maxImageExtent = capabilities.maxImageExtent;
   maxImageArrayLayers = capabilities.maxImageArrayLayers;
   supportedTransforms = static_cast<vk::SurfaceTransformFlagsKHR>(capabilities.supportedTransforms);
   currentTransform = static_cast<vk::SurfaceTransformFlagsKHR>(capabilities.currentTransform);
   supportedCompositeAlpha = static_cast<vk::CompositeAlphaFlagsKHR>(capabilities.supportedCompositeAlpha);
   supportedUsageFlags = static_cast<vk::ImageUsageFlags>(capabilities.supportedUsageFlags);
}

vk::Surface::Surface(const vk::Instance& instance, VkSurfaceKHR surface) : m_instance(instance) {
    m_surface = surface;
}

bool vk::Surface::supported(const vk::PhysicalDevice& physicalDevice, uint32_t queueFamilyIndex) const {
    VkBool32 result;
    vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice.handle(), queueFamilyIndex, m_surface, &result);
    return result == VK_TRUE;
}

std::vector<vk::SurfaceFormat> vk::Surface::getFormats(const vk::PhysicalDevice& physicalDevice) const {
    uint32_t count;
    vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice.handle(), m_surface, &count, nullptr);
    std::vector<VkSurfaceFormatKHR> formats(count);
    vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice.handle(), m_surface, &count, formats.data());

    std::vector<SurfaceFormat> result;
    result.reserve(count);
    for (auto& format : formats) {
        result.emplace_back(format);
    }

    return result;
}

std::vector<vk::PresentModeKHR> vk::Surface::getPresentModes(const vk::PhysicalDevice& physicalDevice) const {
    uint32_t count;
    vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice.handle(), m_surface, &count, nullptr);
    std::vector<VkPresentModeKHR> modes(count);
    vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice.handle(), m_surface, &count, modes.data());

    std::vector<PresentModeKHR> result;
    for (auto mode : modes) {
        result.push_back(static_cast<PresentModeKHR>(mode));
    }

    return result;
}

vk::SurfaceCapabilities vk::Surface::getCapabilities(const vk::PhysicalDevice& physicalDevice) const {
    VkSurfaceCapabilitiesKHR capabilities;
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice.handle(), m_surface, &capabilities);

    return vk::SurfaceCapabilities(capabilities);
}