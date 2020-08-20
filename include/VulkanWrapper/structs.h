#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/enums.h"

namespace vk {
    typedef VkDeviceSize DeviceSize;
    typedef VkPhysicalDeviceFeatures PhysicalDeviceFeatures;
    typedef VkPhysicalDeviceVulkan11Features PhysicalDeviceVulkan11Features;
    typedef VkPhysicalDeviceVulkan12Features PhysicalDeviceVulkan12Features;
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
    typedef VkSampleMask SampleMask;

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

    struct PushConstantRange {
        ShaderStageFlags stageFlags;
        uint32_t offset;
        uint32_t size;
    };

    struct VertexInputBindingDescription {
        uint32_t             binding;
        uint32_t             stride;
        VertexInputRate    inputRate;
    };

    struct VertexInputAttributeDescription {
        uint32_t    location;
        uint32_t    binding;
        Format    format;
        uint32_t    offset;
    };

    struct StencilOpState {
        StencilOp failOp;
        StencilOp passOp;
        StencilOp depthFailOp;
        CompareOp compareOp;
        uint32_t compareMask;
        uint32_t writeMask;
        uint32_t reference;
    };

    struct PipelineColorBlendAttachmentState {
        bool blendEnable;
        BlendFactor srcColorBlendFactor;
        BlendFactor dstColorBlendFactor;
        BlendOp colorBlendOp;
        BlendFactor srcAlphaBlendFactor;
        BlendFactor dstAlphaBlendFactor;
        BlendOp alphaBlendOp;
        ColorComponentFlags colorWriteMask;

        const VkPipelineColorBlendAttachmentState& info() const { return m_info; }
        void marshal() const {
            m_info.blendEnable = blendEnable;
            m_info.srcColorBlendFactor = static_cast<VkBlendFactor>(srcColorBlendFactor);
            m_info.dstColorBlendFactor = static_cast<VkBlendFactor>(dstColorBlendFactor);
            m_info.colorBlendOp = static_cast<VkBlendOp>(colorBlendOp);
            m_info.srcAlphaBlendFactor = static_cast<VkBlendFactor>(srcAlphaBlendFactor);
            m_info.dstAlphaBlendFactor = static_cast<VkBlendFactor>(dstAlphaBlendFactor);
            m_info.alphaBlendOp = static_cast<VkBlendOp>(alphaBlendOp);
            m_info.colorWriteMask = static_cast<VkColorComponentFlags>(colorWriteMask);
        }

    private:
        mutable VkPipelineColorBlendAttachmentState m_info;
    };

    struct FormatProperties {
        FormatFeatureFlags linearTilingFeatures;
        FormatFeatureFlags optimalTilingFeatures;
        FormatFeatureFlags bufferFeatures;
    };

    struct ImageFormatProperties {
        Extent3D maxExtent;
        uint32_t maxMipLevels;
        uint32_t maxArrayLayers;
        SampleCountFlags sampleCounts;
        DeviceSize maxResourceSize;
    };

    struct DescriptorPoolSize {
        DescriptorType type;
        uint32_t descriptorCount;
    };

    struct ImageSubresourceLayers {
        ImageAspectFlags aspectMask;
        uint32_t mipLevel;
        uint32_t baseArrayLayer;
        uint32_t layerCount;
    };

    struct BufferImageCopy {
        DeviceSize bufferOffset;
        uint32_t bufferRowLength;
        uint32_t bufferImageHeight;
        ImageSubresourceLayers imageSubresource;
        Offset3D imageOffset;
        Extent3D imageExtent;
    };

    struct ImageBlit {
        ImageSubresourceLayers srcSubresource;
        Offset3D srcOffsets[2];
        ImageSubresourceLayers dstSubresource;
        Offset3D dstOffsets[2];
    };
}