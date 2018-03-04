#pragma once
#include <vulkan/vulkan.h>

namespace vk {
    struct LayerProperties {
        std::string layerName;
        uint32_t specVersion;
        uint32_t implementationVersion;
        std::string description;

        LayerProperties() { }

        LayerProperties(VkLayerProperties properties)
            : layerName(properties.layerName)
            , specVersion(properties.specVersion)
            , implementationVersion(properties.implementationVersion)
            , description(properties.description) {
        }
    };
}