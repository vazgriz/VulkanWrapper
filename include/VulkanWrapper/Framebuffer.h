#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class Device;
    class ImageView;
    class RenderPass;

    class FramebufferCreateInfo : public InfoMixin<FramebufferCreateInfo, VkFramebufferCreateInfo> {
    public:
        FramebufferCreateFlags flags;
        RenderPass* renderPass;
        std::vector<std::reference_wrapper<const ImageView>> attachments;
        uint32_t width;
        uint32_t height;
        uint32_t layers;

        void marshal() const;

    private:
        mutable std::vector<VkImageView> m_attachments;
    };

    class Framebuffer {
    public:
        Framebuffer(Device& device, const FramebufferCreateInfo& info);
        Framebuffer(const Framebuffer& other) = delete;
        Framebuffer& operator = (const Framebuffer& other) = delete;
        Framebuffer(Framebuffer&& other);
        Framebuffer& operator = (Framebuffer&& other);
        ~Framebuffer();

        VkFramebuffer handle() const { return m_framebuffer; }
        Device& device() const { return *m_device; }

        FramebufferCreateFlags flags() const { return m_info.flags; }
        RenderPass& renderPass() const { return *m_info.renderPass; }
        const std::vector<std::reference_wrapper<const ImageView>> attachments() const { return m_info.attachments; }
        uint32_t width() const { return m_info.width; }
        uint32_t height() const { return m_info.height; }
        uint32_t layers() const { return m_info.layers; }

    private:
        VkFramebuffer m_framebuffer;
        Device* m_device;

        FramebufferCreateInfo m_info;
    };
}