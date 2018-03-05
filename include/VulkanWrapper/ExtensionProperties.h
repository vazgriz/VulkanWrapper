#pragma once
#include <vulkan/vulkan.h>

namespace vk {
    struct ExtensionProperties {
        std::string extensionName;
        uint32_t specVersion;

        ExtensionProperties(VkExtensionProperties properties)
            : extensionName(properties.extensionName)
            , specVersion(properties.specVersion) {
        }
    };

    inline bool operator < (const ExtensionProperties a, const ExtensionProperties b) {
        return a.extensionName < b.extensionName;
    }
}