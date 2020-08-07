#include "VulkanWrapper/Swapchain.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"
#include "VulkanWrapper/Surface.h"
#include "VulkanWrapper/Semaphore.h"
#include "VulkanWrapper/Fence.h"
#include "VulkanWrapper/Image.h"

using namespace vk;

void SwapchainCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkSwapchainCreateFlagsKHR>(flags);
    m_info.surface = surface->handle();
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

Swapchain::Swapchain(Device& device, const SwapchainCreateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateSwapchainKHR(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_swapchain));
    m_device = &device;

    getImages();
}

Swapchain::Swapchain(Swapchain&& other) {
    m_device = other.m_device;
    m_swapchain = other.m_swapchain;
    m_info = std::move(other.m_info);
    m_images = std::move(other.m_images);
    other.m_swapchain = VK_NULL_HANDLE;
}

Swapchain& Swapchain::operator = (Swapchain&& other) {
    vkDestroySwapchainKHR(m_device->handle(), m_swapchain, device().instance().callbacks());
    m_device = other.m_device;
    m_swapchain = other.m_swapchain;
    m_info = std::move(other.m_info);
    m_images = std::move(other.m_images);
    other.m_swapchain = VK_NULL_HANDLE;
    return *this;
}

Swapchain::~Swapchain() {
    vkDestroySwapchainKHR(m_device->handle(), m_swapchain, device().instance().callbacks());
}

vk::Result Swapchain::acquireNextImage(uint64_t timeout, const Semaphore* semaphore, const Fence* fence, uint32_t& index) const {
    VkSemaphore vkSemaphore = semaphore == nullptr ? VK_NULL_HANDLE : semaphore->handle();
    VkFence vkFence = fence == nullptr ? VK_NULL_HANDLE : fence->handle();
    VkResult result = vkAcquireNextImageKHR(m_device->handle(), m_swapchain, timeout, vkSemaphore, vkFence, &index);

    if (result < 0) {
        throw std::runtime_error(vk::toString(result));
    } else {
        return static_cast<vk::Result>(result);
    }
}

void Swapchain::getImages() {
    uint32_t count;
    vkGetSwapchainImagesKHR(m_device->handle(), m_swapchain, &count, nullptr);
    std::vector<VkImage> images(count);
    vkGetSwapchainImagesKHR(m_device->handle(), m_swapchain, &count, images.data());
    
    ImageCreateInfo info = {};
    info.format = format();
    info.extent = { extent().width, extent().height };
    info.arrayLayers = arrayLayers();
    info.usage = usage();
    info.sharingMode = sharingMode();
    info.queueFamilyIndices = queueFamilyIndices();
    info.imageType = ImageType::_2D;
    info.mipLevels = 1;
    info.samples = SampleCountFlags::_1;
    info.tiling = ImageTiling::Optimal;

    m_images.reserve(images.size());
    for (auto image : images) {
        m_images.emplace_back(device(), image, false, &info);
    }
}