#include "VulkanWrapper/Utilities.h"

size_t vk::getFormatSize(vk::Format format) {
    switch (format) {
        default: throw std::runtime_error("Not supported");
        case vk::Format::Undefined: return 0;
        case vk::Format::R4G4_Unorm_Pack8: return 1;
        case vk::Format::R4G4B4A4_Unorm_Pack16: return 2;
        case vk::Format::B4G4R4A4_Unorm_Pack16: return 2;
        case vk::Format::R5G6B5_Unorm_Pack16: return 2;
        case vk::Format::B5G6R5_Unorm_Pack16: return 2;
        case vk::Format::R5G5B5A1_Unorm_Pack16: return 2;
        case vk::Format::B5G5R5A1_Unorm_Pack16: return 2;
        case vk::Format::A1R5G5B5_Unorm_Pack16: return 2;
        case vk::Format::R8_Unorm: return 1;
        case vk::Format::R8_Snorm: return 1;
        case vk::Format::R8_Uscaled: return 1;
        case vk::Format::R8_Sscaled: return 1;
        case vk::Format::R8_Uint: return 1;
        case vk::Format::R8_Sint: return 1;
        case vk::Format::R8_Srgb: return 1;
        case vk::Format::R8G8_Unorm: return 2;
        case vk::Format::R8G8_Snorm: return 2;
        case vk::Format::R8G8_Uscaled: return 2;
        case vk::Format::R8G8_Sscaled: return 2;
        case vk::Format::R8G8_Uint: return 2;
        case vk::Format::R8G8_Sint: return 2;
        case vk::Format::R8G8_Srgb: return 2;
        case vk::Format::R8G8B8_Unorm: return 3;
        case vk::Format::R8G8B8_Snorm: return 3;
        case vk::Format::R8G8B8_Uscaled: return 3;
        case vk::Format::R8G8B8_Sscaled: return 3;
        case vk::Format::R8G8B8_Uint: return 3;
        case vk::Format::R8G8B8_Sint: return 3;
        case vk::Format::R8G8B8_Srgb: return 3;
        case vk::Format::B8G8R8_Unorm: return 3;
        case vk::Format::B8G8R8_Snorm: return 3;
        case vk::Format::B8G8R8_Uscaled: return 3;
        case vk::Format::B8G8R8_Sscaled: return 3;
        case vk::Format::B8G8R8_Uint: return 3;
        case vk::Format::B8G8R8_Sint: return 3;
        case vk::Format::B8G8R8_Srgb: return 3;
        case vk::Format::R8G8B8A8_Unorm: return 4;
        case vk::Format::R8G8B8A8_Snorm: return 4;
        case vk::Format::R8G8B8A8_Uscaled: return 4;
        case vk::Format::R8G8B8A8_Sscaled: return 4;
        case vk::Format::R8G8B8A8_Uint: return 4;
        case vk::Format::R8G8B8A8_Sint: return 4;
        case vk::Format::R8G8B8A8_Srgb: return 4;
        case vk::Format::B8G8R8A8_Unorm: return 4;
        case vk::Format::B8G8R8A8_Snorm: return 4;
        case vk::Format::B8G8R8A8_Uscaled: return 4;
        case vk::Format::B8G8R8A8_Sscaled: return 4;
        case vk::Format::B8G8R8A8_Uint: return 4;
        case vk::Format::B8G8R8A8_Sint: return 4;
        case vk::Format::B8G8R8A8_Srgb: return 4;
        case vk::Format::A8B8G8R8_Unorm_Pack32: return 4;
        case vk::Format::A8B8G8R8_Snorm_Pack32: return 4;
        case vk::Format::A8B8G8R8_Uscaled_Pack32: return 4;
        case vk::Format::A8B8G8R8_Sscaled_Pack32: return 4;
        case vk::Format::A8B8G8R8_Uint_Pack32: return 4;
        case vk::Format::A8B8G8R8_Sint_Pack32: return 4;
        case vk::Format::A8B8G8R8_Srgb_Pack32: return 4;
        case vk::Format::A2R10G10B10_Unorm_Pack32: return 4;
        case vk::Format::A2R10G10B10_Snorm_Pack32: return 4;
        case vk::Format::A2R10G10B10_Uscaled_Pack32: return 4;
        case vk::Format::A2R10G10B10_Sscaled_Pack32: return 4;
        case vk::Format::A2R10G10B10_Uint_Pack32: return 4;
        case vk::Format::A2R10G10B10_Sint_Pack32: return 4;
        case vk::Format::A2B10G10R10_Unorm_Pack32: return 4;
        case vk::Format::A2B10G10R10_Snorm_Pack32: return 4;
        case vk::Format::A2B10G10R10_Uscaled_Pack32: return 4;
        case vk::Format::A2B10G10R10_Sscaled_Pack32: return 4;
        case vk::Format::A2B10G10R10_Uint_Pack32: return 4;
        case vk::Format::A2B10G10R10_Sint_Pack32: return 4;
        case vk::Format::R16_Unorm: return 2;
        case vk::Format::R16_Snorm: return 2;
        case vk::Format::R16_Uscaled: return 2;
        case vk::Format::R16_Sscaled: return 2;
        case vk::Format::R16_Uint: return 2;
        case vk::Format::R16_Sint: return 2;
        case vk::Format::R16_Sfloat: return 2;
        case vk::Format::R16G16_Unorm: return 4;
        case vk::Format::R16G16_Snorm: return 4;
        case vk::Format::R16G16_Uscaled: return 4;
        case vk::Format::R16G16_Sscaled: return 4;
        case vk::Format::R16G16_Uint: return 4;
        case vk::Format::R16G16_Sint: return 4;
        case vk::Format::R16G16_Sfloat: return 4;
        case vk::Format::R16G16B16_Unorm: return 6;
        case vk::Format::R16G16B16_Snorm: return 6;
        case vk::Format::R16G16B16_Uscaled: return 6;
        case vk::Format::R16G16B16_Sscaled: return 6;
        case vk::Format::R16G16B16_Uint: return 6;
        case vk::Format::R16G16B16_Sint: return 6;
        case vk::Format::R16G16B16_Sfloat: return 6;
        case vk::Format::R16G16B16A16_Unorm: return 8;
        case vk::Format::R16G16B16A16_Snorm: return 8;
        case vk::Format::R16G16B16A16_Uscaled: return 8;
        case vk::Format::R16G16B16A16_Sscaled: return 8;
        case vk::Format::R16G16B16A16_Uint: return 8;
        case vk::Format::R16G16B16A16_Sint: return 8;
        case vk::Format::R16G16B16A16_Sfloat: return 8;
        case vk::Format::R32_Uint: return 4;
        case vk::Format::R32_Sint: return 4;
        case vk::Format::R32_Sfloat: return 4;
        case vk::Format::R32G32_Uint: return 8;
        case vk::Format::R32G32_Sint: return 8;
        case vk::Format::R32G32_Sfloat: return 8;
        case vk::Format::R32G32B32_Uint: return 12;
        case vk::Format::R32G32B32_Sint: return 12;
        case vk::Format::R32G32B32_Sfloat: return 12;
        case vk::Format::R32G32B32A32_Uint: return 16;
        case vk::Format::R32G32B32A32_Sint: return 16;
        case vk::Format::R32G32B32A32_Sfloat: return 16;
        case vk::Format::R64_Uint: return 8;
        case vk::Format::R64_Sint: return 8;
        case vk::Format::R64_Sfloat: return 8;
        case vk::Format::R64G64_Uint: return 16;
        case vk::Format::R64G64_Sint: return 16;
        case vk::Format::R64G64_Sfloat: return 16;
        case vk::Format::R64G64B64_Uint: return 24;
        case vk::Format::R64G64B64_Sint: return 24;
        case vk::Format::R64G64B64_Sfloat: return 24;
        case vk::Format::R64G64B64A64_Uint: return 32;
        case vk::Format::R64G64B64A64_Sint: return 32;
        case vk::Format::R64G64B64A64_Sfloat: return 32;
        case vk::Format::B10G11R11_Ufloat_Pack32: return 4;
        case vk::Format::E5B9G9R9_Ufloat_Pack32: return 4;
        case vk::Format::D16_Unorm: return 2;
        case vk::Format::X8_D24_Unorm_Pack32: return 4;
        case vk::Format::D32_Sfloat: return 4;
        case vk::Format::S8_Uint: return 1;
        case vk::Format::D16_Unorm_S8_Uint: return 2;
        case vk::Format::D24_Unorm_S8_Uint: return 4;
        case vk::Format::D32_Sfloat_S8_Uint: return 4;
        case vk::Format::Bc1_RgbUnormBlock: return 8;
        case vk::Format::Bc1_RgbSrgbBlock: return 8;
        case vk::Format::Bc1_RgbaUnormBlock: return 8;
        case vk::Format::Bc1_RgbaSrgbBlock: return 8;
        case vk::Format::Bc2_UnormBlock: return 16;
        case vk::Format::Bc2_SrgbBlock: return 16;
        case vk::Format::Bc3_UnormBlock: return 16;
        case vk::Format::Bc3_SrgbBlock: return 16;
        case vk::Format::Bc4_UnormBlock: return 8;
        case vk::Format::Bc4_SnormBlock: return 8;
        case vk::Format::Bc5_UnormBlock: return 16;
        case vk::Format::Bc5_SnormBlock: return 16;
        case vk::Format::Bc6H_UfloatBlock: return 16;
        case vk::Format::Bc6H_SfloatBlock: return 16;
        case vk::Format::Bc7_UnormBlock: return 16;
        case vk::Format::Bc7_SrgbBlock: return 16;
        case vk::Format::Etc2_R8G8B8_UnormBlock: return 8;
        case vk::Format::Etc2_R8G8B8_SrgbBlock: return 8;
        case vk::Format::Etc2_R8G8B8A1_UnormBlock: return 8;
        case vk::Format::Etc2_R8G8B8A1_SrgbBlock: return 8;
        case vk::Format::Etc2_R8G8B8A8_UnormBlock: return 16;
        case vk::Format::Etc2_R8G8B8A8_SrgbBlock: return 16;
        case vk::Format::Eac_R11_UnormBlock: return 8;
        case vk::Format::Eac_R11_SnormBlock: return 8;
        case vk::Format::Eac_R11G11_UnormBlock: return 16;
        case vk::Format::Eac_R11G11_SnormBlock: return 16;
        case vk::Format::Astc_4x4_UnormBlock: return 16;
        case vk::Format::Astc_4x4_SrgbBlock: return 16;
        case vk::Format::Astc_5x4_UnormBlock: return 16;
        case vk::Format::Astc_5x4_SrgbBlock: return 16;
        case vk::Format::Astc_5x5_UnormBlock: return 16;
        case vk::Format::Astc_5x5_SrgbBlock: return 16;
        case vk::Format::Astc_6x5_UnormBlock: return 16;
        case vk::Format::Astc_6x5_SrgbBlock: return 16;
        case vk::Format::Astc_6x6_UnormBlock: return 16;
        case vk::Format::Astc_6x6_SrgbBlock: return 16;
        case vk::Format::Astc_8x5_UnormBlock: return 16;
        case vk::Format::Astc_8x5_SrgbBlock: return 16;
        case vk::Format::Astc_8x6_UnormBlock: return 16;
        case vk::Format::Astc_8x6_SrgbBlock: return 16;
        case vk::Format::Astc_8x8_UnormBlock: return 16;
        case vk::Format::Astc_8x8_SrgbBlock: return 16;
        case vk::Format::Astc_10x5_UnormBlock: return 16;
        case vk::Format::Astc_10x5_SrgbBlock: return 16;
        case vk::Format::Astc_10x6_UnormBlock: return 16;
        case vk::Format::Astc_10x6_SrgbBlock: return 16;
        case vk::Format::Astc_10x8_UnormBlock: return 16;
        case vk::Format::Astc_10x8_SrgbBlock: return 16;
        case vk::Format::Astc_10x10_UnormBlock: return 16;
        case vk::Format::Astc_10x10_SrgbBlock: return 16;
        case vk::Format::Astc_12x10_UnormBlock: return 16;
        case vk::Format::Astc_12x10_SrgbBlock: return 16;
        case vk::Format::Astc_12x12_UnormBlock: return 16;
        case vk::Format::Astc_12x12_SrgbBlock: return 16;
        case vk::Format::Pvrtc1_2Bpp_UnormBlockIMG: throw std::runtime_error("Not supported");
        case vk::Format::Pvrtc1_4Bpp_UnormBlockIMG: throw std::runtime_error("Not supported");
        case vk::Format::Pvrtc2_2Bpp_UnormBlockIMG: throw std::runtime_error("Not supported");
        case vk::Format::Pvrtc2_4Bpp_UnormBlockIMG: throw std::runtime_error("Not supported");
        case vk::Format::Pvrtc1_2Bpp_SrgbBlockIMG: throw std::runtime_error("Not supported");
        case vk::Format::Pvrtc1_4Bpp_SrgbBlockIMG: throw std::runtime_error("Not supported");
        case vk::Format::Pvrtc2_2Bpp_SrgbBlockIMG: throw std::runtime_error("Not supported");
        case vk::Format::Pvrtc2_4Bpp_SrgbBlockIMG: throw std::runtime_error("Not supported");
    }
}

