#include "VulkanWrapper/Image.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

vk::Image::Image(Device& device, VkImage image) : m_device(device) {
    m_image = image;
    m_shouldDestroy = false;
}

vk::Image::~Image() {
    if (m_shouldDestroy) vkDestroyImage(m_device.handle(), m_image, m_device.instance().callbacks());
}

vk::Image::Image(Image&& other) : m_device(other.device()) {
    m_image = other.m_image;
    m_shouldDestroy = other.m_shouldDestroy;
    other.m_image = VK_NULL_HANDLE;
}