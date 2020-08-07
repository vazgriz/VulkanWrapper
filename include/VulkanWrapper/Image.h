#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;
    class DeviceMemory;

    class ImageCreateInfo : public InfoMixin<ImageCreateInfo, VkImageCreateInfo> {
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
        Image(Device& device, VkImage image, bool enableDestructor, const ImageCreateInfo* info = nullptr);
        Image(const Image& image) = delete;
        Image& operator = (const Image& other) = delete;
        Image(Image&& other);
        Image& operator = (Image&& other);
        ~Image();

        VkImage handle() const { return m_image; }
        Device& device() const { return *m_device; }
        void setInfo(const ImageCreateInfo& info) { m_info = info; }

        ImageCreateFlags flags() const { return m_info.flags; }
        ImageType imageType() const { return m_info.imageType; }
        Format format() const { return m_info.format; }
        Extent3D extent() const { return m_info.extent; }
        uint32_t mipLevels() const { return m_info.mipLevels; }
        uint32_t arrayLayers() const { return m_info.arrayLayers; }
        SampleCountFlags samples() const { return m_info.samples; }
        ImageTiling tiling() const { return m_info.tiling; }
        ImageUsageFlags usage() const { return m_info.usage; }
        SharingMode sharingMode() const { return m_info.sharingMode; }
        const std::vector<uint32_t>& queueFamilyIndices() { return m_info.queueFamilyIndices; }

        void bind(DeviceMemory& memory, size_t offset);

        MemoryRequirements requirements() const { return m_requirements; }

    private:
        void getRequirements();

        VkImage m_image;
        Device* m_device;
        bool m_destructorEnabled;

        ImageCreateInfo m_info;
        MemoryRequirements m_requirements;
    };
}