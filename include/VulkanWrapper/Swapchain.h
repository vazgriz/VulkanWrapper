#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;
    class Swapchain;
    class Semaphore;
    class Fence;
    class Surface;
    class Image;

    class SwapchainCreateInfo : public InfoMixin<SwapchainCreateInfo, VkSwapchainCreateInfoKHR> {
    public:
        SwapchainCreateFlags flags;
        Surface* surface;
        uint32_t minImageCount;
        Format imageFormat;
        ColorSpace imageColorSpace;
        Extent2D imageExtent;
        uint32_t imageArrayLayers;
        ImageUsageFlags imageUsage;
        SharingMode imageSharingMode;
        std::vector<uint32_t> queueFamilyIndices;
        SurfaceTransformFlags preTransform;
        CompositeAlphaFlags compositeAlpha;
        PresentMode presentMode;
        bool clipped;
        const Swapchain* oldSwapchain;

        void marshal() const;
    };

    class Swapchain {
    public:
        Swapchain(Device& device, const SwapchainCreateInfo& info);
        Swapchain(const Swapchain& other) = delete;
        Swapchain& operator = (const Swapchain& other) = delete;
        Swapchain(Swapchain&& other);
        Swapchain& operator = (Swapchain&& other);
        ~Swapchain();

        VkSwapchainKHR handle() const { return m_swapchain; }
        Device& device() const { return *m_device; }
        Surface& surface() const { return *m_info.getInfo().surface; }

        Format format() const { return m_info.getInfo().imageFormat; }
        ColorSpace colorSpace() const { return m_info.getInfo().imageColorSpace; }
        Extent2D extent() const { return m_info.getInfo().imageExtent; }
        uint32_t arrayLayers() const { return m_info.getInfo().imageArrayLayers; }
        ImageUsageFlags usage() const { return m_info.getInfo().imageUsage; }
        SharingMode sharingMode() const { return m_info.getInfo().imageSharingMode; }
        const std::vector<uint32_t>& queueFamilyIndices() const { return m_info.getInfo().queueFamilyIndices; }
        SurfaceTransformFlags surfaceTransform() const { return m_info.getInfo().preTransform; }
        CompositeAlphaFlags compositeAlpha() const { return m_info.getInfo().compositeAlpha; }
        PresentMode presentMode() const { return m_info.getInfo().presentMode; }
        bool clipped() const { return m_info.getInfo().clipped; }
        std::vector<Image>& images() { return m_images; }

        vk::Result acquireNextImage(uint64_t timeout, const Semaphore* semaphore, const Fence* fence, uint32_t& index) const;

    private:
        void getImages();

        VkSwapchainKHR m_swapchain;
        Device* m_device;

        InfoChain<SwapchainCreateInfo> m_info;

        std::vector<Image> m_images;
    };
}