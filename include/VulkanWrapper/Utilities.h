#pragma once
#include <vulkan/vulkan.h>
#include <stdexcept>
#include "VulkanWrapper/enums.h"

#define VKW_CHECK(exp) {\
    VkResult result = exp;\
    if (result < 0) {\
        throw std::runtime_error(::vk::toString(result));\
    }\
}

namespace vk {
    inline const char* toString(VkResult result) {
        switch (result) {
            default: return "Unknown value";
            case 0: return "Success";
            case 1: return "Not ready";
            case 2: return "Timeout";
            case 3: return "Event set";
            case 4: return "Event reset";
            case 5: return "Incomplete";
            case -1: return "Out of host memory";
            case -2: return "Out of device memory";
            case -3: return "Initialization failed";
            case -4: return "Device lost";
            case -5: return "Memory map failed";
            case -6: return "Layer not present";
            case -7: return "Extension not present";
            case -8: return "Feature not present";
            case -9: return "Incompatible driver";
            case -10: return "Too many objects";
            case -11: return "Format not supported";
            case -12: return "Fragmented pool";
            case -1000000000: return "Surface lost";
            case -1000000001: return "Native window in use";
            case  1000001003: return "Suboptimal";
            case -1000001004: return "Out of date";
            case -1000003001: return "Incompatible display";
            case -1000011001: return "Validation failed";
            case -1000012000: return "Invalid shader";
            case -1000069000: return "Out of pool memory";
            case -1000072003: return "Invalid external handle";
        }
    }

    size_t getFormatSize(Format format);
    size_t getFormatStencilSize(Format format);
    bool isColorFormat(Format format);
    bool isDepthFormat(Format format);
    bool isStencilFormat(Format format);
    bool isDepthStencilFormat(Format format);
}