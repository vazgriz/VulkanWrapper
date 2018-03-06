#pragma once
#include <vulkan/vulkan.h>

namespace vk {
    class Device;

    class Image {
    public:
        Image(Device& device, VkImage image);
        ~Image();

        VkImage handle() const { return m_image; }
        Device& device() const { return m_device; }

    private:
        bool shouldDestroy;
        VkImage m_image;
        Device& m_device;
    };
}