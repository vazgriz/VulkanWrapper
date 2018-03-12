#pragma once
#include <vulkan/vulkan.h>

namespace vk {
    class Device;

    class Image {
    public:
        Image(Device& device, VkImage image);
        Image(const Image& image) = delete;
        Image& operator = (const Image& other) = delete;
        Image(Image&& other);
        ~Image();

        VkImage handle() const { return m_image; }
        Device& device() const { return m_device; }

    private:
        VkImage m_image;
        Device& m_device;
        bool m_destructorEnabled;
    };
}