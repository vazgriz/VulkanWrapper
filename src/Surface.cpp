#include "VulkanWrapper/Surface.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

SurfaceCapabilities::SurfaceCapabilities(VkSurfaceCapabilitiesKHR capabilities) {
   minImageCount = capabilities.minImageCount;
   maxImageCount = capabilities.maxImageCount;
   currentExtent = capabilities.currentExtent;
   minImageExtent = capabilities.minImageExtent;
   maxImageExtent = capabilities.maxImageExtent;
   maxImageArrayLayers = capabilities.maxImageArrayLayers;
   supportedTransforms = static_cast<SurfaceTransformFlags>(capabilities.supportedTransforms);
   currentTransform = static_cast<SurfaceTransformFlags>(capabilities.currentTransform);
   supportedCompositeAlpha = static_cast<CompositeAlphaFlags>(capabilities.supportedCompositeAlpha);
   supportedUsageFlags = static_cast<ImageUsageFlags>(capabilities.supportedUsageFlags);
}

Surface::Surface(Instance& instance, VkSurfaceKHR surface) {
    m_surface = surface;
    m_instance = &instance;
}

Surface::Surface(Surface&& other) {
    m_surface = other.m_surface;
    m_instance = other.m_instance;
    other.m_surface = VK_NULL_HANDLE;
}

Surface& Surface::operator = (Surface&& other) {
    vkDestroySurfaceKHR(m_instance->handle(), m_surface, m_instance->callbacks());
    m_surface = other.m_surface;
    m_instance = other.m_instance;
    other.m_surface = VK_NULL_HANDLE;
    return *this;
}

Surface::~Surface() {
    vkDestroySurfaceKHR(m_instance->handle(), m_surface, m_instance->callbacks());
}

bool Surface::supported(const PhysicalDevice& physicalDevice, uint32_t queueFamilyIndex) const {
    VkBool32 result;
    vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice.handle(), queueFamilyIndex, m_surface, &result);
    return result == VK_TRUE;
}

std::vector<SurfaceFormat> Surface::getFormats(const PhysicalDevice& physicalDevice) const {
    uint32_t count;
    vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice.handle(), m_surface, &count, nullptr);
    std::vector<VkSurfaceFormatKHR> formats(count);
    vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice.handle(), m_surface, &count, formats.data());

    std::vector<SurfaceFormat> result;
    result.reserve(count);
    for (auto& format : formats) {
        result.push_back({ static_cast<Format>(format.format), static_cast<ColorSpace>(format.colorSpace) });
    }

    return result;
}

std::vector<PresentMode> Surface::getPresentModes(const PhysicalDevice& physicalDevice) const {
    uint32_t count;
    vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice.handle(), m_surface, &count, nullptr);
    std::vector<VkPresentModeKHR> modes(count);
    vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice.handle(), m_surface, &count, modes.data());

    std::vector<PresentMode> result;
    for (auto mode : modes) {
        result.push_back(static_cast<PresentMode>(mode));
    }

    return result;
}

SurfaceCapabilities Surface::getCapabilities(const PhysicalDevice& physicalDevice) const {
    VkSurfaceCapabilitiesKHR capabilities;
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice.handle(), m_surface, &capabilities);

    return SurfaceCapabilities(capabilities);
}