#pragma once
#include <vulkan/vulkan.h>
#include <stdexcept>

#define VKW_CHECK(exp) {\
    VkResult result = exp;\
    if (result < 0) {\
        throw std::runtime_error(GetResultString(result));\
    }\
}

namespace vk {
    const char* GetResultString(VkResult result);
}