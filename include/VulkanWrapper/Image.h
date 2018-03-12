#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;

    class ImageCreateInfo : public Info<VkImageCreateInfo> {
    public:
        ImageCreateFlags flags;
        ImageType imageType;
        Format format;
        Extent3D extent;
        uint32_t mipLevels;
        uint32_t arrayLayers;
        SampleCountFlags samples;
        ImageTiling tiling;
        ImageUsageFlags usage;
        SharingMode sharingMode;
        std::vector<uint32_t> queueFamilyIndices;
        ImageLayout initialLayout;

        void marshal() const;
    };

    class Image {
    public:
        Image(Device& device, const ImageCreateInfo& info);
        Image(Device& device, VkImage image, bool enableDestructor);
        Image(const Image& image) = delete;
        Image& operator = (const Image& other) = delete;
        Image(Image&& other);
        ~Image();

        VkImage handle() const { return m_image; }
        Device& device() const { return m_device; }

        MemoryRequirements requirements() const { return m_requirements; }

    private:
        void getRequirements();

        VkImage m_image;
        Device& m_device;
        bool m_destructorEnabled;
        MemoryRequirements m_requirements;
    };
}