#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class Instance;
    class PhysicalDevice;

    struct SurfaceFormat {
        Format format;
        ColorSpace colorSpace;
    };

    struct SurfaceCapabilities {
        uint32_t minImageCount;
        uint32_t maxImageCount;
        VkExtent2D currentExtent;
        VkExtent2D minImageExtent;
        VkExtent2D maxImageExtent;
        uint32_t maxImageArrayLayers;
        SurfaceTransformFlags supportedTransforms;
        SurfaceTransformFlags currentTransform;
        CompositeAlphaFlags supportedCompositeAlpha;
        ImageUsageFlags supportedUsageFlags;

        SurfaceCapabilities(VkSurfaceCapabilitiesKHR capabilities);
    };

    class Surface {
    public:
        Surface(Instance& instance, VkSurfaceKHR surface);
        Surface(const Surface& other) = delete;
        Surface& operator = (const Surface& other) = delete;
        Surface(Surface&& other);
        Surface& operator = (Surface&& other);
        ~Surface();

        VkSurfaceKHR handle() const { return m_surface; }
        Instance& instance() const { return *m_instance; }

        bool supported(const PhysicalDevice&, uint32_t queueFamilyIndex) const;
        std::vector<SurfaceFormat> getFormats(const PhysicalDevice& physicalDevice) const;
        std::vector<PresentMode> getPresentModes(const PhysicalDevice& physicalDevice) const;
        SurfaceCapabilities getCapabilities(const PhysicalDevice& physicalDevice) const;

    private:
        VkSurfaceKHR m_surface;
        Instance* m_instance;
    };
}