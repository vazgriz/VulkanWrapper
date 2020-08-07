#include "VulkanWrapper/ImageView.h"
#include "VulkanWrapper/Image.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

void ImageViewCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
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

ImageView::ImageView(Device& device, const ImageViewCreateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateImageView(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_imageView));
    m_device = &device;
}

ImageView::ImageView(ImageView&& other) {
    m_device = other.m_device;
    m_imageView = other.m_imageView;
    m_info = std::move(other.m_info);
    other.m_imageView = VK_NULL_HANDLE;
}

ImageView& ImageView::operator = (ImageView&& other) {
    vkDestroyImageView(m_device->handle(), m_imageView, device().instance().callbacks());
    m_device = other.m_device;
    m_imageView = other.m_imageView;
    m_info = std::move(other.m_info);
    other.m_imageView = VK_NULL_HANDLE;
    return *this;
}

ImageView::~ImageView() {
    vkDestroyImageView(m_device->handle(), m_imageView, device().instance().callbacks());
}