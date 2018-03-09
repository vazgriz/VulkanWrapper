#include "VulkanWrapper/Image.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

vk::Image::Image(Device& device, VkImage image) : m_device(device) {
    m_image = image;
    shouldDestroy = false;
}

vk::Image::~Image() {
    if (shouldDestroy) vkDestroyImage(m_device.handle(), m_image, m_device.instance().callbacks());
}