//auto generated on 8/7/2020 3:26:34 PM
#pragma once

namespace vk {
    enum class AttachmentLoadOp {
        Load = 0,
        Clear = 1,
        DontCare = 2,
    };

    enum class AttachmentStoreOp {
        Store = 0,
        DontCare = 1,
    };

    enum class BlendFactor {
        Zero = 0,
        One = 1,
        SrcColor = 2,
        OneMinusSrcColor = 3,
        DstColor = 4,
        OneMinusDstColor = 5,
        SrcAlpha = 6,
        OneMinusSrcAlpha = 7,
        DstAlpha = 8,
        OneMinusDstAlpha = 9,
        ConstantColor = 10,
        OneMinusConstantColor = 11,
        ConstantAlpha = 12,
        OneMinusConstantAlpha = 13,
        SrcAlphaSaturate = 14,
        Src1_Color = 15,
        OneMinus_Src1_Color = 16,
        Src1_Alpha = 17,
        OneMinus_Src1_Alpha = 18,
    };

    enum class BlendOp {
        Add = 0,
        Subtract = 1,
        ReverseSubtract = 2,
        Min = 3,
        Max = 4,
        ZeroEXT = 1000148000,
        SrcEXT = 1000148001,
        DstEXT = 1000148002,
        SrcOverEXT = 1000148003,
        DstOverEXT = 1000148004,
        SrcInEXT = 1000148005,
        DstInEXT = 1000148006,
        SrcOutEXT = 1000148007,
        DstOutEXT = 1000148008,
        SrcAtopEXT = 1000148009,
        DstAtopEXT = 1000148010,
        XorEXT = 1000148011,
        MultiplyEXT = 1000148012,
        ScreenEXT = 1000148013,
        OverlayEXT = 1000148014,
        DarkenEXT = 1000148015,
        LightenEXT = 1000148016,
        ColordodgeEXT = 1000148017,
        ColorburnEXT = 1000148018,
        HardlightEXT = 1000148019,
        SoftlightEXT = 1000148020,
        DifferenceEXT = 1000148021,
        ExclusionEXT = 1000148022,
        InvertEXT = 1000148023,
        InvertRgbEXT = 1000148024,
        LineardodgeEXT = 1000148025,
        LinearburnEXT = 1000148026,
        VividlightEXT = 1000148027,
        LinearlightEXT = 1000148028,
        PinlightEXT = 1000148029,
        HardmixEXT = 1000148030,
        HslHueEXT = 1000148031,
        HslSaturationEXT = 1000148032,
        HslColorEXT = 1000148033,
        HslLuminosityEXT = 1000148034,
        PlusEXT = 1000148035,
        PlusClampedEXT = 1000148036,
        PlusClampedAlphaEXT = 1000148037,
        PlusDarkerEXT = 1000148038,
        MinusEXT = 1000148039,
        MinusClampedEXT = 1000148040,
        ContrastEXT = 1000148041,
        InvertOvgEXT = 1000148042,
        RedEXT = 1000148043,
        GreenEXT = 1000148044,
        BlueEXT = 1000148045,
    };

    enum class BorderColor {
        FloatTransparentBlack = 0,
        IntTransparentBlack = 1,
        FloatOpaqueBlack = 2,
        IntOpaqueBlack = 3,
        FloatOpaqueWhite = 4,
        IntOpaqueWhite = 5,
    };

    enum class FramebufferCreateFlags : uint32_t {
        None = 0,
    };

