#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;
    class Image;

    class ImageViewCreateInfo : public Info<VkImageViewCreateInfo> {
    public:
        const Image* image;
        ImageViewType viewType;
        Format format;
        ComponentMapping components;
        ImageSubresourceRange subresourceRange;

        void marshal() const;
    };

    class ImageView {
    public:
        ImageView(Device& device, const ImageViewCreateInfo& info);
        ImageView(const ImageView& other) = delete;
        ImageView& operator = (const ImageView& other) = delete;
        ImageView(ImageView&& other);
        ~ImageView();

        VkImageView handle() const { return m_imageView; }
        Device& device() const { return **m_deviceRef; }

        const Image& image() const { return *m_info.image; }
        ImageViewType imageType() const { return m_info.viewType; }
        Format format() const { return m_info.format; }
        ComponentMapping components() const { return m_info.components; }
        ImageSubresourceRange subresourceRange() const { return m_info.subresourceRange; }

    private:
        VkImageView m_imageView;
        VkDevice m_device;
        Device** m_deviceRef;

        ImageViewCreateInfo m_info;
    };
}