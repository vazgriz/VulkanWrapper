#pragma once
#include <vulkan/vulkan.h>

namespace vk {
    typedef VkDeviceSize DeviceSize;
    typedef VkPhysicalDeviceFeatures PhysicalDeviceFeatures;
    typedef VkExtent3D Extent3D;
    typedef VkPhysicalDeviceLimits PhysicalDeviceLimits;
    typedef VkPhysicalDeviceSparseProperties PhysicalDeviceSparseProperties;
    typedef VkMemoryRequirements MemoryRequirements;
    typedef VkOffset3D Offset3D;
    typedef VkSubresourceLayout SubresourceLayout;
    typedef VkSpecializationMapEntry SpecializationMapEntry;
    typedef VkViewport Viewport;
    typedef VkOffset2D Offset2D;
    typedef VkExtent2D Extent2D;
    typedef VkRect2D Rect2D;
    typedef VkBufferCopy BufferCopy;
    typedef VkClearColorValue ClearColorValue;
    typedef VkClearDepthStencilValue ClearDepthStencilValue;
    typedef VkClearValue ClearValue;
    typedef VkClearRect ClearRect;
    typedef VkDispatchIndirectCommand DispatchIndirectCommand;
    typedef VkDrawIndexedIndirectCommand DrawIndexedIndirectCommand;
    typedef VkDrawIndirectCommand DrawIndirectCommand;
    typedef VkDisplayModeParametersKHR DisplayModeParameters;

    struct ComponentMapping {
        ComponentSwizzle r;
        ComponentSwizzle g;
        ComponentSwizzle b;
        ComponentSwizzle a;
    };

    struct ImageSubresourceRange {
        ImageAspectFlags aspectMask;
        uint32_t baseMipLevel;
        uint32_t levelCount;
        uint32_t baseArrayLayer;
        uint32_t layerCount;
    };
}