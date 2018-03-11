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

    class SwapchainCreateInfo : public Info<VkSwapchainCreateInfoKHR> {
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
        ~Swapchain();

        VkSwapchainKHR handle() const { return m_swapchain; }
        Device& device() const { return m_device; }
        Surface& surface() const { return m_surface; }

        Format format() const { return m_format; }
        ColorSpace colorSpace() const { return m_colorSpace; }
        Extent2D extent() const { return m_extent; }
        uint32_t arrayLayers() const { return m_layers; }
        ImageUsageFlags usage() const { return m_usage; }
        SharingMode sharingMode() const { return m_sharingMode; }
        const std::vector<uint32_t>& queueFamilyIndices() const { return m_queueFamilyIndices; }
        SurfaceTransformFlags surfaceTransform() const { return m_preTransform; }
        CompositeAlphaFlags compositeAlpha() const { return m_compositeAlpha; }
        PresentMode presentMode() const { return m_presentMode; }
        bool clipped() const { return m_clipped; }
        const std::vector<Image>& images() const { return m_images; }

        uint32_t acquireNextImage(uint64_t timeout, const Semaphore* semaphore, const Fence* fence) const;

    private:
        void getImages();

        VkSwapchainKHR m_swapchain;
        Device& m_device;
        Surface& m_surface;
        Format m_format;
        ColorSpace m_colorSpace;
        Extent2D m_extent;
        uint32_t m_layers;
        ImageUsageFlags m_usage;
        SharingMode m_sharingMode;
        std::vector<uint32_t> m_queueFamilyIndices;
        SurfaceTransformFlags m_preTransform;
        CompositeAlphaFlags m_compositeAlpha;
        PresentMode m_presentMode;
        bool m_clipped;

        std::vector<Image> m_images;
    };
}