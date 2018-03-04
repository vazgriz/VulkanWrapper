#pragma once
#include <vulkan/vulkan.h>

namespace vk {
    struct ExtensionProperties {
        std::string extensionName;
        uint32_t specVersion;

        ExtensionProperties() { }

        ExtensionProperties(VkExtensionProperties properties)
            : extensionName(properties.extensionName)
            , specVersion(properties.specVersion) {
        }
    };
}