    inline FramebufferCreateFlags operator | (FramebufferCreateFlags a, FramebufferCreateFlags b) {
        return static_cast<FramebufferCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline FramebufferCreateFlags& operator |= (FramebufferCreateFlags& a, FramebufferCreateFlags b) {
        a = static_cast<FramebufferCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline FramebufferCreateFlags operator & (FramebufferCreateFlags a, FramebufferCreateFlags b) {
        return static_cast<FramebufferCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline FramebufferCreateFlags& operator &= (FramebufferCreateFlags& a, FramebufferCreateFlags& b) {
        a = static_cast<FramebufferCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (FramebufferCreateFlags& a, FramebufferCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (FramebufferCreateFlags& a, FramebufferCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class QueryPoolCreateFlags {
        None = 0,
    };

    enum class RenderPassCreateFlags : uint32_t {
        None = 0,
    };

    inline RenderPassCreateFlags operator | (RenderPassCreateFlags a, RenderPassCreateFlags b) {
        return static_cast<RenderPassCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline RenderPassCreateFlags& operator |= (RenderPassCreateFlags& a, RenderPassCreateFlags b) {
        a = static_cast<RenderPassCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline RenderPassCreateFlags operator & (RenderPassCreateFlags a, RenderPassCreateFlags b) {
        return static_cast<RenderPassCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline RenderPassCreateFlags& operator &= (RenderPassCreateFlags& a, RenderPassCreateFlags& b) {
        a = static_cast<RenderPassCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (RenderPassCreateFlags& a, RenderPassCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (RenderPassCreateFlags& a, RenderPassCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class SamplerCreateFlags : uint32_t {
        None = 0,
    };

    inline SamplerCreateFlags operator | (SamplerCreateFlags a, SamplerCreateFlags b) {
        return static_cast<SamplerCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline SamplerCreateFlags& operator |= (SamplerCreateFlags& a, SamplerCreateFlags b) {
        a = static_cast<SamplerCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline SamplerCreateFlags operator & (SamplerCreateFlags a, SamplerCreateFlags b) {
        return static_cast<SamplerCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline SamplerCreateFlags& operator &= (SamplerCreateFlags& a, SamplerCreateFlags& b) {
        a = static_cast<SamplerCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (SamplerCreateFlags& a, SamplerCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (SamplerCreateFlags& a, SamplerCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class PipelineCacheHeaderVersion {
        One = 1,
    };

    enum class PipelineLayoutCreateFlags {
        None = 0,
    };

    enum class PipelineCacheCreateFlags : uint32_t {
        None = 0,
    };

    inline PipelineCacheCreateFlags operator | (PipelineCacheCreateFlags a, PipelineCacheCreateFlags b) {
        return static_cast<PipelineCacheCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline PipelineCacheCreateFlags& operator |= (PipelineCacheCreateFlags& a, PipelineCacheCreateFlags b) {
        a = static_cast<PipelineCacheCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline PipelineCacheCreateFlags operator & (PipelineCacheCreateFlags a, PipelineCacheCreateFlags b) {
        return static_cast<PipelineCacheCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline PipelineCacheCreateFlags& operator &= (PipelineCacheCreateFlags& a, PipelineCacheCreateFlags& b) {
        a = static_cast<PipelineCacheCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (PipelineCacheCreateFlags& a, PipelineCacheCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (PipelineCacheCreateFlags& a, PipelineCacheCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class PipelineDepthStencilStateCreateFlags {
        None = 0,
    };

    enum class PipelineDynamicStateCreateFlags {
        None = 0,
    };

    enum class PipelineColorBlendStateCreateFlags {
        None = 0,
    };

    enum class PipelineMultisampleStateCreateFlags {
        None = 0,
    };

    enum class PipelineRasterizationStateCreateFlags {
        None = 0,
    };

    enum class PipelineViewportStateCreateFlags {
        None = 0,
    };

    enum class PipelineTessellationStateCreateFlags {
        None = 0,
    };

    enum class PipelineInputAssemblyStateCreateFlags {
        None = 0,
    };

    enum class PipelineVertexInputStateCreateFlags {
        None = 0,
    };

    enum class PipelineShaderStageCreateFlags : uint32_t {
        None = 0,
    };

    inline PipelineShaderStageCreateFlags operator | (PipelineShaderStageCreateFlags a, PipelineShaderStageCreateFlags b) {
        return static_cast<PipelineShaderStageCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline PipelineShaderStageCreateFlags& operator |= (PipelineShaderStageCreateFlags& a, PipelineShaderStageCreateFlags b) {
        a = static_cast<PipelineShaderStageCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline PipelineShaderStageCreateFlags operator & (PipelineShaderStageCreateFlags a, PipelineShaderStageCreateFlags b) {
        return static_cast<PipelineShaderStageCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline PipelineShaderStageCreateFlags& operator &= (PipelineShaderStageCreateFlags& a, PipelineShaderStageCreateFlags& b) {
        a = static_cast<PipelineShaderStageCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (PipelineShaderStageCreateFlags& a, PipelineShaderStageCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (PipelineShaderStageCreateFlags& a, PipelineShaderStageCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class DescriptorSetLayoutCreateFlags : uint32_t {
        None = 0,
    };

    inline DescriptorSetLayoutCreateFlags operator | (DescriptorSetLayoutCreateFlags a, DescriptorSetLayoutCreateFlags b) {
        return static_cast<DescriptorSetLayoutCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline DescriptorSetLayoutCreateFlags& operator |= (DescriptorSetLayoutCreateFlags& a, DescriptorSetLayoutCreateFlags b) {
        a = static_cast<DescriptorSetLayoutCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline DescriptorSetLayoutCreateFlags operator & (DescriptorSetLayoutCreateFlags a, DescriptorSetLayoutCreateFlags b) {
        return static_cast<DescriptorSetLayoutCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline DescriptorSetLayoutCreateFlags& operator &= (DescriptorSetLayoutCreateFlags& a, DescriptorSetLayoutCreateFlags& b) {
        a = static_cast<DescriptorSetLayoutCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (DescriptorSetLayoutCreateFlags& a, DescriptorSetLayoutCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (DescriptorSetLayoutCreateFlags& a, DescriptorSetLayoutCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class BufferViewCreateFlags {
        None = 0,
    };

    enum class InstanceCreateFlags {
        None = 0,
    };

    enum class DeviceQueueCreateFlags : uint32_t {
        None = 0,
    };

    inline DeviceQueueCreateFlags operator | (DeviceQueueCreateFlags a, DeviceQueueCreateFlags b) {
        return static_cast<DeviceQueueCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline DeviceQueueCreateFlags& operator |= (DeviceQueueCreateFlags& a, DeviceQueueCreateFlags b) {
        a = static_cast<DeviceQueueCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline DeviceQueueCreateFlags operator & (DeviceQueueCreateFlags a, DeviceQueueCreateFlags b) {
        return static_cast<DeviceQueueCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline DeviceQueueCreateFlags& operator &= (DeviceQueueCreateFlags& a, DeviceQueueCreateFlags& b) {
        a = static_cast<DeviceQueueCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (DeviceQueueCreateFlags& a, DeviceQueueCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (DeviceQueueCreateFlags& a, DeviceQueueCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class BufferCreateFlags : uint32_t {
        None = 0,
        SparseBinding = 1,
        SparseResidency = 2,
        SparseAliased = 4,
    };

    inline BufferCreateFlags operator | (BufferCreateFlags a, BufferCreateFlags b) {
        return static_cast<BufferCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline BufferCreateFlags& operator |= (BufferCreateFlags& a, BufferCreateFlags b) {
        a = static_cast<BufferCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline BufferCreateFlags operator & (BufferCreateFlags a, BufferCreateFlags b) {
        return static_cast<BufferCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline BufferCreateFlags& operator &= (BufferCreateFlags& a, BufferCreateFlags& b) {
        a = static_cast<BufferCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (BufferCreateFlags& a, BufferCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (BufferCreateFlags& a, BufferCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class BufferUsageFlags : uint32_t {
        None = 0,
        TransferSrc = 1,
        TransferDst = 2,
        UniformTexelBuffer = 4,
        StorageTexelBuffer = 8,
        UniformBuffer = 16,
        StorageBuffer = 32,
        IndexBuffer = 64,
        VertexBuffer = 128,
        IndirectBuffer = 256,
    };

    inline BufferUsageFlags operator | (BufferUsageFlags a, BufferUsageFlags b) {
        return static_cast<BufferUsageFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline BufferUsageFlags& operator |= (BufferUsageFlags& a, BufferUsageFlags b) {
        a = static_cast<BufferUsageFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline BufferUsageFlags operator & (BufferUsageFlags a, BufferUsageFlags b) {
        return static_cast<BufferUsageFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline BufferUsageFlags& operator &= (BufferUsageFlags& a, BufferUsageFlags& b) {
        a = static_cast<BufferUsageFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (BufferUsageFlags& a, BufferUsageFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (BufferUsageFlags& a, BufferUsageFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ColorComponentFlags : uint32_t {
        None = 0,
        R = 1,
        G = 2,
        B = 4,
        A = 8,
    };

    inline ColorComponentFlags operator | (ColorComponentFlags a, ColorComponentFlags b) {
        return static_cast<ColorComponentFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ColorComponentFlags& operator |= (ColorComponentFlags& a, ColorComponentFlags b) {
        a = static_cast<ColorComponentFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ColorComponentFlags operator & (ColorComponentFlags a, ColorComponentFlags b) {
        return static_cast<ColorComponentFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ColorComponentFlags& operator &= (ColorComponentFlags& a, ColorComponentFlags& b) {
        a = static_cast<ColorComponentFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ColorComponentFlags& a, ColorComponentFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ColorComponentFlags& a, ColorComponentFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ComponentSwizzle {
        Identity = 0,
        Zero = 1,
        One = 2,
        R = 3,
        G = 4,
        B = 5,
        A = 6,
    };

    enum class CommandPoolCreateFlags : uint32_t {
        None = 0,
        Transient = 1,
        ResetCommandBuffer = 2,
    };

    inline CommandPoolCreateFlags operator | (CommandPoolCreateFlags a, CommandPoolCreateFlags b) {
        return static_cast<CommandPoolCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline CommandPoolCreateFlags& operator |= (CommandPoolCreateFlags& a, CommandPoolCreateFlags b) {
        a = static_cast<CommandPoolCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline CommandPoolCreateFlags operator & (CommandPoolCreateFlags a, CommandPoolCreateFlags b) {
        return static_cast<CommandPoolCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline CommandPoolCreateFlags& operator &= (CommandPoolCreateFlags& a, CommandPoolCreateFlags& b) {
        a = static_cast<CommandPoolCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (CommandPoolCreateFlags& a, CommandPoolCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (CommandPoolCreateFlags& a, CommandPoolCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class CommandPoolResetFlags : uint32_t {
        None = 0,
        ReleaseResources = 1,
    };

    inline CommandPoolResetFlags operator | (CommandPoolResetFlags a, CommandPoolResetFlags b) {
        return static_cast<CommandPoolResetFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline CommandPoolResetFlags& operator |= (CommandPoolResetFlags& a, CommandPoolResetFlags b) {
        a = static_cast<CommandPoolResetFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline CommandPoolResetFlags operator & (CommandPoolResetFlags a, CommandPoolResetFlags b) {
        return static_cast<CommandPoolResetFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline CommandPoolResetFlags& operator &= (CommandPoolResetFlags& a, CommandPoolResetFlags& b) {
        a = static_cast<CommandPoolResetFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (CommandPoolResetFlags& a, CommandPoolResetFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (CommandPoolResetFlags& a, CommandPoolResetFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class CommandBufferResetFlags : uint32_t {
        None = 0,
        ReleaseResources = 1,
    };

    inline CommandBufferResetFlags operator | (CommandBufferResetFlags a, CommandBufferResetFlags b) {
        return static_cast<CommandBufferResetFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline CommandBufferResetFlags& operator |= (CommandBufferResetFlags& a, CommandBufferResetFlags b) {
        a = static_cast<CommandBufferResetFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline CommandBufferResetFlags operator & (CommandBufferResetFlags a, CommandBufferResetFlags b) {
        return static_cast<CommandBufferResetFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline CommandBufferResetFlags& operator &= (CommandBufferResetFlags& a, CommandBufferResetFlags& b) {
        a = static_cast<CommandBufferResetFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (CommandBufferResetFlags& a, CommandBufferResetFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (CommandBufferResetFlags& a, CommandBufferResetFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class CommandBufferLevel {
        Primary = 0,
        Secondary = 1,
    };

    enum class CommandBufferUsageFlags : uint32_t {
        None = 0,
        OneTimeSubmit = 1,
        RenderPassContinue = 2,
        SimultaneousUse = 4,
    };

    inline CommandBufferUsageFlags operator | (CommandBufferUsageFlags a, CommandBufferUsageFlags b) {
        return static_cast<CommandBufferUsageFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline CommandBufferUsageFlags& operator |= (CommandBufferUsageFlags& a, CommandBufferUsageFlags b) {
        a = static_cast<CommandBufferUsageFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline CommandBufferUsageFlags operator & (CommandBufferUsageFlags a, CommandBufferUsageFlags b) {
        return static_cast<CommandBufferUsageFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline CommandBufferUsageFlags& operator &= (CommandBufferUsageFlags& a, CommandBufferUsageFlags& b) {
        a = static_cast<CommandBufferUsageFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (CommandBufferUsageFlags& a, CommandBufferUsageFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (CommandBufferUsageFlags& a, CommandBufferUsageFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class CompareOp {
        Never = 0,
        Less = 1,
        Equal = 2,
        LessOrEqual = 3,
        Greater = 4,
        NotEqual = 5,
        GreaterOrEqual = 6,
        Always = 7,
    };

    enum class CullModeFlags : uint32_t {
        None = 0,
        Front = 1,
        Back = 2,
        FrontAndBack = 0x00000003,
    };

    inline CullModeFlags operator | (CullModeFlags a, CullModeFlags b) {
        return static_cast<CullModeFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline CullModeFlags& operator |= (CullModeFlags& a, CullModeFlags b) {
        a = static_cast<CullModeFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline CullModeFlags operator & (CullModeFlags a, CullModeFlags b) {
        return static_cast<CullModeFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline CullModeFlags& operator &= (CullModeFlags& a, CullModeFlags& b) {
        a = static_cast<CullModeFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (CullModeFlags& a, CullModeFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (CullModeFlags& a, CullModeFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class DescriptorType {
        Sampler = 0,
        CombinedImageSampler = 1,
        SampledImage = 2,
        StorageImage = 3,
        UniformTexelBuffer = 4,
        StorageTexelBuffer = 5,
        UniformBuffer = 6,
        StorageBuffer = 7,
        UniformBufferDynamic = 8,
        StorageBufferDynamic = 9,
        InputAttachment = 10,
        InlineUniformBlockEXT = 1000138000,
        AccelerationStructureKHR = 1000165000,
    };

    enum class DeviceCreateFlags {
        None = 0,
    };

    enum class DynamicState {
        Viewport = 0,
        Scissor = 1,
        LineWidth = 2,
        DepthBias = 3,
        BlendConstants = 4,
        DepthBounds = 5,
        StencilCompareMask = 6,
        StencilWriteMask = 7,
        StencilReference = 8,
        ViewportWScalingNV = 1000087000,
        DiscardRectangleEXT = 1000099000,
        SampleLocationsEXT = 1000143000,
        ViewportShadingRatePaletteNV = 1000164004,
        ViewportCoarseSampleOrderNV = 1000164006,
        ExclusiveScissorNV = 1000205001,
        LineStippleEXT = 1000259000,
    };

    enum class FenceCreateFlags : uint32_t {
        None = 0,
        Signaled = 1,
    };

    inline FenceCreateFlags operator | (FenceCreateFlags a, FenceCreateFlags b) {
        return static_cast<FenceCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline FenceCreateFlags& operator |= (FenceCreateFlags& a, FenceCreateFlags b) {
        a = static_cast<FenceCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline FenceCreateFlags operator & (FenceCreateFlags a, FenceCreateFlags b) {
        return static_cast<FenceCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline FenceCreateFlags& operator &= (FenceCreateFlags& a, FenceCreateFlags& b) {
        a = static_cast<FenceCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (FenceCreateFlags& a, FenceCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (FenceCreateFlags& a, FenceCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class PolygonMode {
        Fill = 0,
        Line = 1,
        Point = 2,
        FillRectangleNV = 1000153000,
    };

    enum class Format {
        Undefined = 0,
        R4G4_Unorm_Pack8 = 1,
        R4G4B4A4_Unorm_Pack16 = 2,
        B4G4R4A4_Unorm_Pack16 = 3,
        R5G6B5_Unorm_Pack16 = 4,
        B5G6R5_Unorm_Pack16 = 5,
        R5G5B5A1_Unorm_Pack16 = 6,
        B5G5R5A1_Unorm_Pack16 = 7,
        A1R5G5B5_Unorm_Pack16 = 8,
        R8_Unorm = 9,
        R8_Snorm = 10,
        R8_Uscaled = 11,
        R8_Sscaled = 12,
        R8_Uint = 13,
        R8_Sint = 14,
        R8_Srgb = 15,
        R8G8_Unorm = 16,
        R8G8_Snorm = 17,
        R8G8_Uscaled = 18,
        R8G8_Sscaled = 19,
        R8G8_Uint = 20,
        R8G8_Sint = 21,
        R8G8_Srgb = 22,
        R8G8B8_Unorm = 23,
        R8G8B8_Snorm = 24,
        R8G8B8_Uscaled = 25,
        R8G8B8_Sscaled = 26,
        R8G8B8_Uint = 27,
        R8G8B8_Sint = 28,
        R8G8B8_Srgb = 29,
        B8G8R8_Unorm = 30,
        B8G8R8_Snorm = 31,
        B8G8R8_Uscaled = 32,
        B8G8R8_Sscaled = 33,
        B8G8R8_Uint = 34,
        B8G8R8_Sint = 35,
        B8G8R8_Srgb = 36,
        R8G8B8A8_Unorm = 37,
        R8G8B8A8_Snorm = 38,
        R8G8B8A8_Uscaled = 39,
        R8G8B8A8_Sscaled = 40,
        R8G8B8A8_Uint = 41,
        R8G8B8A8_Sint = 42,
        R8G8B8A8_Srgb = 43,
        B8G8R8A8_Unorm = 44,
        B8G8R8A8_Snorm = 45,
        B8G8R8A8_Uscaled = 46,
        B8G8R8A8_Sscaled = 47,
        B8G8R8A8_Uint = 48,
        B8G8R8A8_Sint = 49,
        B8G8R8A8_Srgb = 50,
        A8B8G8R8_Unorm_Pack32 = 51,
        A8B8G8R8_Snorm_Pack32 = 52,
        A8B8G8R8_Uscaled_Pack32 = 53,
        A8B8G8R8_Sscaled_Pack32 = 54,
        A8B8G8R8_Uint_Pack32 = 55,
        A8B8G8R8_Sint_Pack32 = 56,
        A8B8G8R8_Srgb_Pack32 = 57,
        A2R10G10B10_Unorm_Pack32 = 58,
        A2R10G10B10_Snorm_Pack32 = 59,
        A2R10G10B10_Uscaled_Pack32 = 60,
        A2R10G10B10_Sscaled_Pack32 = 61,
        A2R10G10B10_Uint_Pack32 = 62,
        A2R10G10B10_Sint_Pack32 = 63,
        A2B10G10R10_Unorm_Pack32 = 64,
        A2B10G10R10_Snorm_Pack32 = 65,
        A2B10G10R10_Uscaled_Pack32 = 66,
        A2B10G10R10_Sscaled_Pack32 = 67,
        A2B10G10R10_Uint_Pack32 = 68,
        A2B10G10R10_Sint_Pack32 = 69,
        R16_Unorm = 70,
        R16_Snorm = 71,
        R16_Uscaled = 72,
        R16_Sscaled = 73,
        R16_Uint = 74,
        R16_Sint = 75,
        R16_Sfloat = 76,
        R16G16_Unorm = 77,
        R16G16_Snorm = 78,
        R16G16_Uscaled = 79,
        R16G16_Sscaled = 80,
        R16G16_Uint = 81,
        R16G16_Sint = 82,
        R16G16_Sfloat = 83,
        R16G16B16_Unorm = 84,
        R16G16B16_Snorm = 85,
        R16G16B16_Uscaled = 86,
        R16G16B16_Sscaled = 87,
        R16G16B16_Uint = 88,
        R16G16B16_Sint = 89,
        R16G16B16_Sfloat = 90,
        R16G16B16A16_Unorm = 91,
        R16G16B16A16_Snorm = 92,
        R16G16B16A16_Uscaled = 93,
        R16G16B16A16_Sscaled = 94,
        R16G16B16A16_Uint = 95,
        R16G16B16A16_Sint = 96,
        R16G16B16A16_Sfloat = 97,
        R32_Uint = 98,
        R32_Sint = 99,
        R32_Sfloat = 100,
        R32G32_Uint = 101,
        R32G32_Sint = 102,
        R32G32_Sfloat = 103,
        R32G32B32_Uint = 104,
        R32G32B32_Sint = 105,
        R32G32B32_Sfloat = 106,
        R32G32B32A32_Uint = 107,
        R32G32B32A32_Sint = 108,
        R32G32B32A32_Sfloat = 109,
        R64_Uint = 110,
        R64_Sint = 111,
        R64_Sfloat = 112,
        R64G64_Uint = 113,
        R64G64_Sint = 114,
        R64G64_Sfloat = 115,
        R64G64B64_Uint = 116,
        R64G64B64_Sint = 117,
        R64G64B64_Sfloat = 118,
        R64G64B64A64_Uint = 119,
        R64G64B64A64_Sint = 120,
        R64G64B64A64_Sfloat = 121,
        B10G11R11_Ufloat_Pack32 = 122,
        E5B9G9R9_Ufloat_Pack32 = 123,
        D16_Unorm = 124,
        X8_D24_Unorm_Pack32 = 125,
        D32_Sfloat = 126,
        S8_Uint = 127,
        D16_Unorm_S8_Uint = 128,
        D24_Unorm_S8_Uint = 129,
        D32_Sfloat_S8_Uint = 130,
        Bc1_RgbUnormBlock = 131,
        Bc1_RgbSrgbBlock = 132,
        Bc1_RgbaUnormBlock = 133,
        Bc1_RgbaSrgbBlock = 134,
        Bc2_UnormBlock = 135,
        Bc2_SrgbBlock = 136,
        Bc3_UnormBlock = 137,
        Bc3_SrgbBlock = 138,
        Bc4_UnormBlock = 139,
        Bc4_SnormBlock = 140,
        Bc5_UnormBlock = 141,
        Bc5_SnormBlock = 142,
        Bc6H_UfloatBlock = 143,
        Bc6H_SfloatBlock = 144,
        Bc7_UnormBlock = 145,
        Bc7_SrgbBlock = 146,
        Etc2_R8G8B8_UnormBlock = 147,
        Etc2_R8G8B8_SrgbBlock = 148,
        Etc2_R8G8B8A1_UnormBlock = 149,
        Etc2_R8G8B8A1_SrgbBlock = 150,
        Etc2_R8G8B8A8_UnormBlock = 151,
        Etc2_R8G8B8A8_SrgbBlock = 152,
        Eac_R11_UnormBlock = 153,
        Eac_R11_SnormBlock = 154,
        Eac_R11G11_UnormBlock = 155,
        Eac_R11G11_SnormBlock = 156,
        Astc_4x4_UnormBlock = 157,
        Astc_4x4_SrgbBlock = 158,
        Astc_5x4_UnormBlock = 159,
        Astc_5x4_SrgbBlock = 160,
        Astc_5x5_UnormBlock = 161,
        Astc_5x5_SrgbBlock = 162,
        Astc_6x5_UnormBlock = 163,
        Astc_6x5_SrgbBlock = 164,
        Astc_6x6_UnormBlock = 165,
        Astc_6x6_SrgbBlock = 166,
        Astc_8x5_UnormBlock = 167,
        Astc_8x5_SrgbBlock = 168,
        Astc_8x6_UnormBlock = 169,
        Astc_8x6_SrgbBlock = 170,
        Astc_8x8_UnormBlock = 171,
        Astc_8x8_SrgbBlock = 172,
        Astc_10x5_UnormBlock = 173,
        Astc_10x5_SrgbBlock = 174,
        Astc_10x6_UnormBlock = 175,
        Astc_10x6_SrgbBlock = 176,
        Astc_10x8_UnormBlock = 177,
        Astc_10x8_SrgbBlock = 178,
        Astc_10x10_UnormBlock = 179,
        Astc_10x10_SrgbBlock = 180,
        Astc_12x10_UnormBlock = 181,
        Astc_12x10_SrgbBlock = 182,
        Astc_12x12_UnormBlock = 183,
        Astc_12x12_SrgbBlock = 184,
        Pvrtc1_2Bpp_UnormBlockIMG = 1000054000,
        Pvrtc1_4Bpp_UnormBlockIMG = 1000054001,
        Pvrtc2_2Bpp_UnormBlockIMG = 1000054002,
        Pvrtc2_4Bpp_UnormBlockIMG = 1000054003,
        Pvrtc1_2Bpp_SrgbBlockIMG = 1000054004,
        Pvrtc1_4Bpp_SrgbBlockIMG = 1000054005,
        Pvrtc2_2Bpp_SrgbBlockIMG = 1000054006,
        Pvrtc2_4Bpp_SrgbBlockIMG = 1000054007,
        Astc_4x4_SfloatBlockEXT = 1000066000,
        Astc_5x4_SfloatBlockEXT = 1000066001,
        Astc_5x5_SfloatBlockEXT = 1000066002,
        Astc_6x5_SfloatBlockEXT = 1000066003,
        Astc_6x6_SfloatBlockEXT = 1000066004,
        Astc_8x5_SfloatBlockEXT = 1000066005,
        Astc_8x6_SfloatBlockEXT = 1000066006,
        Astc_8x8_SfloatBlockEXT = 1000066007,
        Astc_10x5_SfloatBlockEXT = 1000066008,
        Astc_10x6_SfloatBlockEXT = 1000066009,
        Astc_10x8_SfloatBlockEXT = 1000066010,
        Astc_10x10_SfloatBlockEXT = 1000066011,
        Astc_12x10_SfloatBlockEXT = 1000066012,
        Astc_12x12_SfloatBlockEXT = 1000066013,
    };

    enum class FormatFeatureFlags : uint32_t {
        None = 0,
        SampledImage = 1,
        StorageImage = 2,
        StorageImageAtomic = 4,
        UniformTexelBuffer = 8,
        StorageTexelBuffer = 16,
        StorageTexelBufferAtomic = 32,
        VertexBuffer = 64,
        ColorAttachment = 128,
        ColorAttachmentBlend = 256,
        DepthStencilAttachment = 512,
        BlitSrc = 1024,
        BlitDst = 2048,
        SampledImageFilterLinear = 4096,
    };

    inline FormatFeatureFlags operator | (FormatFeatureFlags a, FormatFeatureFlags b) {
        return static_cast<FormatFeatureFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline FormatFeatureFlags& operator |= (FormatFeatureFlags& a, FormatFeatureFlags b) {
        a = static_cast<FormatFeatureFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline FormatFeatureFlags operator & (FormatFeatureFlags a, FormatFeatureFlags b) {
        return static_cast<FormatFeatureFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline FormatFeatureFlags& operator &= (FormatFeatureFlags& a, FormatFeatureFlags& b) {
        a = static_cast<FormatFeatureFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (FormatFeatureFlags& a, FormatFeatureFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (FormatFeatureFlags& a, FormatFeatureFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class FrontFace {
        CounterClockwise = 0,
        Clockwise = 1,
    };

    enum class ImageAspectFlags : uint32_t {
        None = 0,
        Color = 1,
        Depth = 2,
        Stencil = 4,
        Metadata = 8,
    };

    inline ImageAspectFlags operator | (ImageAspectFlags a, ImageAspectFlags b) {
        return static_cast<ImageAspectFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ImageAspectFlags& operator |= (ImageAspectFlags& a, ImageAspectFlags b) {
        a = static_cast<ImageAspectFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ImageAspectFlags operator & (ImageAspectFlags a, ImageAspectFlags b) {
        return static_cast<ImageAspectFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ImageAspectFlags& operator &= (ImageAspectFlags& a, ImageAspectFlags& b) {
        a = static_cast<ImageAspectFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ImageAspectFlags& a, ImageAspectFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ImageAspectFlags& a, ImageAspectFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ImageCreateFlags : uint32_t {
        None = 0,
        SparseBinding = 1,
        SparseResidency = 2,
        SparseAliased = 4,
        MutableFormat = 8,
        CubeCompatible = 16,
    };

    inline ImageCreateFlags operator | (ImageCreateFlags a, ImageCreateFlags b) {
        return static_cast<ImageCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ImageCreateFlags& operator |= (ImageCreateFlags& a, ImageCreateFlags b) {
        a = static_cast<ImageCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ImageCreateFlags operator & (ImageCreateFlags a, ImageCreateFlags b) {
        return static_cast<ImageCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ImageCreateFlags& operator &= (ImageCreateFlags& a, ImageCreateFlags& b) {
        a = static_cast<ImageCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ImageCreateFlags& a, ImageCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ImageCreateFlags& a, ImageCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ImageLayout {
        Undefined = 0,
        General = 1,
        ColorAttachmentOptimal = 2,
        DepthStencilAttachmentOptimal = 3,
        DepthStencilReadOnlyOptimal = 4,
        ShaderReadOnlyOptimal = 5,
        TransferSrcOptimal = 6,
        TransferDstOptimal = 7,
        Preinitialized = 8,
        PresentSrcKHR = 1000001002,
        SharedPresentKHR = 1000111000,
        ShadingRateOptimalNV = 1000164003,
        FragmentDensityMapOptimalEXT = 1000218000,
    };

    enum class ImageTiling {
        Optimal = 0,
        Linear = 1,
        DrmFormatModifierEXT = 1000158000,
    };

    enum class ImageType {
        _1D = 0,
        _2D = 1,
        _3D = 2,
    };

    enum class ImageUsageFlags : uint32_t {
        None = 0,
        TransferSrc = 1,
        TransferDst = 2,
        Sampled = 4,
        Storage = 8,
        ColorAttachment = 16,
        DepthStencilAttachment = 32,
        TransientAttachment = 64,
        InputAttachment = 128,
    };

    inline ImageUsageFlags operator | (ImageUsageFlags a, ImageUsageFlags b) {
        return static_cast<ImageUsageFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ImageUsageFlags& operator |= (ImageUsageFlags& a, ImageUsageFlags b) {
        a = static_cast<ImageUsageFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ImageUsageFlags operator & (ImageUsageFlags a, ImageUsageFlags b) {
        return static_cast<ImageUsageFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ImageUsageFlags& operator &= (ImageUsageFlags& a, ImageUsageFlags& b) {
        a = static_cast<ImageUsageFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ImageUsageFlags& a, ImageUsageFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ImageUsageFlags& a, ImageUsageFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ImageViewCreateFlags : uint32_t {
        None = 0,
    };

    inline ImageViewCreateFlags operator | (ImageViewCreateFlags a, ImageViewCreateFlags b) {
        return static_cast<ImageViewCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ImageViewCreateFlags& operator |= (ImageViewCreateFlags& a, ImageViewCreateFlags b) {
        a = static_cast<ImageViewCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ImageViewCreateFlags operator & (ImageViewCreateFlags a, ImageViewCreateFlags b) {
        return static_cast<ImageViewCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ImageViewCreateFlags& operator &= (ImageViewCreateFlags& a, ImageViewCreateFlags& b) {
        a = static_cast<ImageViewCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ImageViewCreateFlags& a, ImageViewCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ImageViewCreateFlags& a, ImageViewCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ImageViewType {
        _1D = 0,
        _2D = 1,
        _3D = 2,
        Cube = 3,
        _1D_Array = 4,
        _2D_Array = 5,
        CubeArray = 6,
    };

    enum class SharingMode {
        Exclusive = 0,
        Concurrent = 1,
    };

    enum class IndexType {
        Uint16 = 0,
        Uint32 = 1,
        NoneKHR = 1000165000,
        Uint8_EXT = 1000265000,
    };

    enum class LogicOp {
        Clear = 0,
        And = 1,
        AndReverse = 2,
        Copy = 3,
        AndInverted = 4,
        NoOp = 5,
        Xor = 6,
        Or = 7,
        Nor = 8,
        Equivalent = 9,
        Invert = 10,
        OrReverse = 11,
        CopyInverted = 12,
        OrInverted = 13,
        Nand = 14,
        Set = 15,
    };

    enum class MemoryHeapFlags : uint32_t {
        None = 0,
        DeviceLocal = 1,
    };

    inline MemoryHeapFlags operator | (MemoryHeapFlags a, MemoryHeapFlags b) {
        return static_cast<MemoryHeapFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline MemoryHeapFlags& operator |= (MemoryHeapFlags& a, MemoryHeapFlags b) {
        a = static_cast<MemoryHeapFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline MemoryHeapFlags operator & (MemoryHeapFlags a, MemoryHeapFlags b) {
        return static_cast<MemoryHeapFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline MemoryHeapFlags& operator &= (MemoryHeapFlags& a, MemoryHeapFlags& b) {
        a = static_cast<MemoryHeapFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (MemoryHeapFlags& a, MemoryHeapFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (MemoryHeapFlags& a, MemoryHeapFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class AccessFlags : uint32_t {
        None = 0,
        IndirectCommandRead = 1,
        IndexRead = 2,
        VertexAttributeRead = 4,
        UniformRead = 8,
        InputAttachmentRead = 16,
        ShaderRead = 32,
        ShaderWrite = 64,
        ColorAttachmentRead = 128,
        ColorAttachmentWrite = 256,
        DepthStencilAttachmentRead = 512,
        DepthStencilAttachmentWrite = 1024,
        TransferRead = 2048,
        TransferWrite = 4096,
        HostRead = 8192,
        HostWrite = 16384,
        MemoryRead = 32768,
        MemoryWrite = 65536,
    };

    inline AccessFlags operator | (AccessFlags a, AccessFlags b) {
        return static_cast<AccessFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline AccessFlags& operator |= (AccessFlags& a, AccessFlags b) {
        a = static_cast<AccessFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline AccessFlags operator & (AccessFlags a, AccessFlags b) {
        return static_cast<AccessFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline AccessFlags& operator &= (AccessFlags& a, AccessFlags& b) {
        a = static_cast<AccessFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (AccessFlags& a, AccessFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (AccessFlags& a, AccessFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class MemoryPropertyFlags : uint32_t {
        None = 0,
        DeviceLocal = 1,
        HostVisible = 2,
        HostCoherent = 4,
        HostCached = 8,
        LazilyAllocated = 16,
    };

    inline MemoryPropertyFlags operator | (MemoryPropertyFlags a, MemoryPropertyFlags b) {
        return static_cast<MemoryPropertyFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline MemoryPropertyFlags& operator |= (MemoryPropertyFlags& a, MemoryPropertyFlags b) {
        a = static_cast<MemoryPropertyFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline MemoryPropertyFlags operator & (MemoryPropertyFlags a, MemoryPropertyFlags b) {
        return static_cast<MemoryPropertyFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline MemoryPropertyFlags& operator &= (MemoryPropertyFlags& a, MemoryPropertyFlags& b) {
        a = static_cast<MemoryPropertyFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (MemoryPropertyFlags& a, MemoryPropertyFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (MemoryPropertyFlags& a, MemoryPropertyFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class PhysicalDeviceType {
        Other = 0,
        IntegratedGpu = 1,
        DiscreteGpu = 2,
        VirtualGpu = 3,
        Cpu = 4,
    };

    enum class PipelineBindPoint {
        Graphics = 0,
        Compute = 1,
        RayTracingKHR = 1000165000,
    };

    enum class PipelineCreateFlags : uint32_t {
        None = 0,
        DisableOptimization = 1,
        AllowDerivatives = 2,
        Derivative = 4,
    };

    inline PipelineCreateFlags operator | (PipelineCreateFlags a, PipelineCreateFlags b) {
        return static_cast<PipelineCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline PipelineCreateFlags& operator |= (PipelineCreateFlags& a, PipelineCreateFlags b) {
        a = static_cast<PipelineCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline PipelineCreateFlags operator & (PipelineCreateFlags a, PipelineCreateFlags b) {
        return static_cast<PipelineCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline PipelineCreateFlags& operator &= (PipelineCreateFlags& a, PipelineCreateFlags& b) {
        a = static_cast<PipelineCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (PipelineCreateFlags& a, PipelineCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (PipelineCreateFlags& a, PipelineCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class PrimitiveTopology {
        PointList = 0,
        LineList = 1,
        LineStrip = 2,
        TriangleList = 3,
        TriangleStrip = 4,
        TriangleFan = 5,
        LineListWithAdjacency = 6,
        LineStripWithAdjacency = 7,
        TriangleListWithAdjacency = 8,
        TriangleStripWithAdjacency = 9,
        PatchList = 10,
    };

    enum class QueryControlFlags : uint32_t {
        None = 0,
        Precise = 1,
    };

    inline QueryControlFlags operator | (QueryControlFlags a, QueryControlFlags b) {
        return static_cast<QueryControlFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline QueryControlFlags& operator |= (QueryControlFlags& a, QueryControlFlags b) {
        a = static_cast<QueryControlFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline QueryControlFlags operator & (QueryControlFlags a, QueryControlFlags b) {
        return static_cast<QueryControlFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline QueryControlFlags& operator &= (QueryControlFlags& a, QueryControlFlags& b) {
        a = static_cast<QueryControlFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (QueryControlFlags& a, QueryControlFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (QueryControlFlags& a, QueryControlFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class QueryPipelineStatisticFlags : uint32_t {
        None = 0,
        InputAssemblyVertices = 1,
        InputAssemblyPrimitives = 2,
        VertexShaderInvocations = 4,
        GeometryShaderInvocations = 8,
        GeometryShaderPrimitives = 16,
        ClippingInvocations = 32,
        ClippingPrimitives = 64,
        FragmentShaderInvocations = 128,
        TessellationControlShaderPatches = 256,
        TessellationEvaluationShaderInvocations = 512,
        ComputeShaderInvocations = 1024,
    };

    inline QueryPipelineStatisticFlags operator | (QueryPipelineStatisticFlags a, QueryPipelineStatisticFlags b) {
        return static_cast<QueryPipelineStatisticFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline QueryPipelineStatisticFlags& operator |= (QueryPipelineStatisticFlags& a, QueryPipelineStatisticFlags b) {
        a = static_cast<QueryPipelineStatisticFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline QueryPipelineStatisticFlags operator & (QueryPipelineStatisticFlags a, QueryPipelineStatisticFlags b) {
        return static_cast<QueryPipelineStatisticFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline QueryPipelineStatisticFlags& operator &= (QueryPipelineStatisticFlags& a, QueryPipelineStatisticFlags& b) {
        a = static_cast<QueryPipelineStatisticFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (QueryPipelineStatisticFlags& a, QueryPipelineStatisticFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (QueryPipelineStatisticFlags& a, QueryPipelineStatisticFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class QueryResultFlags : uint32_t {
        None = 0,
        _64 = 1,
        Wait = 2,
        WithAvailability = 4,
        Partial = 8,
    };

    inline QueryResultFlags operator | (QueryResultFlags a, QueryResultFlags b) {
        return static_cast<QueryResultFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline QueryResultFlags& operator |= (QueryResultFlags& a, QueryResultFlags b) {
        a = static_cast<QueryResultFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline QueryResultFlags operator & (QueryResultFlags a, QueryResultFlags b) {
        return static_cast<QueryResultFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline QueryResultFlags& operator &= (QueryResultFlags& a, QueryResultFlags& b) {
        a = static_cast<QueryResultFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (QueryResultFlags& a, QueryResultFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (QueryResultFlags& a, QueryResultFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class QueryType {
        Occlusion = 0,
        PipelineStatistics = 1,
        Timestamp = 2,
        Reserved_8 = 1000023008,
        Reserved_4 = 1000024004,
        TransformFeedbackStreamEXT = 1000028004,
        PerformanceQueryKHR = 1000116000,
        AccelerationStructureCompactedSizeKHR = 1000165000,
        AccelerationStructureSerializationSizeKHR = 1000150000,
        PerformanceQueryINTEL = 1000210000,
    };

    enum class QueueFlags : uint32_t {
        None = 0,
        Graphics = 1,
        Compute = 2,
        Transfer = 4,
        SparseBinding = 8,
    };

    inline QueueFlags operator | (QueueFlags a, QueueFlags b) {
        return static_cast<QueueFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline QueueFlags& operator |= (QueueFlags& a, QueueFlags b) {
        a = static_cast<QueueFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline QueueFlags operator & (QueueFlags a, QueueFlags b) {
        return static_cast<QueueFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline QueueFlags& operator &= (QueueFlags& a, QueueFlags& b) {
        a = static_cast<QueueFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (QueueFlags& a, QueueFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (QueueFlags& a, QueueFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class SubpassContents {
        Inline = 0,
        SecondaryCommandBuffers = 1,
    };

    enum class Result {
        Success = 0,
        NotReady = 1,
        Timeout = 2,
        EventSet = 3,
        EventReset = 4,
        Incomplete = 5,
        ErrorOutOfHostMemory = -1,
        ErrorOutOfDeviceMemory = -2,
        ErrorInitializationFailed = -3,
        ErrorDeviceLost = -4,
        ErrorMemoryMapFailed = -5,
        ErrorLayerNotPresent = -6,
        ErrorExtensionNotPresent = -7,
        ErrorFeatureNotPresent = -8,
        ErrorIncompatibleDriver = -9,
        ErrorTooManyObjects = -10,
        ErrorFormatNotSupported = -11,
        ErrorFragmentedPool = -12,
        ErrorUnknown = -13,
        ErrorSurfaceLostKHR = -1000000000,
        ErrorNativeWindowInUseKHR = -1000000001,
        SuboptimalKHR = 1000001003,
        ErrorOutOfDateKHR = -1000001004,
        ErrorIncompatibleDisplayKHR = -1000003001,
        ErrorValidationFailedEXT = -1000011001,
        ErrorInvalidShaderNV = -1000012000,
        ErrorIncompatibleVersionKHR = -1000150000,
        ErrorInvalidDrmFormatModifierPlaneLayoutEXT = -1000158000,
        ErrorNotPermittedEXT = -1000174001,
        ErrorFullScreenExclusiveModeLostEXT = -1000255000,
        ThreadIdleKHR = 1000268000,
        ThreadDoneKHR = 1000268001,
        OperationDeferredKHR = 1000268002,
        OperationNotDeferredKHR = 1000268003,
        ErrorPipelineCompileRequiredEXT = 1000297000,
    };

    enum class ShaderStageFlags : uint32_t {
        None = 0,
        Vertex = 1,
        TessellationControl = 2,
        TessellationEvaluation = 4,
        Geometry = 8,
        Fragment = 16,
        Compute = 32,
        AllGraphics = 0x0000001F,
        All = 0x7FFFFFFF,
    };

    inline ShaderStageFlags operator | (ShaderStageFlags a, ShaderStageFlags b) {
        return static_cast<ShaderStageFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ShaderStageFlags& operator |= (ShaderStageFlags& a, ShaderStageFlags b) {
        a = static_cast<ShaderStageFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ShaderStageFlags operator & (ShaderStageFlags a, ShaderStageFlags b) {
        return static_cast<ShaderStageFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ShaderStageFlags& operator &= (ShaderStageFlags& a, ShaderStageFlags& b) {
        a = static_cast<ShaderStageFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ShaderStageFlags& a, ShaderStageFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ShaderStageFlags& a, ShaderStageFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class SparseMemoryBindFlags : uint32_t {
        None = 0,
        Metadata = 1,
    };

    inline SparseMemoryBindFlags operator | (SparseMemoryBindFlags a, SparseMemoryBindFlags b) {
        return static_cast<SparseMemoryBindFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline SparseMemoryBindFlags& operator |= (SparseMemoryBindFlags& a, SparseMemoryBindFlags b) {
        a = static_cast<SparseMemoryBindFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline SparseMemoryBindFlags operator & (SparseMemoryBindFlags a, SparseMemoryBindFlags b) {
        return static_cast<SparseMemoryBindFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline SparseMemoryBindFlags& operator &= (SparseMemoryBindFlags& a, SparseMemoryBindFlags& b) {
        a = static_cast<SparseMemoryBindFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (SparseMemoryBindFlags& a, SparseMemoryBindFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (SparseMemoryBindFlags& a, SparseMemoryBindFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class StencilFaceFlags : uint32_t {
        None = 0,
        Front = 1,
        Back = 2,
        FrontAndBack = 0x00000003,
    };

    inline StencilFaceFlags operator | (StencilFaceFlags a, StencilFaceFlags b) {
        return static_cast<StencilFaceFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline StencilFaceFlags& operator |= (StencilFaceFlags& a, StencilFaceFlags b) {
        a = static_cast<StencilFaceFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline StencilFaceFlags operator & (StencilFaceFlags a, StencilFaceFlags b) {
        return static_cast<StencilFaceFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline StencilFaceFlags& operator &= (StencilFaceFlags& a, StencilFaceFlags& b) {
        a = static_cast<StencilFaceFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (StencilFaceFlags& a, StencilFaceFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (StencilFaceFlags& a, StencilFaceFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class StencilOp {
        Keep = 0,
        Zero = 1,
        Replace = 2,
        IncrementAndClamp = 3,
        DecrementAndClamp = 4,
        Invert = 5,
        IncrementAndWrap = 6,
        DecrementAndWrap = 7,
    };

    enum class StructureType {
        ApplicationInfo = 0,
        InstanceCreateInfo = 1,
        DeviceQueueCreateInfo = 2,
        DeviceCreateInfo = 3,
        SubmitInfo = 4,
        MemoryAllocateInfo = 5,
        MappedMemoryRange = 6,
        BindSparseInfo = 7,
        FenceCreateInfo = 8,
        SemaphoreCreateInfo = 9,
        EventCreateInfo = 10,
        QueryPoolCreateInfo = 11,
        BufferCreateInfo = 12,
        BufferViewCreateInfo = 13,
        ImageCreateInfo = 14,
        ImageViewCreateInfo = 15,
        ShaderModuleCreateInfo = 16,
        PipelineCacheCreateInfo = 17,
        PipelineShaderStageCreateInfo = 18,
        PipelineVertexInputStateCreateInfo = 19,
        PipelineInputAssemblyStateCreateInfo = 20,
        PipelineTessellationStateCreateInfo = 21,
        PipelineViewportStateCreateInfo = 22,
        PipelineRasterizationStateCreateInfo = 23,
        PipelineMultisampleStateCreateInfo = 24,
        PipelineDepthStencilStateCreateInfo = 25,
        PipelineColorBlendStateCreateInfo = 26,
        PipelineDynamicStateCreateInfo = 27,
        GraphicsPipelineCreateInfo = 28,
        ComputePipelineCreateInfo = 29,
        PipelineLayoutCreateInfo = 30,
        SamplerCreateInfo = 31,
        DescriptorSetLayoutCreateInfo = 32,
        DescriptorPoolCreateInfo = 33,
        DescriptorSetAllocateInfo = 34,
        WriteDescriptorSet = 35,
        CopyDescriptorSet = 36,
        FramebufferCreateInfo = 37,
        RenderPassCreateInfo = 38,
        CommandPoolCreateInfo = 39,
        CommandBufferAllocateInfo = 40,
        CommandBufferInheritanceInfo = 41,
        CommandBufferBeginInfo = 42,
        RenderPassBeginInfo = 43,
        BufferMemoryBarrier = 44,
        ImageMemoryBarrier = 45,
        MemoryBarrier = 46,
        LoaderInstanceCreateInfo = 47,
        LoaderDeviceCreateInfo = 48,
        SwapchainCreateInfoKHR = 1000001000,
        PresentInfoKHR = 1000001001,
        DeviceGroupPresentCapabilitiesKHR = 1000060007,
        ImageSwapchainCreateInfoKHR = 1000060008,
        BindImageMemorySwapchainInfoKHR = 1000060009,
        AcquireNextImageInfoKHR = 1000060010,
        DeviceGroupPresentInfoKHR = 1000060011,
        DeviceGroupSwapchainCreateInfoKHR = 1000060012,
        DisplayModeCreateInfoKHR = 1000002000,
        DisplaySurfaceCreateInfoKHR = 1000002001,
        DisplayPresentInfoKHR = 1000003000,
        XlibSurfaceCreateInfoKHR = 1000004000,
        XcbSurfaceCreateInfoKHR = 1000005000,
        WaylandSurfaceCreateInfoKHR = 1000006000,
        AndroidSurfaceCreateInfoKHR = 1000008000,
        Win32_SurfaceCreateInfoKHR = 1000009000,
        NativeBufferANDROID = 1000010000,
        SwapchainImageCreateInfoANDROID = 1000010001,
        PhysicalDevicePresentationPropertiesANDROID = 1000010002,
        DebugReportCallbackCreateInfoEXT = 1000011000,
        PipelineRasterizationStateRasterizationOrderAMD = 1000018000,
        DebugMarkerObjectNameInfoEXT = 1000022000,
        DebugMarkerObjectTagInfoEXT = 1000022001,
        DebugMarkerMarkerInfoEXT = 1000022002,
        DedicatedAllocationImageCreateInfoNV = 1000026000,
        DedicatedAllocationBufferCreateInfoNV = 1000026001,
        DedicatedAllocationMemoryAllocateInfoNV = 1000026002,
        PhysicalDeviceTransformFeedbackFeaturesEXT = 1000028000,
        PhysicalDeviceTransformFeedbackPropertiesEXT = 1000028001,
        PipelineRasterizationStateStreamCreateInfoEXT = 1000028002,
        ImageViewHandleInfoNVX = 1000030000,
        TextureLodGatherFormatPropertiesAMD = 1000041000,
        StreamDescriptorSurfaceCreateInfoGGP = 1000049000,
        PhysicalDeviceCornerSampledImageFeaturesNV = 1000050000,
        ExternalMemoryImageCreateInfoNV = 1000056000,
        ExportMemoryAllocateInfoNV = 1000056001,
        ImportMemory_Win32_HandleInfoNV = 1000057000,
        ExportMemory_Win32_HandleInfoNV = 1000057001,
        Win32_KeyedMutexAcquireReleaseInfoNV = 1000058000,
        ValidationFlagsEXT = 1000061000,
        ViSurfaceCreateInfoNN = 1000062000,
        PhysicalDeviceTextureCompressionAstcHdrFeaturesEXT = 1000066000,
        ImageViewAstcDecodeModeEXT = 1000067000,
        PhysicalDeviceAstcDecodeFeaturesEXT = 1000067001,
        ImportMemory_Win32_HandleInfoKHR = 1000073000,
        ExportMemory_Win32_HandleInfoKHR = 1000073001,
        Memory_Win32_HandlePropertiesKHR = 1000073002,
        MemoryGet_Win32_HandleInfoKHR = 1000073003,
        ImportMemoryFdInfoKHR = 1000074000,
        MemoryFdPropertiesKHR = 1000074001,
        MemoryGetFdInfoKHR = 1000074002,
        Win32_KeyedMutexAcquireReleaseInfoKHR = 1000075000,
        ImportSemaphore_Win32_HandleInfoKHR = 1000078000,
        ExportSemaphore_Win32_HandleInfoKHR = 1000078001,
        D3D12_FenceSubmitInfoKHR = 1000078002,
        SemaphoreGet_Win32_HandleInfoKHR = 1000078003,
        ImportSemaphoreFdInfoKHR = 1000079000,
        SemaphoreGetFdInfoKHR = 1000079001,
        PhysicalDevicePushDescriptorPropertiesKHR = 1000080000,
        CommandBufferInheritanceConditionalRenderingInfoEXT = 1000081000,
        PhysicalDeviceConditionalRenderingFeaturesEXT = 1000081001,
        ConditionalRenderingBeginInfoEXT = 1000081002,
        PresentRegionsKHR = 1000084000,
        PipelineViewportWScalingStateCreateInfoNV = 1000087000,
        SurfaceCapabilities_2_EXT = 1000090000,
        DisplayPowerInfoEXT = 1000091000,
        DeviceEventInfoEXT = 1000091001,
        DisplayEventInfoEXT = 1000091002,
        SwapchainCounterCreateInfoEXT = 1000091003,
        PresentTimesInfoGOOGLE = 1000092000,
        PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX = 1000097000,
        PipelineViewportSwizzleStateCreateInfoNV = 1000098000,
        PhysicalDeviceDiscardRectanglePropertiesEXT = 1000099000,
        PipelineDiscardRectangleStateCreateInfoEXT = 1000099001,
        PhysicalDeviceConservativeRasterizationPropertiesEXT = 1000101000,
        PipelineRasterizationConservativeStateCreateInfoEXT = 1000101001,
        PhysicalDeviceDepthClipEnableFeaturesEXT = 1000102000,
        PipelineRasterizationDepthClipStateCreateInfoEXT = 1000102001,
        HdrMetadataEXT = 1000105000,
        SharedPresentSurfaceCapabilitiesKHR = 1000111000,
        ImportFence_Win32_HandleInfoKHR = 1000114000,
        ExportFence_Win32_HandleInfoKHR = 1000114001,
        FenceGet_Win32_HandleInfoKHR = 1000114002,
        ImportFenceFdInfoKHR = 1000115000,
        FenceGetFdInfoKHR = 1000115001,
        PhysicalDevicePerformanceQueryFeaturesKHR = 1000116000,
        PhysicalDevicePerformanceQueryPropertiesKHR = 1000116001,
        QueryPoolPerformanceCreateInfoKHR = 1000116002,
        PerformanceQuerySubmitInfoKHR = 1000116003,
        AcquireProfilingLockInfoKHR = 1000116004,
        PerformanceCounterKHR = 1000116005,
        PerformanceCounterDescriptionKHR = 1000116006,
        PhysicalDeviceSurfaceInfo_2_KHR = 1000119000,
        SurfaceCapabilities_2_KHR = 1000119001,
        SurfaceFormat_2_KHR = 1000119002,
        DisplayProperties_2_KHR = 1000121000,
        DisplayPlaneProperties_2_KHR = 1000121001,
        DisplayModeProperties_2_KHR = 1000121002,
        DisplayPlaneInfo_2_KHR = 1000121003,
        DisplayPlaneCapabilities_2_KHR = 1000121004,
        IosSurfaceCreateInfoMVK = 1000122000,
        MacosSurfaceCreateInfoMVK = 1000123000,
        DebugUtilsObjectNameInfoEXT = 1000128000,
        DebugUtilsObjectTagInfoEXT = 1000128001,
        DebugUtilsLabelEXT = 1000128002,
        DebugUtilsMessengerCallbackDataEXT = 1000128003,
        DebugUtilsMessengerCreateInfoEXT = 1000128004,
        AndroidHardwareBufferUsageANDROID = 1000129000,
        AndroidHardwareBufferPropertiesANDROID = 1000129001,
        AndroidHardwareBufferFormatPropertiesANDROID = 1000129002,
        ImportAndroidHardwareBufferInfoANDROID = 1000129003,
        MemoryGetAndroidHardwareBufferInfoANDROID = 1000129004,
        ExternalFormatANDROID = 1000129005,
        PhysicalDeviceInlineUniformBlockFeaturesEXT = 1000138000,
        PhysicalDeviceInlineUniformBlockPropertiesEXT = 1000138001,
        WriteDescriptorSetInlineUniformBlockEXT = 1000138002,
        DescriptorPoolInlineUniformBlockCreateInfoEXT = 1000138003,
        SampleLocationsInfoEXT = 1000143000,
        RenderPassSampleLocationsBeginInfoEXT = 1000143001,
        PipelineSampleLocationsStateCreateInfoEXT = 1000143002,
        PhysicalDeviceSampleLocationsPropertiesEXT = 1000143003,
        MultisamplePropertiesEXT = 1000143004,
        PhysicalDeviceBlendOperationAdvancedFeaturesEXT = 1000148000,
        PhysicalDeviceBlendOperationAdvancedPropertiesEXT = 1000148001,
        PipelineColorBlendAdvancedStateCreateInfoEXT = 1000148002,
        PipelineCoverageToColorStateCreateInfoNV = 1000149000,
        BindAccelerationStructureMemoryInfoKHR = 1000165006,
        WriteDescriptorSetAccelerationStructureKHR = 1000165007,
        AccelerationStructureBuildGeometryInfoKHR = 1000150000,
        AccelerationStructureCreateGeometryTypeInfoKHR = 1000150001,
        AccelerationStructureDeviceAddressInfoKHR = 1000150002,
        AccelerationStructureGeometryAabbsDataKHR = 1000150003,
        AccelerationStructureGeometryInstancesDataKHR = 1000150004,
        AccelerationStructureGeometryTrianglesDataKHR = 1000150005,
        AccelerationStructureGeometryKHR = 1000150006,
        AccelerationStructureInfoKHR = 1000150007,
        AccelerationStructureMemoryRequirementsInfoKHR = 1000150008,
        AccelerationStructureVersionKHR = 1000150009,
        CopyAccelerationStructureInfoKHR = 1000150010,
        CopyAccelerationStructureToMemoryInfoKHR = 1000150011,
        CopyMemoryToAccelerationStructureInfoKHR = 1000150012,
        PhysicalDeviceRayTracingFeaturesKHR = 1000150013,
        PhysicalDeviceRayTracingPropertiesKHR = 1000150014,
        RayTracingPipelineCreateInfoKHR = 1000150015,
        RayTracingShaderGroupCreateInfoKHR = 1000150016,
        AccelerationStructureCreateInfoKHR = 1000150017,
        RayTracingPipelineInterfaceCreateInfoKHR = 1000150018,
        PipelineCoverageModulationStateCreateInfoNV = 1000152000,
        PhysicalDeviceShaderSmBuiltinsFeaturesNV = 1000154000,
        PhysicalDeviceShaderSmBuiltinsPropertiesNV = 1000154001,
        DrmFormatModifierPropertiesListEXT = 1000158000,
        DrmFormatModifierPropertiesEXT = 1000158001,
        PhysicalDeviceImageDrmFormatModifierInfoEXT = 1000158002,
        ImageDrmFormatModifierListCreateInfoEXT = 1000158003,
        ImageDrmFormatModifierExplicitCreateInfoEXT = 1000158004,
        ImageDrmFormatModifierPropertiesEXT = 1000158005,
        ValidationCacheCreateInfoEXT = 1000160000,
        ShaderModuleValidationCacheCreateInfoEXT = 1000160001,
        PipelineViewportShadingRateImageStateCreateInfoNV = 1000164000,
        PhysicalDeviceShadingRateImageFeaturesNV = 1000164001,
        PhysicalDeviceShadingRateImagePropertiesNV = 1000164002,
        PipelineViewportCoarseSampleOrderStateCreateInfoNV = 1000164005,
        RayTracingPipelineCreateInfoNV = 1000165000,
        AccelerationStructureCreateInfoNV = 1000165001,
        GeometryNV = 1000165003,
        GeometryTrianglesNV = 1000165004,
        GeometryAabbNV = 1000165005,
        AccelerationStructureMemoryRequirementsInfoNV = 1000165008,
        PhysicalDeviceRayTracingPropertiesNV = 1000165009,
        RayTracingShaderGroupCreateInfoNV = 1000165011,
        AccelerationStructureInfoNV = 1000165012,
        PhysicalDeviceRepresentativeFragmentTestFeaturesNV = 1000166000,
        PipelineRepresentativeFragmentTestStateCreateInfoNV = 1000166001,
        PhysicalDeviceImageViewImageFormatInfoEXT = 1000170000,
        FilterCubicImageViewImageFormatPropertiesEXT = 1000170001,
        DeviceQueueGlobalPriorityCreateInfoEXT = 1000174000,
        ImportMemoryHostPointerInfoEXT = 1000178000,
        MemoryHostPointerPropertiesEXT = 1000178001,
        PhysicalDeviceExternalMemoryHostPropertiesEXT = 1000178002,
        PhysicalDeviceShaderClockFeaturesKHR = 1000181000,
        PipelineCompilerControlCreateInfoAMD = 1000183000,
        CalibratedTimestampInfoEXT = 1000184000,
        PhysicalDeviceShaderCorePropertiesAMD = 1000185000,
        DeviceMemoryOverallocationCreateInfoAMD = 1000189000,
        PhysicalDeviceVertexAttributeDivisorPropertiesEXT = 1000190000,
        PipelineVertexInputDivisorStateCreateInfoEXT = 1000190001,
        PhysicalDeviceVertexAttributeDivisorFeaturesEXT = 1000190002,
        PresentFrameTokenGGP = 1000191000,
        PipelineCreationFeedbackCreateInfoEXT = 1000192000,
        PhysicalDeviceComputeShaderDerivativesFeaturesNV = 1000201000,
        PhysicalDeviceMeshShaderFeaturesNV = 1000202000,
        PhysicalDeviceMeshShaderPropertiesNV = 1000202001,
        PhysicalDeviceFragmentShaderBarycentricFeaturesNV = 1000203000,
        PhysicalDeviceShaderImageFootprintFeaturesNV = 1000204000,
        PipelineViewportExclusiveScissorStateCreateInfoNV = 1000205000,
        PhysicalDeviceExclusiveScissorFeaturesNV = 1000205002,
        CheckpointDataNV = 1000206000,
        QueueFamilyCheckpointPropertiesNV = 1000206001,
        PhysicalDeviceShaderIntegerFunctions_2_FeaturesINTEL = 1000209000,
        QueryPoolCreateInfoINTEL = 1000210000,
        InitializePerformanceApiInfoINTEL = 1000210001,
        PerformanceMarkerInfoINTEL = 1000210002,
        PerformanceStreamMarkerInfoINTEL = 1000210003,
        PerformanceOverrideInfoINTEL = 1000210004,
        PerformanceConfigurationAcquireInfoINTEL = 1000210005,
        PhysicalDevicePciBusInfoPropertiesEXT = 1000212000,
        DisplayNativeHdrSurfaceCapabilitiesAMD = 1000213000,
        SwapchainDisplayNativeHdrCreateInfoAMD = 1000213001,
        ImagepipeSurfaceCreateInfoFUCHSIA = 1000214000,
        MetalSurfaceCreateInfoEXT = 1000217000,
        PhysicalDeviceFragmentDensityMapFeaturesEXT = 1000218000,
        PhysicalDeviceFragmentDensityMapPropertiesEXT = 1000218001,
        RenderPassFragmentDensityMapCreateInfoEXT = 1000218002,
        PhysicalDeviceSubgroupSizeControlPropertiesEXT = 1000225000,
        PipelineShaderStageRequiredSubgroupSizeCreateInfoEXT = 1000225001,
        PhysicalDeviceSubgroupSizeControlFeaturesEXT = 1000225002,
        PhysicalDeviceShaderCoreProperties_2_AMD = 1000227000,
        PhysicalDeviceCoherentMemoryFeaturesAMD = 1000229000,
        PhysicalDeviceMemoryBudgetPropertiesEXT = 1000237000,
        PhysicalDeviceMemoryPriorityFeaturesEXT = 1000238000,
        MemoryPriorityAllocateInfoEXT = 1000238001,
        SurfaceProtectedCapabilitiesKHR = 1000239000,
        PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV = 1000240000,
        PhysicalDeviceBufferDeviceAddressFeaturesEXT = 1000244000,
        BufferDeviceAddressCreateInfoEXT = 1000244002,
        PhysicalDeviceToolPropertiesEXT = 1000245000,
        ValidationFeaturesEXT = 1000247000,
        PhysicalDeviceCooperativeMatrixFeaturesNV = 1000249000,
        CooperativeMatrixPropertiesNV = 1000249001,
        PhysicalDeviceCooperativeMatrixPropertiesNV = 1000249002,
        PhysicalDeviceCoverageReductionModeFeaturesNV = 1000250000,
        PipelineCoverageReductionStateCreateInfoNV = 1000250001,
        FramebufferMixedSamplesCombinationNV = 1000250002,
        PhysicalDeviceFragmentShaderInterlockFeaturesEXT = 1000251000,
        PhysicalDeviceYcbcrImageArraysFeaturesEXT = 1000252000,
        SurfaceFullScreenExclusiveInfoEXT = 1000255000,
        SurfaceCapabilitiesFullScreenExclusiveEXT = 1000255002,
        SurfaceFullScreenExclusive_Win32_InfoEXT = 1000255001,
        HeadlessSurfaceCreateInfoEXT = 1000256000,
        PhysicalDeviceLineRasterizationFeaturesEXT = 1000259000,
        PipelineRasterizationLineStateCreateInfoEXT = 1000259001,
        PhysicalDeviceLineRasterizationPropertiesEXT = 1000259002,
        PhysicalDeviceIndexType_Uint8_FeaturesEXT = 1000265000,
        DeferredOperationInfoKHR = 1000268000,
        PhysicalDevicePipelineExecutablePropertiesFeaturesKHR = 1000269000,
        PipelineInfoKHR = 1000269001,
        PipelineExecutablePropertiesKHR = 1000269002,
        PipelineExecutableInfoKHR = 1000269003,
        PipelineExecutableStatisticKHR = 1000269004,
        PipelineExecutableInternalRepresentationKHR = 1000269005,
        PhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT = 1000276000,
        PhysicalDeviceDeviceGeneratedCommandsPropertiesNV = 1000277000,
        GraphicsShaderGroupCreateInfoNV = 1000277001,
        GraphicsPipelineShaderGroupsCreateInfoNV = 1000277002,
        IndirectCommandsLayoutTokenNV = 1000277003,
        IndirectCommandsLayoutCreateInfoNV = 1000277004,
        GeneratedCommandsInfoNV = 1000277005,
        GeneratedCommandsMemoryRequirementsInfoNV = 1000277006,
        PhysicalDeviceDeviceGeneratedCommandsFeaturesNV = 1000277007,
        PhysicalDeviceTexelBufferAlignmentFeaturesEXT = 1000281000,
        PhysicalDeviceTexelBufferAlignmentPropertiesEXT = 1000281001,
        CommandBufferInheritanceRenderPassTransformInfoQCOM = 1000282000,
        RenderPassTransformBeginInfoQCOM = 1000282001,
        PipelineLibraryCreateInfoKHR = 1000290000,
        PhysicalDevicePipelineCreationCacheControlFeaturesEXT = 1000297000,
        PhysicalDeviceDiagnosticsConfigFeaturesNV = 1000300000,
        DeviceDiagnosticsConfigCreateInfoNV = 1000300001,
        ReservedQCOM = 1000309000,
    };

    enum class SystemAllocationScope {
        Command = 0,
        Object = 1,
        Cache = 2,
        Device = 3,
        Instance = 4,
    };

    enum class InternalAllocationType {
        Executable = 0,
    };

    enum class SamplerAddressMode {
        Repeat = 0,
        MirroredRepeat = 1,
        ClampToEdge = 2,
        ClampToBorder = 3,
    };

    enum class Filter {
        Nearest = 0,
        Linear = 1,
        CubicIMG = 1000015000,
    };

    enum class SamplerMipmapMode {
        Nearest = 0,
        Linear = 1,
    };

    enum class VertexInputRate {
        Vertex = 0,
        Instance = 1,
    };

    enum class PipelineStageFlags : uint32_t {
        None = 0,
        TopOfPipe = 1,
        DrawIndirect = 2,
        VertexInput = 4,
        VertexShader = 8,
        TessellationControlShader = 16,
        TessellationEvaluationShader = 32,
        GeometryShader = 64,
        FragmentShader = 128,
        EarlyFragmentTests = 256,
        LateFragmentTests = 512,
        ColorAttachmentOutput = 1024,
        ComputeShader = 2048,
        Transfer = 4096,
        BottomOfPipe = 8192,
        Host = 16384,
        AllGraphics = 32768,
        AllCommands = 65536,
    };

    inline PipelineStageFlags operator | (PipelineStageFlags a, PipelineStageFlags b) {
        return static_cast<PipelineStageFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline PipelineStageFlags& operator |= (PipelineStageFlags& a, PipelineStageFlags b) {
        a = static_cast<PipelineStageFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline PipelineStageFlags operator & (PipelineStageFlags a, PipelineStageFlags b) {
        return static_cast<PipelineStageFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline PipelineStageFlags& operator &= (PipelineStageFlags& a, PipelineStageFlags& b) {
        a = static_cast<PipelineStageFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (PipelineStageFlags& a, PipelineStageFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (PipelineStageFlags& a, PipelineStageFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class SparseImageFormatFlags : uint32_t {
        None = 0,
        SingleMiptail = 1,
        AlignedMipSize = 2,
        NonstandardBlockSize = 4,
    };

    inline SparseImageFormatFlags operator | (SparseImageFormatFlags a, SparseImageFormatFlags b) {
        return static_cast<SparseImageFormatFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline SparseImageFormatFlags& operator |= (SparseImageFormatFlags& a, SparseImageFormatFlags b) {
        a = static_cast<SparseImageFormatFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline SparseImageFormatFlags operator & (SparseImageFormatFlags a, SparseImageFormatFlags b) {
        return static_cast<SparseImageFormatFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline SparseImageFormatFlags& operator &= (SparseImageFormatFlags& a, SparseImageFormatFlags& b) {
        a = static_cast<SparseImageFormatFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (SparseImageFormatFlags& a, SparseImageFormatFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (SparseImageFormatFlags& a, SparseImageFormatFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class SampleCountFlags : uint32_t {
        None = 0,
        _1 = 1,
        _2 = 2,
        _4 = 4,
        _8 = 8,
        _16 = 16,
        _32 = 32,
        _64 = 64,
    };

    inline SampleCountFlags operator | (SampleCountFlags a, SampleCountFlags b) {
        return static_cast<SampleCountFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline SampleCountFlags& operator |= (SampleCountFlags& a, SampleCountFlags b) {
        a = static_cast<SampleCountFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline SampleCountFlags operator & (SampleCountFlags a, SampleCountFlags b) {
        return static_cast<SampleCountFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline SampleCountFlags& operator &= (SampleCountFlags& a, SampleCountFlags& b) {
        a = static_cast<SampleCountFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (SampleCountFlags& a, SampleCountFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (SampleCountFlags& a, SampleCountFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class AttachmentDescriptionFlags : uint32_t {
        None = 0,
        MayAlias = 1,
    };

    inline AttachmentDescriptionFlags operator | (AttachmentDescriptionFlags a, AttachmentDescriptionFlags b) {
        return static_cast<AttachmentDescriptionFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline AttachmentDescriptionFlags& operator |= (AttachmentDescriptionFlags& a, AttachmentDescriptionFlags b) {
        a = static_cast<AttachmentDescriptionFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline AttachmentDescriptionFlags operator & (AttachmentDescriptionFlags a, AttachmentDescriptionFlags b) {
        return static_cast<AttachmentDescriptionFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline AttachmentDescriptionFlags& operator &= (AttachmentDescriptionFlags& a, AttachmentDescriptionFlags& b) {
        a = static_cast<AttachmentDescriptionFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (AttachmentDescriptionFlags& a, AttachmentDescriptionFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (AttachmentDescriptionFlags& a, AttachmentDescriptionFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class DescriptorPoolCreateFlags : uint32_t {
        None = 0,
        FreeDescriptorSet = 1,
    };

    inline DescriptorPoolCreateFlags operator | (DescriptorPoolCreateFlags a, DescriptorPoolCreateFlags b) {
        return static_cast<DescriptorPoolCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline DescriptorPoolCreateFlags& operator |= (DescriptorPoolCreateFlags& a, DescriptorPoolCreateFlags b) {
        a = static_cast<DescriptorPoolCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline DescriptorPoolCreateFlags operator & (DescriptorPoolCreateFlags a, DescriptorPoolCreateFlags b) {
        return static_cast<DescriptorPoolCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline DescriptorPoolCreateFlags& operator &= (DescriptorPoolCreateFlags& a, DescriptorPoolCreateFlags& b) {
        a = static_cast<DescriptorPoolCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (DescriptorPoolCreateFlags& a, DescriptorPoolCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (DescriptorPoolCreateFlags& a, DescriptorPoolCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class DependencyFlags : uint32_t {
        None = 0,
        ByRegion = 1,
    };

    inline DependencyFlags operator | (DependencyFlags a, DependencyFlags b) {
        return static_cast<DependencyFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline DependencyFlags& operator |= (DependencyFlags& a, DependencyFlags b) {
        a = static_cast<DependencyFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline DependencyFlags operator & (DependencyFlags a, DependencyFlags b) {
        return static_cast<DependencyFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline DependencyFlags& operator &= (DependencyFlags& a, DependencyFlags& b) {
        a = static_cast<DependencyFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (DependencyFlags& a, DependencyFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (DependencyFlags& a, DependencyFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ObjectType {
        Unknown = 0,
        Instance = 1,
        PhysicalDevice = 2,
        Device = 3,
        Queue = 4,
        Semaphore = 5,
        CommandBuffer = 6,
        Fence = 7,
        DeviceMemory = 8,
        Buffer = 9,
        Image = 10,
        Event = 11,
        QueryPool = 12,
        BufferView = 13,
        ImageView = 14,
        ShaderModule = 15,
        PipelineCache = 16,
        PipelineLayout = 17,
        RenderPass = 18,
        Pipeline = 19,
        DescriptorSetLayout = 20,
        Sampler = 21,
        DescriptorPool = 22,
        DescriptorSet = 23,
        Framebuffer = 24,
        CommandPool = 25,
        SurfaceKHR = 1000000000,
        SwapchainKHR = 1000001000,
        DisplayKHR = 1000002000,
        DisplayModeKHR = 1000002001,
        DebugReportCallbackEXT = 1000011000,
        DebugUtilsMessengerEXT = 1000128000,
        AccelerationStructureKHR = 1000165000,
        ValidationCacheEXT = 1000160000,
        PerformanceConfigurationINTEL = 1000210000,
        DeferredOperationKHR = 1000268000,
        IndirectCommandsLayoutNV = 1000277000,
    };

    enum class IndirectCommandsLayoutUsageFlags : uint32_t {
        None = 0,
        ExplicitPreprocess = 1,
        IndexedSequences = 2,
        UnorderedSequences = 4,
    };

    inline IndirectCommandsLayoutUsageFlags operator | (IndirectCommandsLayoutUsageFlags a, IndirectCommandsLayoutUsageFlags b) {
        return static_cast<IndirectCommandsLayoutUsageFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline IndirectCommandsLayoutUsageFlags& operator |= (IndirectCommandsLayoutUsageFlags& a, IndirectCommandsLayoutUsageFlags b) {
        a = static_cast<IndirectCommandsLayoutUsageFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline IndirectCommandsLayoutUsageFlags operator & (IndirectCommandsLayoutUsageFlags a, IndirectCommandsLayoutUsageFlags b) {
        return static_cast<IndirectCommandsLayoutUsageFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline IndirectCommandsLayoutUsageFlags& operator &= (IndirectCommandsLayoutUsageFlags& a, IndirectCommandsLayoutUsageFlags& b) {
        a = static_cast<IndirectCommandsLayoutUsageFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (IndirectCommandsLayoutUsageFlags& a, IndirectCommandsLayoutUsageFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (IndirectCommandsLayoutUsageFlags& a, IndirectCommandsLayoutUsageFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class IndirectCommandsTokenType {
        ShaderGroup = 0,
        StateFlags = 1,
        IndexBuffer = 2,
        VertexBuffer = 3,
        PushConstant = 4,
        DrawIndexed = 5,
        Draw = 6,
        DrawTasks = 7,
    };

    enum class IndirectStateFlags : uint32_t {
        None = 0,
        Frontface = 1,
    };

    inline IndirectStateFlags operator | (IndirectStateFlags a, IndirectStateFlags b) {
        return static_cast<IndirectStateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline IndirectStateFlags& operator |= (IndirectStateFlags& a, IndirectStateFlags b) {
        a = static_cast<IndirectStateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline IndirectStateFlags operator & (IndirectStateFlags a, IndirectStateFlags b) {
        return static_cast<IndirectStateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline IndirectStateFlags& operator &= (IndirectStateFlags& a, IndirectStateFlags& b) {
        a = static_cast<IndirectStateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (IndirectStateFlags& a, IndirectStateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (IndirectStateFlags& a, IndirectStateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class DescriptorUpdateTemplateType {
        DescriptorSet = 0,
    };

    enum class ViewportCoordinateSwizzle {
        PositiveX = 0,
        NegativeX = 1,
        PositiveY = 2,
        NegativeY = 3,
        PositiveZ = 4,
        NegativeZ = 5,
        PositiveW = 6,
        NegativeW = 7,
    };

    enum class DiscardRectangleMode {
        Inclusive = 0,
        Exclusive = 1,
    };

    enum class SubpassDescriptionFlags : uint32_t {
        None = 0,
    };

    inline SubpassDescriptionFlags operator | (SubpassDescriptionFlags a, SubpassDescriptionFlags b) {
        return static_cast<SubpassDescriptionFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline SubpassDescriptionFlags& operator |= (SubpassDescriptionFlags& a, SubpassDescriptionFlags b) {
        a = static_cast<SubpassDescriptionFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline SubpassDescriptionFlags operator & (SubpassDescriptionFlags a, SubpassDescriptionFlags b) {
        return static_cast<SubpassDescriptionFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline SubpassDescriptionFlags& operator &= (SubpassDescriptionFlags& a, SubpassDescriptionFlags& b) {
        a = static_cast<SubpassDescriptionFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (SubpassDescriptionFlags& a, SubpassDescriptionFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (SubpassDescriptionFlags& a, SubpassDescriptionFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class PointClippingBehavior {
        AllClipPlanes = 0,
        UserClipPlanesOnly = 1,
    };

    enum class CoverageModulationMode {
        None = 0,
        Rgb = 1,
        Alpha = 2,
        Rgba = 3,
    };

    enum class CoverageReductionMode {
        Merge = 0,
        Truncate = 1,
    };

    enum class ValidationCacheHeaderVersion {
        One = 1,
    };

    enum class ShaderInfoType {
        Statistics = 0,
        Binary = 1,
        Disassembly = 2,
    };

    enum class QueueGlobalPriority {
        Low = 128,
        Medium = 256,
        High = 512,
        Realtime = 1024,
    };

    enum class TimeDomain {
        Device = 0,
        ClockMonotonic = 1,
        ClockMonotonicRaw = 2,
        QueryPerformanceCounter = 3,
    };

    enum class ConservativeRasterizationMode {
        Disabled = 0,
        Overestimate = 1,
        Underestimate = 2,
    };

    enum class ResolveModeFlags : uint32_t {
        None = 0,
        SampleZero = 1,
        Average = 2,
        Min = 4,
        Max = 8,
    };

    inline ResolveModeFlags operator | (ResolveModeFlags a, ResolveModeFlags b) {
        return static_cast<ResolveModeFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ResolveModeFlags& operator |= (ResolveModeFlags& a, ResolveModeFlags b) {
        a = static_cast<ResolveModeFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ResolveModeFlags operator & (ResolveModeFlags a, ResolveModeFlags b) {
        return static_cast<ResolveModeFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ResolveModeFlags& operator &= (ResolveModeFlags& a, ResolveModeFlags& b) {
        a = static_cast<ResolveModeFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ResolveModeFlags& a, ResolveModeFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ResolveModeFlags& a, ResolveModeFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class DescriptorBindingFlags : uint32_t {
        None = 0,
        UpdateAfterBind = 1,
        UpdateUnusedWhilePending = 2,
        PartiallyBound = 4,
        VariableDescriptorCount = 8,
    };

    inline DescriptorBindingFlags operator | (DescriptorBindingFlags a, DescriptorBindingFlags b) {
        return static_cast<DescriptorBindingFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline DescriptorBindingFlags& operator |= (DescriptorBindingFlags& a, DescriptorBindingFlags b) {
        a = static_cast<DescriptorBindingFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline DescriptorBindingFlags operator & (DescriptorBindingFlags a, DescriptorBindingFlags b) {
        return static_cast<DescriptorBindingFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline DescriptorBindingFlags& operator &= (DescriptorBindingFlags& a, DescriptorBindingFlags& b) {
        a = static_cast<DescriptorBindingFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (DescriptorBindingFlags& a, DescriptorBindingFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (DescriptorBindingFlags& a, DescriptorBindingFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ConditionalRenderingFlags : uint32_t {
        None = 0,
        Inverted = 1,
    };

    inline ConditionalRenderingFlags operator | (ConditionalRenderingFlags a, ConditionalRenderingFlags b) {
        return static_cast<ConditionalRenderingFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ConditionalRenderingFlags& operator |= (ConditionalRenderingFlags& a, ConditionalRenderingFlags b) {
        a = static_cast<ConditionalRenderingFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ConditionalRenderingFlags operator & (ConditionalRenderingFlags a, ConditionalRenderingFlags b) {
        return static_cast<ConditionalRenderingFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ConditionalRenderingFlags& operator &= (ConditionalRenderingFlags& a, ConditionalRenderingFlags& b) {
        a = static_cast<ConditionalRenderingFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ConditionalRenderingFlags& a, ConditionalRenderingFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ConditionalRenderingFlags& a, ConditionalRenderingFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class SemaphoreType {
        Binary = 0,
        Timeline = 1,
    };

    enum class GeometryFlags : uint32_t {
        None = 0,
        Opaque = 1,
        NoDuplicateAnyHitInvocation = 2,
    };

    inline GeometryFlags operator | (GeometryFlags a, GeometryFlags b) {
        return static_cast<GeometryFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline GeometryFlags& operator |= (GeometryFlags& a, GeometryFlags b) {
        a = static_cast<GeometryFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline GeometryFlags operator & (GeometryFlags a, GeometryFlags b) {
        return static_cast<GeometryFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline GeometryFlags& operator &= (GeometryFlags& a, GeometryFlags& b) {
        a = static_cast<GeometryFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (GeometryFlags& a, GeometryFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (GeometryFlags& a, GeometryFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class GeometryInstanceFlags : uint32_t {
        None = 0,
        TriangleFacingCullDisable = 1,
        TriangleFrontCounterclockwise = 2,
        ForceOpaque = 4,
        ForceNoOpaque = 8,
    };

    inline GeometryInstanceFlags operator | (GeometryInstanceFlags a, GeometryInstanceFlags b) {
        return static_cast<GeometryInstanceFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline GeometryInstanceFlags& operator |= (GeometryInstanceFlags& a, GeometryInstanceFlags b) {
        a = static_cast<GeometryInstanceFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline GeometryInstanceFlags operator & (GeometryInstanceFlags a, GeometryInstanceFlags b) {
        return static_cast<GeometryInstanceFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline GeometryInstanceFlags& operator &= (GeometryInstanceFlags& a, GeometryInstanceFlags& b) {
        a = static_cast<GeometryInstanceFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (GeometryInstanceFlags& a, GeometryInstanceFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (GeometryInstanceFlags& a, GeometryInstanceFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class BuildAccelerationStructureFlags : uint32_t {
        None = 0,
        AllowUpdate = 1,
        AllowCompaction = 2,
        PreferFastTrace = 4,
        PreferFastBuild = 8,
        LowMemory = 16,
    };

    inline BuildAccelerationStructureFlags operator | (BuildAccelerationStructureFlags a, BuildAccelerationStructureFlags b) {
        return static_cast<BuildAccelerationStructureFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline BuildAccelerationStructureFlags& operator |= (BuildAccelerationStructureFlags& a, BuildAccelerationStructureFlags b) {
        a = static_cast<BuildAccelerationStructureFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline BuildAccelerationStructureFlags operator & (BuildAccelerationStructureFlags a, BuildAccelerationStructureFlags b) {
        return static_cast<BuildAccelerationStructureFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline BuildAccelerationStructureFlags& operator &= (BuildAccelerationStructureFlags& a, BuildAccelerationStructureFlags& b) {
        a = static_cast<BuildAccelerationStructureFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (BuildAccelerationStructureFlags& a, BuildAccelerationStructureFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (BuildAccelerationStructureFlags& a, BuildAccelerationStructureFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class CopyAccelerationStructureMode {
        Clone = 0,
        Compact = 1,
        Serialize = 2,
        Deserialize = 3,
    };

    enum class AccelerationStructureType {
        TopLevel = 0,
        BottomLevel = 1,
    };

    enum class GeometryType {
        Triangles = 0,
        Aabbs = 1,
        Instances = 1000150000,
    };

    enum class RayTracingShaderGroupType {
        General = 0,
        TrianglesHitGroup = 1,
        ProceduralHitGroup = 2,
    };

    enum class AccelerationStructureMemoryRequirementsType {
        Object = 0,
        BuildScratch = 1,
        UpdateScratch = 2,
    };

    enum class AccelerationStructureBuildType {
        Host = 0,
        Device = 1,
        HostOrDevice = 2,
    };

    enum class MemoryOverallocationBehavior {
        Default = 0,
        Allowed = 1,
        Disallowed = 2,
    };

    enum class Scope {
        Device = 1,
        Workgroup = 2,
        Subgroup = 3,
        QueueFamily = 5,
    };

    enum class ComponentType {
        Float16_ = 0,
        Float32_ = 1,
        Float64_ = 2,
        Sint8_ = 3,
        Sint16_ = 4,
        Sint32_ = 5,
        Sint64_ = 6,
        Uint8_ = 7,
        Uint16_ = 8,
        Uint32_ = 9,
        Uint64_ = 10,
    };

    enum class DeviceDiagnosticsConfigFlags : uint32_t {
        None = 0,
        EnableShaderDebugInfo = 1,
        EnableResourceTracking = 2,
        EnableAutomaticCheckpoints = 4,
    };

    inline DeviceDiagnosticsConfigFlags operator | (DeviceDiagnosticsConfigFlags a, DeviceDiagnosticsConfigFlags b) {
        return static_cast<DeviceDiagnosticsConfigFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline DeviceDiagnosticsConfigFlags& operator |= (DeviceDiagnosticsConfigFlags& a, DeviceDiagnosticsConfigFlags b) {
        a = static_cast<DeviceDiagnosticsConfigFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline DeviceDiagnosticsConfigFlags operator & (DeviceDiagnosticsConfigFlags a, DeviceDiagnosticsConfigFlags b) {
        return static_cast<DeviceDiagnosticsConfigFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline DeviceDiagnosticsConfigFlags& operator &= (DeviceDiagnosticsConfigFlags& a, DeviceDiagnosticsConfigFlags& b) {
        a = static_cast<DeviceDiagnosticsConfigFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (DeviceDiagnosticsConfigFlags& a, DeviceDiagnosticsConfigFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (DeviceDiagnosticsConfigFlags& a, DeviceDiagnosticsConfigFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class PipelineCreationFeedbackFlags : uint32_t {
        None = 0,
        Valid = 1,
        ApplicationPipelineCacheHit = 2,
        BasePipelineAcceleration = 4,
    };

    inline PipelineCreationFeedbackFlags operator | (PipelineCreationFeedbackFlags a, PipelineCreationFeedbackFlags b) {
        return static_cast<PipelineCreationFeedbackFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline PipelineCreationFeedbackFlags& operator |= (PipelineCreationFeedbackFlags& a, PipelineCreationFeedbackFlags b) {
        a = static_cast<PipelineCreationFeedbackFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline PipelineCreationFeedbackFlags operator & (PipelineCreationFeedbackFlags a, PipelineCreationFeedbackFlags b) {
        return static_cast<PipelineCreationFeedbackFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline PipelineCreationFeedbackFlags& operator &= (PipelineCreationFeedbackFlags& a, PipelineCreationFeedbackFlags& b) {
        a = static_cast<PipelineCreationFeedbackFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (PipelineCreationFeedbackFlags& a, PipelineCreationFeedbackFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (PipelineCreationFeedbackFlags& a, PipelineCreationFeedbackFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class PerformanceCounterScope {
        CommandBuffer = 0,
        RenderPass = 1,
        Command = 2,
    };

    enum class PerformanceCounterUnit {
        Generic = 0,
        Percentage = 1,
        Nanoseconds = 2,
        Bytes = 3,
        BytesPerSecond = 4,
        Kelvin = 5,
        Watts = 6,
        Volts = 7,
        Amps = 8,
        Hertz = 9,
        Cycles = 10,
    };

    enum class PerformanceCounterStorage {
        Int32_ = 0,
        Int64_ = 1,
        Uint32_ = 2,
        Uint64_ = 3,
        Float32_ = 4,
        Float64_ = 5,
    };

    enum class PerformanceCounterDescriptionFlags : uint32_t {
        None = 0,
        PerformanceImpacting = 1,
        ConcurrentlyImpacted = 2,
    };

    inline PerformanceCounterDescriptionFlags operator | (PerformanceCounterDescriptionFlags a, PerformanceCounterDescriptionFlags b) {
        return static_cast<PerformanceCounterDescriptionFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline PerformanceCounterDescriptionFlags& operator |= (PerformanceCounterDescriptionFlags& a, PerformanceCounterDescriptionFlags b) {
        a = static_cast<PerformanceCounterDescriptionFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline PerformanceCounterDescriptionFlags operator & (PerformanceCounterDescriptionFlags a, PerformanceCounterDescriptionFlags b) {
        return static_cast<PerformanceCounterDescriptionFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline PerformanceCounterDescriptionFlags& operator &= (PerformanceCounterDescriptionFlags& a, PerformanceCounterDescriptionFlags& b) {
        a = static_cast<PerformanceCounterDescriptionFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (PerformanceCounterDescriptionFlags& a, PerformanceCounterDescriptionFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (PerformanceCounterDescriptionFlags& a, PerformanceCounterDescriptionFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class AcquireProfilingLockFlags : uint32_t {
        None = 0,
    };

    inline AcquireProfilingLockFlags operator | (AcquireProfilingLockFlags a, AcquireProfilingLockFlags b) {
        return static_cast<AcquireProfilingLockFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline AcquireProfilingLockFlags& operator |= (AcquireProfilingLockFlags& a, AcquireProfilingLockFlags b) {
        a = static_cast<AcquireProfilingLockFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline AcquireProfilingLockFlags operator & (AcquireProfilingLockFlags a, AcquireProfilingLockFlags b) {
        return static_cast<AcquireProfilingLockFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline AcquireProfilingLockFlags& operator &= (AcquireProfilingLockFlags& a, AcquireProfilingLockFlags& b) {
        a = static_cast<AcquireProfilingLockFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (AcquireProfilingLockFlags& a, AcquireProfilingLockFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (AcquireProfilingLockFlags& a, AcquireProfilingLockFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class SemaphoreWaitFlags : uint32_t {
        None = 0,
        Any = 1,
    };

    inline SemaphoreWaitFlags operator | (SemaphoreWaitFlags a, SemaphoreWaitFlags b) {
        return static_cast<SemaphoreWaitFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline SemaphoreWaitFlags& operator |= (SemaphoreWaitFlags& a, SemaphoreWaitFlags b) {
        a = static_cast<SemaphoreWaitFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline SemaphoreWaitFlags operator & (SemaphoreWaitFlags a, SemaphoreWaitFlags b) {
        return static_cast<SemaphoreWaitFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline SemaphoreWaitFlags& operator &= (SemaphoreWaitFlags& a, SemaphoreWaitFlags& b) {
        a = static_cast<SemaphoreWaitFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (SemaphoreWaitFlags& a, SemaphoreWaitFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (SemaphoreWaitFlags& a, SemaphoreWaitFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class PerformanceConfigurationType {
        CommandQueueMetricsDiscoveryActivated = 0,
    };

    enum class QueryPoolSamplingMode {
        Manual = 0,
    };

    enum class PerformanceOverrideType {
        NullHardware = 0,
        FlushGpuCaches = 1,
    };

    enum class PerformanceParameterType {
        HwCountersSupported = 0,
        StreamMarkerValidBits = 1,
    };

    enum class PerformanceValueType {
        Uint32_ = 0,
        Uint64_ = 1,
        Float = 2,
        Bool = 3,
        String = 4,
    };

    enum class LineRasterizationMode {
        Default = 0,
        Rectangular = 1,
        Bresenham = 2,
        RectangularSmooth = 3,
    };

    enum class ShaderModuleCreateFlags : uint32_t {
        None = 0,
    };

    inline ShaderModuleCreateFlags operator | (ShaderModuleCreateFlags a, ShaderModuleCreateFlags b) {
        return static_cast<ShaderModuleCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ShaderModuleCreateFlags& operator |= (ShaderModuleCreateFlags& a, ShaderModuleCreateFlags b) {
        a = static_cast<ShaderModuleCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ShaderModuleCreateFlags operator & (ShaderModuleCreateFlags a, ShaderModuleCreateFlags b) {
        return static_cast<ShaderModuleCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ShaderModuleCreateFlags& operator &= (ShaderModuleCreateFlags& a, ShaderModuleCreateFlags& b) {
        a = static_cast<ShaderModuleCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ShaderModuleCreateFlags& a, ShaderModuleCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ShaderModuleCreateFlags& a, ShaderModuleCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class PipelineCompilerControlFlags : uint32_t {
        None = 0,
    };

    inline PipelineCompilerControlFlags operator | (PipelineCompilerControlFlags a, PipelineCompilerControlFlags b) {
        return static_cast<PipelineCompilerControlFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline PipelineCompilerControlFlags& operator |= (PipelineCompilerControlFlags& a, PipelineCompilerControlFlags b) {
        a = static_cast<PipelineCompilerControlFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline PipelineCompilerControlFlags operator & (PipelineCompilerControlFlags a, PipelineCompilerControlFlags b) {
        return static_cast<PipelineCompilerControlFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline PipelineCompilerControlFlags& operator &= (PipelineCompilerControlFlags& a, PipelineCompilerControlFlags& b) {
        a = static_cast<PipelineCompilerControlFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (PipelineCompilerControlFlags& a, PipelineCompilerControlFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (PipelineCompilerControlFlags& a, PipelineCompilerControlFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ShaderCorePropertiesFlags : uint32_t {
        None = 0,
    };

    inline ShaderCorePropertiesFlags operator | (ShaderCorePropertiesFlags a, ShaderCorePropertiesFlags b) {
        return static_cast<ShaderCorePropertiesFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ShaderCorePropertiesFlags& operator |= (ShaderCorePropertiesFlags& a, ShaderCorePropertiesFlags b) {
        a = static_cast<ShaderCorePropertiesFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ShaderCorePropertiesFlags operator & (ShaderCorePropertiesFlags a, ShaderCorePropertiesFlags b) {
        return static_cast<ShaderCorePropertiesFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ShaderCorePropertiesFlags& operator &= (ShaderCorePropertiesFlags& a, ShaderCorePropertiesFlags& b) {
        a = static_cast<ShaderCorePropertiesFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ShaderCorePropertiesFlags& a, ShaderCorePropertiesFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ShaderCorePropertiesFlags& a, ShaderCorePropertiesFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ToolPurposeFlags : uint32_t {
        None = 0,
        Validation = 1,
        Profiling = 2,
        Tracing = 4,
        AdditionalFeatures = 8,
        ModifyingFeatures = 16,
    };

    inline ToolPurposeFlags operator | (ToolPurposeFlags a, ToolPurposeFlags b) {
        return static_cast<ToolPurposeFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ToolPurposeFlags& operator |= (ToolPurposeFlags& a, ToolPurposeFlags b) {
        a = static_cast<ToolPurposeFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ToolPurposeFlags operator & (ToolPurposeFlags a, ToolPurposeFlags b) {
        return static_cast<ToolPurposeFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ToolPurposeFlags& operator &= (ToolPurposeFlags& a, ToolPurposeFlags& b) {
        a = static_cast<ToolPurposeFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ToolPurposeFlags& a, ToolPurposeFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ToolPurposeFlags& a, ToolPurposeFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ColorSpace {
        SrgbNonlinear = 0,
        Display_P3_NonlinearEXT = 1000104001,
        ExtendedSrgbLinearEXT = 1000104002,
        Display_P3_LinearEXT = 1000104003,
        Dci_P3_NonlinearEXT = 1000104004,
        Bt709_LinearEXT = 1000104005,
        Bt709_NonlinearEXT = 1000104006,
        Bt2020_LinearEXT = 1000104007,
        Hdr10_St2084_EXT = 1000104008,
        DolbyvisionEXT = 1000104009,
        Hdr10_HlgEXT = 1000104010,
        AdobergbLinearEXT = 1000104011,
        AdobergbNonlinearEXT = 1000104012,
        PassThroughEXT = 1000104013,
        ExtendedSrgbNonlinearEXT = 1000104014,
        DisplayNativeAMD = 1000213000,
    };

    enum class CompositeAlphaFlags : uint32_t {
        None = 0,
        Opaque = 1,
        PreMultiplied = 2,
        PostMultiplied = 4,
        Inherit = 8,
    };

    inline CompositeAlphaFlags operator | (CompositeAlphaFlags a, CompositeAlphaFlags b) {
        return static_cast<CompositeAlphaFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline CompositeAlphaFlags& operator |= (CompositeAlphaFlags& a, CompositeAlphaFlags b) {
        a = static_cast<CompositeAlphaFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline CompositeAlphaFlags operator & (CompositeAlphaFlags a, CompositeAlphaFlags b) {
        return static_cast<CompositeAlphaFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline CompositeAlphaFlags& operator &= (CompositeAlphaFlags& a, CompositeAlphaFlags& b) {
        a = static_cast<CompositeAlphaFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (CompositeAlphaFlags& a, CompositeAlphaFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (CompositeAlphaFlags& a, CompositeAlphaFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class DisplayPlaneAlphaFlags : uint32_t {
        None = 0,
        Opaque = 1,
        Global = 2,
        PerPixel = 4,
        PerPixelPremultiplied = 8,
    };

    inline DisplayPlaneAlphaFlags operator | (DisplayPlaneAlphaFlags a, DisplayPlaneAlphaFlags b) {
        return static_cast<DisplayPlaneAlphaFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline DisplayPlaneAlphaFlags& operator |= (DisplayPlaneAlphaFlags& a, DisplayPlaneAlphaFlags b) {
        a = static_cast<DisplayPlaneAlphaFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline DisplayPlaneAlphaFlags operator & (DisplayPlaneAlphaFlags a, DisplayPlaneAlphaFlags b) {
        return static_cast<DisplayPlaneAlphaFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline DisplayPlaneAlphaFlags& operator &= (DisplayPlaneAlphaFlags& a, DisplayPlaneAlphaFlags& b) {
        a = static_cast<DisplayPlaneAlphaFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (DisplayPlaneAlphaFlags& a, DisplayPlaneAlphaFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (DisplayPlaneAlphaFlags& a, DisplayPlaneAlphaFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class PresentMode {
        Immediate = 0,
        Mailbox = 1,
        Fifo = 2,
        FifoRelaxed = 3,
        SharedDemandRefresh = 1000111000,
        SharedContinuousRefresh = 1000111001,
    };

    enum class SurfaceTransformFlags : uint32_t {
        None = 0,
        Identity = 1,
        Rotate_90_ = 2,
        Rotate_180_ = 4,
        Rotate_270_ = 8,
        HorizontalMirror = 16,
        HorizontalMirrorRotate_90_ = 32,
        HorizontalMirrorRotate_180_ = 64,
        HorizontalMirrorRotate_270_ = 128,
        Inherit = 256,
    };

    inline SurfaceTransformFlags operator | (SurfaceTransformFlags a, SurfaceTransformFlags b) {
        return static_cast<SurfaceTransformFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline SurfaceTransformFlags& operator |= (SurfaceTransformFlags& a, SurfaceTransformFlags b) {
        a = static_cast<SurfaceTransformFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline SurfaceTransformFlags operator & (SurfaceTransformFlags a, SurfaceTransformFlags b) {
        return static_cast<SurfaceTransformFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline SurfaceTransformFlags& operator &= (SurfaceTransformFlags& a, SurfaceTransformFlags& b) {
        a = static_cast<SurfaceTransformFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (SurfaceTransformFlags& a, SurfaceTransformFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (SurfaceTransformFlags& a, SurfaceTransformFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class DebugReportFlags : uint32_t {
        None = 0,
        Information = 1,
        Warning = 2,
        PerformanceWarning = 4,
        Error = 8,
        Debug = 16,
    };

    inline DebugReportFlags operator | (DebugReportFlags a, DebugReportFlags b) {
        return static_cast<DebugReportFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline DebugReportFlags& operator |= (DebugReportFlags& a, DebugReportFlags b) {
        a = static_cast<DebugReportFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline DebugReportFlags operator & (DebugReportFlags a, DebugReportFlags b) {
        return static_cast<DebugReportFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline DebugReportFlags& operator &= (DebugReportFlags& a, DebugReportFlags& b) {
        a = static_cast<DebugReportFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (DebugReportFlags& a, DebugReportFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (DebugReportFlags& a, DebugReportFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class DebugReportObjectType {
        Unknown = 0,
        Instance = 1,
        PhysicalDevice = 2,
        Device = 3,
        Queue = 4,
        Semaphore = 5,
        CommandBuffer = 6,
        Fence = 7,
        DeviceMemory = 8,
        Buffer = 9,
        Image = 10,
        Event = 11,
        QueryPool = 12,
        BufferView = 13,
        ImageView = 14,
        ShaderModule = 15,
        PipelineCache = 16,
        PipelineLayout = 17,
        RenderPass = 18,
        Pipeline = 19,
        DescriptorSetLayout = 20,
        Sampler = 21,
        DescriptorPool = 22,
        DescriptorSet = 23,
        Framebuffer = 24,
        CommandPool = 25,
        SurfaceKhr = 26,
        SwapchainKhr = 27,
        DebugReportCallbackEXT = 28,
        DisplayKhr = 29,
        DisplayModeKhr = 30,
        ValidationCacheEXT = 33,
        SamplerYcbcrConversion = 1000156000,
        DescriptorUpdateTemplate = 1000085000,
        AccelerationStructureKhr = 1000165000,
    };

    enum class RasterizationOrder {
        Strict = 0,
        Relaxed = 1,
    };

    enum class ExternalMemoryHandleTypeFlagsNV : uint32_t {
        None = 0,
        Opaque_Win32_ = 1,
        Opaque_Win32_Kmt = 2,
        D3D11_Image = 4,
        D3D11_ImageKmt = 8,
    };

    inline ExternalMemoryHandleTypeFlagsNV operator | (ExternalMemoryHandleTypeFlagsNV a, ExternalMemoryHandleTypeFlagsNV b) {
        return static_cast<ExternalMemoryHandleTypeFlagsNV>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ExternalMemoryHandleTypeFlagsNV& operator |= (ExternalMemoryHandleTypeFlagsNV& a, ExternalMemoryHandleTypeFlagsNV b) {
        a = static_cast<ExternalMemoryHandleTypeFlagsNV>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ExternalMemoryHandleTypeFlagsNV operator & (ExternalMemoryHandleTypeFlagsNV a, ExternalMemoryHandleTypeFlagsNV b) {
        return static_cast<ExternalMemoryHandleTypeFlagsNV>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ExternalMemoryHandleTypeFlagsNV& operator &= (ExternalMemoryHandleTypeFlagsNV& a, ExternalMemoryHandleTypeFlagsNV& b) {
        a = static_cast<ExternalMemoryHandleTypeFlagsNV>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ExternalMemoryHandleTypeFlagsNV& a, ExternalMemoryHandleTypeFlagsNV& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ExternalMemoryHandleTypeFlagsNV& a, ExternalMemoryHandleTypeFlagsNV& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ExternalMemoryFeatureFlagsNV : uint32_t {
        None = 0,
        DedicatedOnly = 1,
        Exportable = 2,
        Importable = 4,
    };

    inline ExternalMemoryFeatureFlagsNV operator | (ExternalMemoryFeatureFlagsNV a, ExternalMemoryFeatureFlagsNV b) {
        return static_cast<ExternalMemoryFeatureFlagsNV>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ExternalMemoryFeatureFlagsNV& operator |= (ExternalMemoryFeatureFlagsNV& a, ExternalMemoryFeatureFlagsNV b) {
        a = static_cast<ExternalMemoryFeatureFlagsNV>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ExternalMemoryFeatureFlagsNV operator & (ExternalMemoryFeatureFlagsNV a, ExternalMemoryFeatureFlagsNV b) {
        return static_cast<ExternalMemoryFeatureFlagsNV>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ExternalMemoryFeatureFlagsNV& operator &= (ExternalMemoryFeatureFlagsNV& a, ExternalMemoryFeatureFlagsNV& b) {
        a = static_cast<ExternalMemoryFeatureFlagsNV>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ExternalMemoryFeatureFlagsNV& a, ExternalMemoryFeatureFlagsNV& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ExternalMemoryFeatureFlagsNV& a, ExternalMemoryFeatureFlagsNV& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ValidationCheck {
        All = 0,
        Shaders = 1,
    };

    enum class ValidationFeatureEnable {
        GpuAssisted = 0,
        GpuAssistedReserveBindingSlot = 1,
        BestPractices = 2,
        DebugPrintf = 3,
    };

    enum class ValidationFeatureDisable {
        All = 0,
        Shaders = 1,
        ThreadSafety = 2,
        ApiParameters = 3,
        ObjectLifetimes = 4,
        CoreChecks = 5,
        UniqueHandles = 6,
    };

    enum class ExternalMemoryHandleTypeFlags : uint32_t {
        None = 0,
        OpaqueFd = 1,
        Opaque_Win32 = 2,
        Opaque_Win32_Kmt = 4,
        D3D11_Texture = 8,
        D3D11_TextureKmt = 16,
        D3D12_Heap = 32,
        D3D12_Resource = 64,
    };

    inline ExternalMemoryHandleTypeFlags operator | (ExternalMemoryHandleTypeFlags a, ExternalMemoryHandleTypeFlags b) {
        return static_cast<ExternalMemoryHandleTypeFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ExternalMemoryHandleTypeFlags& operator |= (ExternalMemoryHandleTypeFlags& a, ExternalMemoryHandleTypeFlags b) {
        a = static_cast<ExternalMemoryHandleTypeFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ExternalMemoryHandleTypeFlags operator & (ExternalMemoryHandleTypeFlags a, ExternalMemoryHandleTypeFlags b) {
        return static_cast<ExternalMemoryHandleTypeFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ExternalMemoryHandleTypeFlags& operator &= (ExternalMemoryHandleTypeFlags& a, ExternalMemoryHandleTypeFlags& b) {
        a = static_cast<ExternalMemoryHandleTypeFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ExternalMemoryHandleTypeFlags& a, ExternalMemoryHandleTypeFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ExternalMemoryHandleTypeFlags& a, ExternalMemoryHandleTypeFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ExternalMemoryFeatureFlags : uint32_t {
        None = 0,
        DedicatedOnly = 1,
        Exportable = 2,
        Importable = 4,
    };

    inline ExternalMemoryFeatureFlags operator | (ExternalMemoryFeatureFlags a, ExternalMemoryFeatureFlags b) {
        return static_cast<ExternalMemoryFeatureFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ExternalMemoryFeatureFlags& operator |= (ExternalMemoryFeatureFlags& a, ExternalMemoryFeatureFlags b) {
        a = static_cast<ExternalMemoryFeatureFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ExternalMemoryFeatureFlags operator & (ExternalMemoryFeatureFlags a, ExternalMemoryFeatureFlags b) {
        return static_cast<ExternalMemoryFeatureFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ExternalMemoryFeatureFlags& operator &= (ExternalMemoryFeatureFlags& a, ExternalMemoryFeatureFlags& b) {
        a = static_cast<ExternalMemoryFeatureFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ExternalMemoryFeatureFlags& a, ExternalMemoryFeatureFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ExternalMemoryFeatureFlags& a, ExternalMemoryFeatureFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ExternalSemaphoreHandleTypeFlags : uint32_t {
        None = 0,
        OpaqueFd = 1,
        Opaque_Win32 = 2,
        Opaque_Win32_Kmt = 4,
        D3D12_Fence = 8,
        SyncFd = 16,
    };

    inline ExternalSemaphoreHandleTypeFlags operator | (ExternalSemaphoreHandleTypeFlags a, ExternalSemaphoreHandleTypeFlags b) {
        return static_cast<ExternalSemaphoreHandleTypeFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ExternalSemaphoreHandleTypeFlags& operator |= (ExternalSemaphoreHandleTypeFlags& a, ExternalSemaphoreHandleTypeFlags b) {
        a = static_cast<ExternalSemaphoreHandleTypeFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ExternalSemaphoreHandleTypeFlags operator & (ExternalSemaphoreHandleTypeFlags a, ExternalSemaphoreHandleTypeFlags b) {
        return static_cast<ExternalSemaphoreHandleTypeFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ExternalSemaphoreHandleTypeFlags& operator &= (ExternalSemaphoreHandleTypeFlags& a, ExternalSemaphoreHandleTypeFlags& b) {
        a = static_cast<ExternalSemaphoreHandleTypeFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ExternalSemaphoreHandleTypeFlags& a, ExternalSemaphoreHandleTypeFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ExternalSemaphoreHandleTypeFlags& a, ExternalSemaphoreHandleTypeFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ExternalSemaphoreFeatureFlags : uint32_t {
        None = 0,
        Exportable = 1,
        Importable = 2,
    };

    inline ExternalSemaphoreFeatureFlags operator | (ExternalSemaphoreFeatureFlags a, ExternalSemaphoreFeatureFlags b) {
        return static_cast<ExternalSemaphoreFeatureFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ExternalSemaphoreFeatureFlags& operator |= (ExternalSemaphoreFeatureFlags& a, ExternalSemaphoreFeatureFlags b) {
        a = static_cast<ExternalSemaphoreFeatureFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ExternalSemaphoreFeatureFlags operator & (ExternalSemaphoreFeatureFlags a, ExternalSemaphoreFeatureFlags b) {
        return static_cast<ExternalSemaphoreFeatureFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ExternalSemaphoreFeatureFlags& operator &= (ExternalSemaphoreFeatureFlags& a, ExternalSemaphoreFeatureFlags& b) {
        a = static_cast<ExternalSemaphoreFeatureFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ExternalSemaphoreFeatureFlags& a, ExternalSemaphoreFeatureFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ExternalSemaphoreFeatureFlags& a, ExternalSemaphoreFeatureFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class SemaphoreImportFlags : uint32_t {
        None = 0,
        Temporary = 1,
    };

    inline SemaphoreImportFlags operator | (SemaphoreImportFlags a, SemaphoreImportFlags b) {
        return static_cast<SemaphoreImportFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline SemaphoreImportFlags& operator |= (SemaphoreImportFlags& a, SemaphoreImportFlags b) {
        a = static_cast<SemaphoreImportFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline SemaphoreImportFlags operator & (SemaphoreImportFlags a, SemaphoreImportFlags b) {
        return static_cast<SemaphoreImportFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline SemaphoreImportFlags& operator &= (SemaphoreImportFlags& a, SemaphoreImportFlags& b) {
        a = static_cast<SemaphoreImportFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (SemaphoreImportFlags& a, SemaphoreImportFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (SemaphoreImportFlags& a, SemaphoreImportFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ExternalFenceHandleTypeFlags : uint32_t {
        None = 0,
        OpaqueFd = 1,
        Opaque_Win32 = 2,
        Opaque_Win32_Kmt = 4,
        SyncFd = 8,
    };

    inline ExternalFenceHandleTypeFlags operator | (ExternalFenceHandleTypeFlags a, ExternalFenceHandleTypeFlags b) {
        return static_cast<ExternalFenceHandleTypeFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ExternalFenceHandleTypeFlags& operator |= (ExternalFenceHandleTypeFlags& a, ExternalFenceHandleTypeFlags b) {
        a = static_cast<ExternalFenceHandleTypeFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ExternalFenceHandleTypeFlags operator & (ExternalFenceHandleTypeFlags a, ExternalFenceHandleTypeFlags b) {
        return static_cast<ExternalFenceHandleTypeFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ExternalFenceHandleTypeFlags& operator &= (ExternalFenceHandleTypeFlags& a, ExternalFenceHandleTypeFlags& b) {
        a = static_cast<ExternalFenceHandleTypeFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ExternalFenceHandleTypeFlags& a, ExternalFenceHandleTypeFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ExternalFenceHandleTypeFlags& a, ExternalFenceHandleTypeFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ExternalFenceFeatureFlags : uint32_t {
        None = 0,
        Exportable = 1,
        Importable = 2,
    };

    inline ExternalFenceFeatureFlags operator | (ExternalFenceFeatureFlags a, ExternalFenceFeatureFlags b) {
        return static_cast<ExternalFenceFeatureFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ExternalFenceFeatureFlags& operator |= (ExternalFenceFeatureFlags& a, ExternalFenceFeatureFlags b) {
        a = static_cast<ExternalFenceFeatureFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ExternalFenceFeatureFlags operator & (ExternalFenceFeatureFlags a, ExternalFenceFeatureFlags b) {
        return static_cast<ExternalFenceFeatureFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ExternalFenceFeatureFlags& operator &= (ExternalFenceFeatureFlags& a, ExternalFenceFeatureFlags& b) {
        a = static_cast<ExternalFenceFeatureFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ExternalFenceFeatureFlags& a, ExternalFenceFeatureFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ExternalFenceFeatureFlags& a, ExternalFenceFeatureFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class FenceImportFlags : uint32_t {
        None = 0,
        Temporary = 1,
    };

    inline FenceImportFlags operator | (FenceImportFlags a, FenceImportFlags b) {
        return static_cast<FenceImportFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline FenceImportFlags& operator |= (FenceImportFlags& a, FenceImportFlags b) {
        a = static_cast<FenceImportFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline FenceImportFlags operator & (FenceImportFlags a, FenceImportFlags b) {
        return static_cast<FenceImportFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline FenceImportFlags& operator &= (FenceImportFlags& a, FenceImportFlags& b) {
        a = static_cast<FenceImportFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (FenceImportFlags& a, FenceImportFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (FenceImportFlags& a, FenceImportFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class SurfaceCounterFlags : uint32_t {
        None = 0,
        Vblank = 1,
    };

    inline SurfaceCounterFlags operator | (SurfaceCounterFlags a, SurfaceCounterFlags b) {
        return static_cast<SurfaceCounterFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline SurfaceCounterFlags& operator |= (SurfaceCounterFlags& a, SurfaceCounterFlags b) {
        a = static_cast<SurfaceCounterFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline SurfaceCounterFlags operator & (SurfaceCounterFlags a, SurfaceCounterFlags b) {
        return static_cast<SurfaceCounterFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline SurfaceCounterFlags& operator &= (SurfaceCounterFlags& a, SurfaceCounterFlags& b) {
        a = static_cast<SurfaceCounterFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (SurfaceCounterFlags& a, SurfaceCounterFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (SurfaceCounterFlags& a, SurfaceCounterFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class DisplayPowerState {
        Off = 0,
        Suspend = 1,
        On = 2,
    };

    enum class DeviceEventType {
        DisplayHotplug = 0,
    };

    enum class DisplayEventType {
        FirstPixelOut = 0,
    };

    enum class PeerMemoryFeatureFlags : uint32_t {
        None = 0,
        CopySrc = 1,
        CopyDst = 2,
        GenericSrc = 4,
        GenericDst = 8,
    };

    inline PeerMemoryFeatureFlags operator | (PeerMemoryFeatureFlags a, PeerMemoryFeatureFlags b) {
        return static_cast<PeerMemoryFeatureFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline PeerMemoryFeatureFlags& operator |= (PeerMemoryFeatureFlags& a, PeerMemoryFeatureFlags b) {
        a = static_cast<PeerMemoryFeatureFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline PeerMemoryFeatureFlags operator & (PeerMemoryFeatureFlags a, PeerMemoryFeatureFlags b) {
        return static_cast<PeerMemoryFeatureFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline PeerMemoryFeatureFlags& operator &= (PeerMemoryFeatureFlags& a, PeerMemoryFeatureFlags& b) {
        a = static_cast<PeerMemoryFeatureFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (PeerMemoryFeatureFlags& a, PeerMemoryFeatureFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (PeerMemoryFeatureFlags& a, PeerMemoryFeatureFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class MemoryAllocateFlags : uint32_t {
        None = 0,
        DeviceMask = 1,
    };

    inline MemoryAllocateFlags operator | (MemoryAllocateFlags a, MemoryAllocateFlags b) {
        return static_cast<MemoryAllocateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline MemoryAllocateFlags& operator |= (MemoryAllocateFlags& a, MemoryAllocateFlags b) {
        a = static_cast<MemoryAllocateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline MemoryAllocateFlags operator & (MemoryAllocateFlags a, MemoryAllocateFlags b) {
        return static_cast<MemoryAllocateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline MemoryAllocateFlags& operator &= (MemoryAllocateFlags& a, MemoryAllocateFlags& b) {
        a = static_cast<MemoryAllocateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (MemoryAllocateFlags& a, MemoryAllocateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (MemoryAllocateFlags& a, MemoryAllocateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class DeviceGroupPresentModeFlags : uint32_t {
        None = 0,
        Local = 1,
        Remote = 2,
        Sum = 4,
        LocalMultiDevice = 8,
    };

    inline DeviceGroupPresentModeFlags operator | (DeviceGroupPresentModeFlags a, DeviceGroupPresentModeFlags b) {
        return static_cast<DeviceGroupPresentModeFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline DeviceGroupPresentModeFlags& operator |= (DeviceGroupPresentModeFlags& a, DeviceGroupPresentModeFlags b) {
        a = static_cast<DeviceGroupPresentModeFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline DeviceGroupPresentModeFlags operator & (DeviceGroupPresentModeFlags a, DeviceGroupPresentModeFlags b) {
        return static_cast<DeviceGroupPresentModeFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline DeviceGroupPresentModeFlags& operator &= (DeviceGroupPresentModeFlags& a, DeviceGroupPresentModeFlags& b) {
        a = static_cast<DeviceGroupPresentModeFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (DeviceGroupPresentModeFlags& a, DeviceGroupPresentModeFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (DeviceGroupPresentModeFlags& a, DeviceGroupPresentModeFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class SwapchainCreateFlags : uint32_t {
        None = 0,
    };

    inline SwapchainCreateFlags operator | (SwapchainCreateFlags a, SwapchainCreateFlags b) {
        return static_cast<SwapchainCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline SwapchainCreateFlags& operator |= (SwapchainCreateFlags& a, SwapchainCreateFlags b) {
        a = static_cast<SwapchainCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline SwapchainCreateFlags operator & (SwapchainCreateFlags a, SwapchainCreateFlags b) {
        return static_cast<SwapchainCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline SwapchainCreateFlags& operator &= (SwapchainCreateFlags& a, SwapchainCreateFlags& b) {
        a = static_cast<SwapchainCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (SwapchainCreateFlags& a, SwapchainCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (SwapchainCreateFlags& a, SwapchainCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class SubgroupFeatureFlags : uint32_t {
        None = 0,
        Basic = 1,
        Vote = 2,
        Arithmetic = 4,
        Ballot = 8,
        Shuffle = 16,
        ShuffleRelative = 32,
        Clustered = 64,
        Quad = 128,
    };

    inline SubgroupFeatureFlags operator | (SubgroupFeatureFlags a, SubgroupFeatureFlags b) {
        return static_cast<SubgroupFeatureFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline SubgroupFeatureFlags& operator |= (SubgroupFeatureFlags& a, SubgroupFeatureFlags b) {
        a = static_cast<SubgroupFeatureFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline SubgroupFeatureFlags operator & (SubgroupFeatureFlags a, SubgroupFeatureFlags b) {
        return static_cast<SubgroupFeatureFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline SubgroupFeatureFlags& operator &= (SubgroupFeatureFlags& a, SubgroupFeatureFlags& b) {
        a = static_cast<SubgroupFeatureFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (SubgroupFeatureFlags& a, SubgroupFeatureFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (SubgroupFeatureFlags& a, SubgroupFeatureFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class TessellationDomainOrigin {
        UpperLeft = 0,
        LowerLeft = 1,
    };

    enum class SamplerYcbcrModelConversion {
        RgbIdentity = 0,
        YcbcrIdentity = 1,
        Ycbcr_709 = 2,
        Ycbcr_601 = 3,
        Ycbcr_2020 = 4,
    };

    enum class SamplerYcbcrRange {
        ItuFull = 0,
        ItuNarrow = 1,
    };

    enum class ChromaLocation {
        CositedEven = 0,
        Midpoint = 1,
    };

    enum class SamplerReductionMode {
        WeightedAverage = 0,
        Min = 1,
        Max = 2,
    };

    enum class BlendOverlap {
        Uncorrelated = 0,
        Disjoint = 1,
        Conjoint = 2,
    };

    enum class DebugUtilsMessageSeverityFlags : uint32_t {
        None = 0,
        Verbose = 1,
        Info = 16,
        Warning = 256,
        Error = 4096,
    };

    inline DebugUtilsMessageSeverityFlags operator | (DebugUtilsMessageSeverityFlags a, DebugUtilsMessageSeverityFlags b) {
        return static_cast<DebugUtilsMessageSeverityFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline DebugUtilsMessageSeverityFlags& operator |= (DebugUtilsMessageSeverityFlags& a, DebugUtilsMessageSeverityFlags b) {
        a = static_cast<DebugUtilsMessageSeverityFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline DebugUtilsMessageSeverityFlags operator & (DebugUtilsMessageSeverityFlags a, DebugUtilsMessageSeverityFlags b) {
        return static_cast<DebugUtilsMessageSeverityFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline DebugUtilsMessageSeverityFlags& operator &= (DebugUtilsMessageSeverityFlags& a, DebugUtilsMessageSeverityFlags& b) {
        a = static_cast<DebugUtilsMessageSeverityFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (DebugUtilsMessageSeverityFlags& a, DebugUtilsMessageSeverityFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (DebugUtilsMessageSeverityFlags& a, DebugUtilsMessageSeverityFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class DebugUtilsMessageTypeFlags : uint32_t {
        None = 0,
        General = 1,
        Validation = 2,
        Performance = 4,
    };

    inline DebugUtilsMessageTypeFlags operator | (DebugUtilsMessageTypeFlags a, DebugUtilsMessageTypeFlags b) {
        return static_cast<DebugUtilsMessageTypeFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline DebugUtilsMessageTypeFlags& operator |= (DebugUtilsMessageTypeFlags& a, DebugUtilsMessageTypeFlags b) {
        a = static_cast<DebugUtilsMessageTypeFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline DebugUtilsMessageTypeFlags operator & (DebugUtilsMessageTypeFlags a, DebugUtilsMessageTypeFlags b) {
        return static_cast<DebugUtilsMessageTypeFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline DebugUtilsMessageTypeFlags& operator &= (DebugUtilsMessageTypeFlags& a, DebugUtilsMessageTypeFlags& b) {
        a = static_cast<DebugUtilsMessageTypeFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (DebugUtilsMessageTypeFlags& a, DebugUtilsMessageTypeFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (DebugUtilsMessageTypeFlags& a, DebugUtilsMessageTypeFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class FullScreenExclusive {
        Default = 0,
        Allowed = 1,
        Disallowed = 2,
        ApplicationControlled = 3,
    };

    enum class ShaderFloatControlsIndependence {
        _32_Only = 0,
        All = 1,
        None = 2,
    };

    enum class SwapchainImageUsageFlags : uint32_t {
        None = 0,
        Shared = 1,
    };

    inline SwapchainImageUsageFlags operator | (SwapchainImageUsageFlags a, SwapchainImageUsageFlags b) {
        return static_cast<SwapchainImageUsageFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline SwapchainImageUsageFlags& operator |= (SwapchainImageUsageFlags& a, SwapchainImageUsageFlags b) {
        a = static_cast<SwapchainImageUsageFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline SwapchainImageUsageFlags operator & (SwapchainImageUsageFlags a, SwapchainImageUsageFlags b) {
        return static_cast<SwapchainImageUsageFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline SwapchainImageUsageFlags& operator &= (SwapchainImageUsageFlags& a, SwapchainImageUsageFlags& b) {
        a = static_cast<SwapchainImageUsageFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (SwapchainImageUsageFlags& a, SwapchainImageUsageFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (SwapchainImageUsageFlags& a, SwapchainImageUsageFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class VendorId {
        VIV = 0x10001,
        VSI = 0x10002,
        Kazan = 0x10003,
        Codeplay = 0x10004,
    };

    enum class DriverId {
        AmdProprietary = 1,
        AmdOpenSource = 2,
        MesaRadv = 3,
        NvidiaProprietary = 4,
        IntelProprietaryWindows = 5,
        IntelOpenSourceMESA = 6,
        ImaginationProprietary = 7,
        QualcommProprietary = 8,
        ArmProprietary = 9,
        GoogleSwiftshader = 10,
        GgpProprietary = 11,
        BroadcomProprietary = 12,
    };

    enum class ShadingRatePaletteEntry {
        NoInvocations = 0,
        _16_InvocationsPerPixel = 1,
        _8_InvocationsPerPixel = 2,
        _4_InvocationsPerPixel = 3,
        _2_InvocationsPerPixel = 4,
        _1_InvocationPerPixel = 5,
        _1_InvocationPer_2X1_Pixels = 6,
        _1_InvocationPer_1X2_Pixels = 7,
        _1_InvocationPer_2X2_Pixels = 8,
        _1_InvocationPer_4X2_Pixels = 9,
        _1_InvocationPer_2X4_Pixels = 10,
        _1_InvocationPer_4X4_Pixels = 11,
    };

    enum class CoarseSampleOrderType {
        Default = 0,
        Custom = 1,
        PixelMajor = 2,
        SampleMajor = 3,
    };

    enum class PipelineExecutableStatisticFormat {
        Bool32_ = 0,
        Int64_ = 1,
        Uint64_ = 2,
        Float64_ = 3,
    };

    enum class SemaphoreCreateFlags : uint32_t {
        None = 0,
    };

    inline SemaphoreCreateFlags operator | (SemaphoreCreateFlags a, SemaphoreCreateFlags b) {
        return static_cast<SemaphoreCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline SemaphoreCreateFlags& operator |= (SemaphoreCreateFlags& a, SemaphoreCreateFlags b) {
        a = static_cast<SemaphoreCreateFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline SemaphoreCreateFlags operator & (SemaphoreCreateFlags a, SemaphoreCreateFlags b) {
        return static_cast<SemaphoreCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline SemaphoreCreateFlags& operator &= (SemaphoreCreateFlags& a, SemaphoreCreateFlags& b) {
        a = static_cast<SemaphoreCreateFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (SemaphoreCreateFlags& a, SemaphoreCreateFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (SemaphoreCreateFlags& a, SemaphoreCreateFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

}

static_assert(sizeof(VkResult) == sizeof(vk::Result), "Enums are not the same size");
