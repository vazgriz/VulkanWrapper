#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;

    struct AttachmentDescription {
        AttachmentDescriptionFlags flags;
        Format format;
        SampleCountFlags samples;
        AttachmentLoadOp loadOp;
        AttachmentStoreOp storeOp;
        AttachmentLoadOp stencilLoadOp;
        AttachmentStoreOp stencilStoreOp;
        ImageLayout initialLayout;
        ImageLayout finalLayout;
    };

    struct AttachmentReference {
        uint32_t attachment;
        ImageLayout layout;
    };

    struct SubpassDescription {
        SubpassDescriptionFlags flags;
        PipelineBindPoint pipelineBindPoint;
        std::vector<AttachmentReference> inputAttachments;
        std::vector<AttachmentReference> colorAttachments;
        std::vector<AttachmentReference> resolveAttachments;
        const AttachmentReference* depthStencilAttachment;
        std::vector<uint32_t> preserveAttachments;

        void marshal() const;
        const VkSubpassDescription& info() const { return m_info; }

    private:
        mutable VkSubpassDescription m_info;
    };

    struct SubpassDependency {
        uint32_t srcSubpass;
        uint32_t dstSubpass;
        PipelineStageFlags srcStageMask;
        PipelineStageFlags dstStageMask;
        AccessFlags srcAccessMask;
        AccessFlags dstAccessMask;
        DependencyFlags dependencyFlags;
    };

    class RenderPassCreateInfo : public InfoMixin<RenderPassCreateInfo, VkRenderPassCreateInfo> {
    public:
        RenderPassCreateFlags flags;
        std::vector<AttachmentDescription> attachments;
        std::vector<SubpassDescription> subpasses;
        std::vector<SubpassDependency> dependencies;

        void marshal() const;

    private:
        mutable std::vector<VkSubpassDescription> m_subpasses;
    };

    class RenderPass {
    public:
        RenderPass(Device& device, const RenderPassCreateInfo& info);
        RenderPass(const RenderPass& other) = delete;
        RenderPass& operator = (const RenderPass& other) = delete;
        RenderPass(RenderPass&& other);
        RenderPass& operator = (RenderPass&& other);
        ~RenderPass();

        VkRenderPass handle() const { return m_renderPass; }
        Device& device() const { return *m_device; }

        RenderPassCreateFlags flags() const { return m_info.flags; }
        const std::vector<AttachmentDescription> attachments() const { return m_info.attachments; }
        const std::vector<SubpassDescription> subpasses() const { return m_info.subpasses; }
        const std::vector<SubpassDependency> dependencies() const { return m_info.dependencies; }

    private:
        VkRenderPass m_renderPass;
        Device* m_device;

        RenderPassCreateInfo m_info;
    };
}