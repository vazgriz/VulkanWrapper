#include "VulkanWrapper/ImageView.h"
#include "VulkanWrapper/Image.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

void vk::ImageViewCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = &next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = 0;
    m_info.image = image->handle();
    m_info.viewType = static_cast<VkImageViewType>(viewType);
    m_info.format = static_cast<VkFormat>(format);
    m_info.components = *reinterpret_cast<const VkComponentMapping*>(&components);
    m_info.subresourceRange = *reinterpret_cast<const VkImageSubresourceRange*>(&subresourceRange);
}

vk::ImageView::ImageView(Device& device, const vk::ImageViewCreateInfo& info) : m_device(device), m_image(*info.image) {
    info.marshal();

    VKW_CHECK(vkCreateImageView(device.handle(), &info.info(), device.instance().callbacks(), &m_imageView));
}

vk::ImageView::~ImageView() {
    vkDestroyImageView(m_device.handle(), m_imageView, m_device.instance().callbacks());
}