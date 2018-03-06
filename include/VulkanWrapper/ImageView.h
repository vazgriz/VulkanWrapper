#pragma once
#include <vulkan/vulkan.h>

namespace vk {
    class Device;
    class Image;

    class ImageViewCreateInfo : public CreateInfo<VkImageViewCreateInfo> {
    public:
        const Image& image;
        ImageViewType viewType;
        Format format;
        ComponentMapping components;
        ImageSubresourceRange subresourceRange;

        ImageViewCreateInfo(const Image& image) : image(image) {}
        void marshal() const;
    };

    class ImageView {
    public:
        ImageView(Device& device, const ImageViewCreateInfo& info);
        ~ImageView();

        VkImageView handle() const { return m_imageView; }
        Device& device() const { return m_device; }
        const Image& image() const { return m_image; }

    private:
        VkImageView m_imageView;
        Device& m_device;
        const Image& m_image;
    };
}