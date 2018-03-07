#pragma once
#include <vulkan/vulkan.h>

namespace vk {
    class Device;
    class ImageView;
    class RenderPass;

    class FramebufferCreateInfo : public CreateInfo<VkFramebufferCreateInfo> {
    public:
        FramebufferCreateFlags flags;
        RenderPass* renderPass;
        std::vector<std::reference_wrapper<ImageView>> attachments;
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
        Framebuffer(Framebuffer&& other) = default;
        ~Framebuffer();

        VkFramebuffer handle() const { return m_framebuffer; }
        Device& device() const { return m_device; }

    private:
        VkFramebuffer m_framebuffer;
        Device& m_device;
    };
}