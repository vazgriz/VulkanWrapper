#include "VulkanWrapper/VulkanWrapper.h"

void vk::SwapchainCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    m_info.pNext = next == nullptr ? nullptr : &next->info();
    m_info.flags = static_cast<VkSwapchainCreateFlagsKHR>(flags);
    m_info.surface = surface.handle();
    m_info.minImageCount = minImageCount;
    m_info.imageFormat = static_cast<VkFormat>(imageFormat);
    m_info.imageColorSpace = static_cast<VkColorSpaceKHR>(imageColorSpace);
    m_info.imageExtent = imageExtent;
    m_info.imageArrayLayers = imageArrayLayers;
    m_info.imageUsage = static_cast<VkImageUsageFlags>(imageUsage);
    m_info.imageSharingMode = static_cast<VkSharingMode>(imageSharingMode);
    m_info.queueFamilyIndexCount = static_cast<uint32_t>(queueFamilyIndices.size());
    m_info.pQueueFamilyIndices = queueFamilyIndices.data();
    m_info.preTransform = static_cast<VkSurfaceTransformFlagBitsKHR>(preTransform);
    m_info.compositeAlpha = static_cast<VkCompositeAlphaFlagBitsKHR>(compositeAlpha);
    m_info.presentMode = static_cast<VkPresentModeKHR>(presentMode);
    m_info.clipped = clipped;

    if (oldSwapchain == nullptr) {
        m_info.oldSwapchain = VK_NULL_HANDLE;
    } else {
        m_info.oldSwapchain = oldSwapchain->handle();
    }
}

vk::Swapchain::Swapchain(Device& device, const SwapchainCreateInfo& info) : m_device(device), m_surface(info.surface) {
    info.marshal();

    VKW_CHECK(vkCreateSwapchainKHR(device.handle(), &info.info(), device.instance().callbacks(), &m_swapchain));

    m_format = info.imageFormat;
    m_colorSpace = info.imageColorSpace;
    m_extent = info.imageExtent;
    m_layers = info.imageArrayLayers;
    m_usage = info.imageUsage;
    m_sharingMode = info.imageSharingMode;
    m_queueFamilyIndices = info.queueFamilyIndices;
    m_preTransform = info.preTransform;
    m_compositeAlpha = info.compositeAlpha;
    m_presentMode = info.presentMode;
    m_clipped = info.clipped;
}

vk::Swapchain::~Swapchain() {
    vkDestroySwapchainKHR(m_device.handle(), m_swapchain, m_device.instance().callbacks());
}