#include "VulkanWrapper/Image.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"
#include "VulkanWrapper/DeviceMemory.h"

using namespace vk;

void ImageCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkImageCreateFlags>(flags);
    m_info.imageType = static_cast<VkImageType>(imageType);
    m_info.format = static_cast<VkFormat>(format);
    m_info.extent = extent;
    m_info.mipLevels = mipLevels;
    m_info.arrayLayers = arrayLayers;
    m_info.samples = static_cast<VkSampleCountFlagBits>(samples);
    m_info.tiling = static_cast<VkImageTiling>(tiling);
    m_info.usage = static_cast<VkImageUsageFlags>(usage);
    m_info.sharingMode = static_cast<VkSharingMode>(sharingMode);
    m_info.queueFamilyIndexCount = static_cast<uint32_t>(queueFamilyIndices.size());
    m_info.pQueueFamilyIndices = queueFamilyIndices.data();
    m_info.initialLayout = static_cast<VkImageLayout>(initialLayout);
}

Image::Image(Device& device, const ImageCreateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateImage(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_image));
    m_device = &device;
    m_destructorEnabled = true;

    getRequirements();
}

Image::Image(Device& device, VkImage image, bool enableDestructor, const ImageCreateInfo* info) {
    if (info == nullptr) {
        m_info = {};
    } else {
        m_info = *info;
    }

    m_device = &device;
    m_image = image;
    m_destructorEnabled = enableDestructor;

    getRequirements();
}

Image::~Image() {
    if (m_destructorEnabled) vkDestroyImage(m_device->handle(), m_image, device().instance().callbacks());
}

Image::Image(Image&& other) {
    m_device = other.m_device;
    m_image = other.m_image;
    m_destructorEnabled = other.m_destructorEnabled;
    m_requirements = other.m_requirements;
    m_info = std::move(other.m_info);
    other.m_image = VK_NULL_HANDLE;
}

Image& Image::operator = (Image&& other) {
    if (m_destructorEnabled) vkDestroyImage(m_device->handle(), m_image, device().instance().callbacks());
    m_device = other.m_device;
    m_image = other.m_image;
    m_destructorEnabled = other.m_destructorEnabled;
    m_requirements = other.m_requirements;
    m_info = std::move(other.m_info);
    other.m_image = VK_NULL_HANDLE;
    return *this;
}

void Image::bind(DeviceMemory& memory, size_t offset) {
    vkBindImageMemory(m_device->handle(), m_image, memory.handle(), offset);
}

void Image::getRequirements() {
    vkGetImageMemoryRequirements(m_device->handle(), m_image, &m_requirements);
}