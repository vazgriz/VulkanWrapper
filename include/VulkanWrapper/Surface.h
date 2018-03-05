#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class Instance;
    class PhysicalDevice;

    struct SurfaceFormat {
        Format format;
        ColorSpaceKHR colorSpace;

        SurfaceFormat(VkSurfaceFormatKHR surfaceFormat);
    };

    struct SurfaceCapabilities {
        uint32_t minImageCount;
        uint32_t maxImageCount;
        VkExtent2D currentExtent;
        VkExtent2D minImageExtent;
        VkExtent2D maxImageExtent;
        uint32_t maxImageArrayLayers;
        SurfaceTransformFlagsKHR supportedTransforms;
        SurfaceTransformFlagsKHR currentTransform;
        CompositeAlphaFlagsKHR supportedCompositeAlpha;
        ImageUsageFlags supportedUsageFlags;

        SurfaceCapabilities(VkSurfaceCapabilitiesKHR capabilities);
    };

    class Surface {
    public:
        Surface(const Instance& instance, VkSurfaceKHR surface);

        VkSurfaceKHR handle() const { return m_surface; }
        const Instance& instance() const { return m_instance; }

        bool supported(const PhysicalDevice&, uint32_t queueFamilyIndex) const;
        std::vector<SurfaceFormat> getFormats(const PhysicalDevice& physicalDevice) const;
        std::vector<PresentModeKHR> getPresentModes(const PhysicalDevice& physicalDevice) const;
        SurfaceCapabilities getCapabilities(const PhysicalDevice& physicalDevice) const;

    private:
        VkSurfaceKHR m_surface;
        const Instance& m_instance;
    };
}