size_t vk::getFormatStencilSize(vk::Format format) {
    switch (format) {
        default: throw std::runtime_error("Not supported");
        case vk::Format::D16_Unorm_S8_Uint:
        case vk::Format::D24_Unorm_S8_Uint:
        case vk::Format::D32_Sfloat_S8_Uint: return 1;
    }
}

bool vk::isColorFormat(vk::Format format) {
    return !(isDepthFormat(format) || isStencilFormat(format));
}

bool vk::isDepthFormat(vk::Format format) {
    switch (format) {
        default: return false;
        case vk::Format::D16_Unorm:
        case vk::Format::X8_D24_Unorm_Pack32:
        case vk::Format::D32_Sfloat:
        case vk::Format::D16_Unorm_S8_Uint:
        case vk::Format::D24_Unorm_S8_Uint:
        case vk::Format::D32_Sfloat_S8_Uint: return true;
    }
}

bool vk::isStencilFormat(vk::Format format) {
    switch (format) {
        default: return false;
        case vk::Format::S8_Uint:
        case vk::Format::D16_Unorm_S8_Uint:
        case vk::Format::D24_Unorm_S8_Uint:
        case vk::Format::D32_Sfloat_S8_Uint: return true;
    }
}

bool vk::isDepthStencilFormat(vk::Format format) {
    switch (format) {
        default: return false;
        case vk::Format::D16_Unorm_S8_Uint:
        case vk::Format::D24_Unorm_S8_Uint:
        case vk::Format::D32_Sfloat_S8_Uint: return true;
    }
}