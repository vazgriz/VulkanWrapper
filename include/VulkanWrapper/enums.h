//auto generated on 03/18/2018 9:15:50 PM
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
        ZeroExt = 1000148000,
        SrcExt = 1000148001,
        DstExt = 1000148002,
        SrcOverExt = 1000148003,
        DstOverExt = 1000148004,
        SrcInExt = 1000148005,
        DstInExt = 1000148006,
        SrcOutExt = 1000148007,
        DstOutExt = 1000148008,
        SrcAtopExt = 1000148009,
        DstAtopExt = 1000148010,
        XorExt = 1000148011,
        MultiplyExt = 1000148012,
        ScreenExt = 1000148013,
        OverlayExt = 1000148014,
        DarkenExt = 1000148015,
        LightenExt = 1000148016,
        ColordodgeExt = 1000148017,
        ColorburnExt = 1000148018,
        HardlightExt = 1000148019,
        SoftlightExt = 1000148020,
        DifferenceExt = 1000148021,
        ExclusionExt = 1000148022,
        InvertExt = 1000148023,
        InvertRgbExt = 1000148024,
        LineardodgeExt = 1000148025,
        LinearburnExt = 1000148026,
        VividlightExt = 1000148027,
        LinearlightExt = 1000148028,
        PinlightExt = 1000148029,
        HardmixExt = 1000148030,
        HslHueExt = 1000148031,
        HslSaturationExt = 1000148032,
        HslColorExt = 1000148033,
        HslLuminosityExt = 1000148034,
        PlusExt = 1000148035,
        PlusClampedExt = 1000148036,
        PlusClampedAlphaExt = 1000148037,
        PlusDarkerExt = 1000148038,
        MinusExt = 1000148039,
        MinusClampedExt = 1000148040,
        ContrastExt = 1000148041,
        InvertOvgExt = 1000148042,
        RedExt = 1000148043,
        GreenExt = 1000148044,
        BlueExt = 1000148045,
    };

    enum class BorderColor {
        FloatTransparentBlack = 0,
        IntTransparentBlack = 1,
        FloatOpaqueBlack = 2,
        IntOpaqueBlack = 3,
        FloatOpaqueWhite = 4,
        IntOpaqueWhite = 5,
    };

    enum class FramebufferCreateFlags {
        None = 0,
    };

    enum class QueryPoolCreateFlags {
        None = 0,
    };

    enum class RenderPassCreateFlags {
        None = 0,
    };

    enum class SamplerCreateFlags {
        None = 0,
    };

    enum class PipelineCacheHeaderVersion {
        One = 1,
    };

    enum class PipelineLayoutCreateFlags {
        None = 0,
    };

    enum class PipelineCacheCreateFlags {
        None = 0,
    };

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

    enum class PipelineShaderStageCreateFlags {
        None = 0,
    };

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

    enum class DeviceQueueCreateFlags {
        None = 0,
    };

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
        ViewportWScalingNv = 1000087000,
        DiscardRectangleExt = 1000099000,
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
        FillRectangleNv = 1000153000,
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
        Pvrtc1_2Bpp_UnormBlockImg = 1000054000,
        Pvrtc1_4Bpp_UnormBlockImg = 1000054001,
        Pvrtc2_2Bpp_UnormBlockImg = 1000054002,
        Pvrtc2_4Bpp_UnormBlockImg = 1000054003,
        Pvrtc1_2Bpp_SrgbBlockImg = 1000054004,
        Pvrtc1_4Bpp_SrgbBlockImg = 1000054005,
        Pvrtc2_2Bpp_SrgbBlockImg = 1000054006,
        Pvrtc2_4Bpp_SrgbBlockImg = 1000054007,
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
        PresentSrcKhr = 1000001002,
        SharedPresentKhr = 1000111000,
    };

    enum class ImageTiling {
        Optimal = 0,
        Linear = 1,
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
        ErrorSurfaceLostKhr = -1000000000,
        ErrorNativeWindowInUseKhr = -1000000001,
        SuboptimalKhr = 1000001003,
        ErrorOutOfDateKhr = -1000001004,
        ErrorIncompatibleDisplayKhr = -1000003001,
        ErrorValidationFailedExt = -1000011001,
        ErrorInvalidShaderNv = -1000012000,
        ErrorOutOfPoolMemoryKhr = -1000069000,
        ErrorInvalidExternalHandleKhr = -1000072003,
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
        SwapchainCreateInfoKhr = 1000001000,
        PresentInfoKhr = 1000001001,
        DisplayModeCreateInfoKhr = 1000002000,
        DisplaySurfaceCreateInfoKhr = 1000002001,
        DisplayPresentInfoKhr = 1000003000,
        XlibSurfaceCreateInfoKhr = 1000004000,
        XcbSurfaceCreateInfoKhr = 1000005000,
        WaylandSurfaceCreateInfoKhr = 1000006000,
        MirSurfaceCreateInfoKhr = 1000007000,
        AndroidSurfaceCreateInfoKhr = 1000008000,
        Win32_SurfaceCreateInfoKhr = 1000009000,
        DebugReportCallbackCreateInfoExt = 1000011000,
        PipelineRasterizationStateRasterizationOrderAmd = 1000018000,
        DebugMarkerObjectNameInfoExt = 1000022000,
        DebugMarkerObjectTagInfoExt = 1000022001,
        DebugMarkerMarkerInfoExt = 1000022002,
        DedicatedAllocationImageCreateInfoNv = 1000026000,
        DedicatedAllocationBufferCreateInfoNv = 1000026001,
        DedicatedAllocationMemoryAllocateInfoNv = 1000026002,
        TextureLodGatherFormatPropertiesAmd = 1000041000,
        RenderPassMultiviewCreateInfoKhx = 1000053000,
        PhysicalDeviceMultiviewFeaturesKhx = 1000053001,
        PhysicalDeviceMultiviewPropertiesKhx = 1000053002,
        ExternalMemoryImageCreateInfoNv = 1000056000,
        ExportMemoryAllocateInfoNv = 1000056001,
        ImportMemory_Win32_HandleInfoNv = 1000057000,
        ExportMemory_Win32_HandleInfoNv = 1000057001,
        Win32_KeyedMutexAcquireReleaseInfoNv = 1000058000,
        PhysicalDeviceFeatures_2_Khr = 1000059000,
        PhysicalDeviceProperties_2_Khr = 1000059001,
        FormatProperties_2_Khr = 1000059002,
        ImageFormatProperties_2_Khr = 1000059003,
        PhysicalDeviceImageFormatInfo_2_Khr = 1000059004,
        QueueFamilyProperties_2_Khr = 1000059005,
        PhysicalDeviceMemoryProperties_2_Khr = 1000059006,
        SparseImageFormatProperties_2_Khr = 1000059007,
        PhysicalDeviceSparseImageFormatInfo_2_Khr = 1000059008,
        MemoryAllocateFlagsInfoKhx = 1000060000,
        BindBufferMemoryInfoKhx = 1000060001,
        BindImageMemoryInfoKhx = 1000060002,
        DeviceGroupRenderPassBeginInfoKhx = 1000060003,
        DeviceGroupCommandBufferBeginInfoKhx = 1000060004,
        DeviceGroupSubmitInfoKhx = 1000060005,
        DeviceGroupBindSparseInfoKhx = 1000060006,
        DeviceGroupPresentCapabilitiesKhx = 1000060007,
        ImageSwapchainCreateInfoKhx = 1000060008,
        BindImageMemorySwapchainInfoKhx = 1000060009,
        AcquireNextImageInfoKhx = 1000060010,
        DeviceGroupPresentInfoKhx = 1000060011,
        DeviceGroupSwapchainCreateInfoKhx = 1000060012,
        ValidationFlagsExt = 1000061000,
        ViSurfaceCreateInfoNn = 1000062000,
        PhysicalDeviceGroupPropertiesKhx = 1000070000,
        DeviceGroupDeviceCreateInfoKhx = 1000070001,
        PhysicalDeviceExternalImageFormatInfoKhr = 1000071000,
        ExternalImageFormatPropertiesKhr = 1000071001,
        PhysicalDeviceExternalBufferInfoKhr = 1000071002,
        ExternalBufferPropertiesKhr = 1000071003,
        PhysicalDeviceIdPropertiesKhr = 1000071004,
        ExternalMemoryBufferCreateInfoKhr = 1000072000,
        ExternalMemoryImageCreateInfoKhr = 1000072001,
        ExportMemoryAllocateInfoKhr = 1000072002,
        ImportMemory_Win32_HandleInfoKhr = 1000073000,
        ExportMemory_Win32_HandleInfoKhr = 1000073001,
        Memory_Win32_HandlePropertiesKhr = 1000073002,
        MemoryGet_Win32_HandleInfoKhr = 1000073003,
        ImportMemoryFdInfoKhr = 1000074000,
        MemoryFdPropertiesKhr = 1000074001,
        MemoryGetFdInfoKhr = 1000074002,
        Win32_KeyedMutexAcquireReleaseInfoKhr = 1000075000,
        PhysicalDeviceExternalSemaphoreInfoKhr = 1000076000,
        ExternalSemaphorePropertiesKhr = 1000076001,
        ExportSemaphoreCreateInfoKhr = 1000077000,
        ImportSemaphore_Win32_HandleInfoKhr = 1000078000,
        ExportSemaphore_Win32_HandleInfoKhr = 1000078001,
        D3D12_FenceSubmitInfoKhr = 1000078002,
        SemaphoreGet_Win32_HandleInfoKhr = 1000078003,
        ImportSemaphoreFdInfoKhr = 1000079000,
        SemaphoreGetFdInfoKhr = 1000079001,
        PhysicalDevicePushDescriptorPropertiesKhr = 1000080000,
        PhysicalDevice_16Bit_StorageFeaturesKhr = 1000083000,
        PresentRegionsKhr = 1000084000,
        DescriptorUpdateTemplateCreateInfoKhr = 1000085000,
        ObjectTableCreateInfoNvx = 1000086000,
        IndirectCommandsLayoutCreateInfoNvx = 1000086001,
        CmdProcessCommandsInfoNvx = 1000086002,
        CmdReserveSpaceForCommandsInfoNvx = 1000086003,
        DeviceGeneratedCommandsLimitsNvx = 1000086004,
        DeviceGeneratedCommandsFeaturesNvx = 1000086005,
        PipelineViewportWScalingStateCreateInfoNv = 1000087000,
        Surface_Capabilities2_Ext = 1000090000,
        DisplayPowerInfoExt = 1000091000,
        DeviceEventInfoExt = 1000091001,
        DisplayEventInfoExt = 1000091002,
        SwapchainCounterCreateInfoExt = 1000091003,
        PresentTimesInfoGoogle = 1000092000,
        PhysicalDeviceMultiviewPerViewAttributesPropertiesNvx = 1000097000,
        PipelineViewportSwizzleStateCreateInfoNv = 1000098000,
        PhysicalDeviceDiscardRectanglePropertiesExt = 1000099000,
        PipelineDiscardRectangleStateCreateInfoExt = 1000099001,
        HdrMetadataExt = 1000105000,
        SharedPresentSurfaceCapabilitiesKhr = 1000111000,
        PhysicalDeviceExternalFenceInfoKhr = 1000112000,
        ExternalFencePropertiesKhr = 1000112001,
        ExportFenceCreateInfoKhr = 1000113000,
        ImportFence_Win32_HandleInfoKhr = 1000114000,
        ExportFence_Win32_HandleInfoKhr = 1000114001,
        FenceGet_Win32_HandleInfoKhr = 1000114002,
        ImportFenceFdInfoKhr = 1000115000,
        FenceGetFdInfoKhr = 1000115001,
        PhysicalDeviceSurfaceInfo_2_Khr = 1000119000,
        SurfaceCapabilities_2_Khr = 1000119001,
        SurfaceFormat_2_Khr = 1000119002,
        PhysicalDeviceVariablePointerFeaturesKhr = 1000120000,
        IosSurfaceCreateInfoMvk = 1000122000,
        MacosSurfaceCreateInfoMvk = 1000123000,
        MemoryDedicatedRequirementsKhr = 1000127000,
        MemoryDedicatedAllocateInfoKhr = 1000127001,
        PhysicalDeviceSamplerFilterMinmaxPropertiesExt = 1000130000,
        SamplerReductionModeCreateInfoExt = 1000130001,
        BufferMemoryRequirementsInfo_2_Khr = 1000146000,
        ImageMemoryRequirementsInfo_2_Khr = 1000146001,
        ImageSparseMemoryRequirementsInfo_2_Khr = 1000146002,
        MemoryRequirements_2_Khr = 1000146003,
        SparseImageMemoryRequirements_2_Khr = 1000146004,
        PhysicalDeviceBlendOperationAdvancedFeaturesExt = 1000148000,
        PhysicalDeviceBlendOperationAdvancedPropertiesExt = 1000148001,
        PipelineColorBlendAdvancedStateCreateInfoExt = 1000148002,
        PipelineCoverageToColorStateCreateInfoNv = 1000149000,
        PipelineCoverageModulationStateCreateInfoNv = 1000152000,
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
        CubicImg = 1000015000,
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
        SurfaceKhr = 1000000000,
        SwapchainKhr = 1000001000,
        DisplayKhr = 1000002000,
        DisplayModeKhr = 1000002001,
        DebugReportCallbackExt = 1000011000,
        DescriptorUpdateTemplateKhr = 1000085000,
        ObjectTableNvx = 1000086000,
        IndirectCommandsLayoutNvx = 1000086001,
    };

    enum class IndirectCommandsLayoutUsageFlags : uint32_t {
        None = 0,
        UnorderedSequences = 1,
        SparseSequences = 2,
        EmptyExecutions = 4,
        IndexedSequences = 8,
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
        Pipeline = 0,
        DescriptorSet = 1,
        IndexBuffer = 2,
        VertexBuffer = 3,
        PushConstant = 4,
        DrawIndexed = 5,
        Draw = 6,
        Dispatch = 7,
    };

    enum class ObjectEntryUsageFlags : uint32_t {
        None = 0,
        Graphics = 1,
        Compute = 2,
    };

    inline ObjectEntryUsageFlags operator | (ObjectEntryUsageFlags a, ObjectEntryUsageFlags b) {
        return static_cast<ObjectEntryUsageFlags>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ObjectEntryUsageFlags& operator |= (ObjectEntryUsageFlags& a, ObjectEntryUsageFlags b) {
        a = static_cast<ObjectEntryUsageFlags>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ObjectEntryUsageFlags operator & (ObjectEntryUsageFlags a, ObjectEntryUsageFlags b) {
        return static_cast<ObjectEntryUsageFlags>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ObjectEntryUsageFlags& operator &= (ObjectEntryUsageFlags& a, ObjectEntryUsageFlags& b) {
        a = static_cast<ObjectEntryUsageFlags>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ObjectEntryUsageFlags& a, ObjectEntryUsageFlags& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ObjectEntryUsageFlags& a, ObjectEntryUsageFlags& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ObjectEntryType {
        DescriptorSet = 0,
        Pipeline = 1,
        IndexBuffer = 2,
        VertexBuffer = 3,
        PushConstant = 4,
    };

    enum class DescriptorUpdateTemplateType {
        DescriptorSet = 0,
        PushDescriptors = 1,
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

    enum class CoverageModulationMode {
        None = 0,
        Rgb = 1,
        Alpha = 2,
        Rgba = 3,
    };

    enum class ColorSpace {
        SrgbNonlinear = 0,
        Display_P3_NonlinearExt = 1000104001,
        ExtendedSrgbLinearExt = 1000104002,
        Dci_P3_LinearExt = 1000104003,
        Dci_P3_NonlinearExt = 1000104004,
        Bt709_LinearExt = 1000104005,
        Bt709_NonlinearExt = 1000104006,
        Bt2020_LinearExt = 1000104007,
        Hdr10_St2084_Ext = 1000104008,
        DolbyvisionExt = 1000104009,
        Hdr10_HlgExt = 1000104010,
        AdobergbLinearExt = 1000104011,
        AdobergbNonlinearExt = 1000104012,
        PassThroughExt = 1000104013,
        ExtendedSrgbNonlinearExt = 1000104014,
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
        DebugReportCallbackExt = 28,
        DisplayKhr = 29,
        DisplayModeKhr = 30,
        ObjectTableNvx = 31,
        IndirectCommandsLayoutNvx = 32,
        DescriptorUpdateTemplateKhr = 1000085000,
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

    enum class ExternalMemoryHandleTypeFlagsKHR : uint32_t {
        None = 0,
        OpaqueFd = 1,
        Opaque_Win32_ = 2,
        Opaque_Win32_Kmt = 4,
        D3D11_Texture = 8,
        D3D11_TextureKmt = 16,
        D3D12_Heap = 32,
        D3D12_Resource = 64,
    };

    inline ExternalMemoryHandleTypeFlagsKHR operator | (ExternalMemoryHandleTypeFlagsKHR a, ExternalMemoryHandleTypeFlagsKHR b) {
        return static_cast<ExternalMemoryHandleTypeFlagsKHR>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ExternalMemoryHandleTypeFlagsKHR& operator |= (ExternalMemoryHandleTypeFlagsKHR& a, ExternalMemoryHandleTypeFlagsKHR b) {
        a = static_cast<ExternalMemoryHandleTypeFlagsKHR>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ExternalMemoryHandleTypeFlagsKHR operator & (ExternalMemoryHandleTypeFlagsKHR a, ExternalMemoryHandleTypeFlagsKHR b) {
        return static_cast<ExternalMemoryHandleTypeFlagsKHR>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ExternalMemoryHandleTypeFlagsKHR& operator &= (ExternalMemoryHandleTypeFlagsKHR& a, ExternalMemoryHandleTypeFlagsKHR& b) {
        a = static_cast<ExternalMemoryHandleTypeFlagsKHR>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ExternalMemoryHandleTypeFlagsKHR& a, ExternalMemoryHandleTypeFlagsKHR& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ExternalMemoryHandleTypeFlagsKHR& a, ExternalMemoryHandleTypeFlagsKHR& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ExternalMemoryFeatureFlagsKHR : uint32_t {
        None = 0,
        DedicatedOnly = 1,
        Exportable = 2,
        Importable = 4,
    };

    inline ExternalMemoryFeatureFlagsKHR operator | (ExternalMemoryFeatureFlagsKHR a, ExternalMemoryFeatureFlagsKHR b) {
        return static_cast<ExternalMemoryFeatureFlagsKHR>(static_cast<int>(a) | static_cast<int>(b));
    }

    inline ExternalMemoryFeatureFlagsKHR& operator |= (ExternalMemoryFeatureFlagsKHR& a, ExternalMemoryFeatureFlagsKHR b) {
        a = static_cast<ExternalMemoryFeatureFlagsKHR>(static_cast<int>(a) | static_cast<int>(b));
        return a;
    }

    inline ExternalMemoryFeatureFlagsKHR operator & (ExternalMemoryFeatureFlagsKHR a, ExternalMemoryFeatureFlagsKHR b) {
        return static_cast<ExternalMemoryFeatureFlagsKHR>(static_cast<int>(a) & static_cast<int>(b));
    }

    inline ExternalMemoryFeatureFlagsKHR& operator &= (ExternalMemoryFeatureFlagsKHR& a, ExternalMemoryFeatureFlagsKHR& b) {
        a = static_cast<ExternalMemoryFeatureFlagsKHR>(static_cast<int>(a) & static_cast<int>(b));
        return a;
    }

    inline bool operator == (ExternalMemoryFeatureFlagsKHR& a, ExternalMemoryFeatureFlagsKHR& b) {
        return static_cast<int>(a) == static_cast<int>(b);
    }

    inline bool operator != (ExternalMemoryFeatureFlagsKHR& a, ExternalMemoryFeatureFlagsKHR& b) {
        return static_cast<int>(a) != static_cast<int>(b);
    }

    enum class ExternalSemaphoreHandleTypeFlags : uint32_t {
        None = 0,
        OpaqueFd = 1,
        Opaque_Win32_ = 2,
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
        Opaque_Win32_ = 2,
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

}

static_assert(sizeof(VkResult) == sizeof(vk::Result), "Enums are not the same size");
