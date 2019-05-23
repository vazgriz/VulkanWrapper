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
        Image(Device& device, VkImage image, const ImageCreateInfo& info, bool enableDestructor);
        Image(const Image& image) = delete;
        Image& operator = (const Image& other) = delete;
        Image(Image&& other);
        Image& operator = (Image&& other);
        ~Image();

        VkImage handle() const { return m_image; }
        Device& device() const { return *m_device; }

        ImageCreateFlags flags() const { return m_info.getInfo().flags; }
        ImageType imageType() const { return m_info.getInfo().imageType; }
        Format format() const { return m_info.getInfo().format; }
        Extent3D extent() const { return m_info.getInfo().extent; }
        uint32_t mipLevels() const { return m_info.getInfo().mipLevels; }
        uint32_t arrayLayers() const { return m_info.getInfo().arrayLayers; }
        SampleCountFlags samples() const { return m_info.getInfo().samples; }
        ImageTiling tiling() const { return m_info.getInfo().tiling; }
        ImageUsageFlags usage() const { return m_info.getInfo().usage; }
        SharingMode sharingMode() const { return m_info.getInfo().sharingMode; }
        const std::vector<uint32_t>& queueFamilyIndices() { return m_info.getInfo().queueFamilyIndices; }

        void bind(DeviceMemory& memory, size_t offset);

        MemoryRequirements requirements() const { return m_requirements; }

    private:
        void getRequirements();

        VkImage m_image;
        Device* m_device;
        bool m_destructorEnabled;

        InfoChain<ImageCreateInfo> m_info;
        MemoryRequirements m_requirements;
    };
}