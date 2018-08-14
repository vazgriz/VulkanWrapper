#include "VulkanWrapper/RenderPass.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

void SubpassDescription::marshal() const {
    m_info.flags = static_cast<VkSubpassDescriptionFlags>(flags);
    m_info.pipelineBindPoint = static_cast<VkPipelineBindPoint>(pipelineBindPoint);
    m_info.inputAttachmentCount = static_cast<uint32_t>(inputAttachments.size());
    m_info.pInputAttachments = reinterpret_cast<const VkAttachmentReference*>(inputAttachments.data());
    m_info.colorAttachmentCount = static_cast<uint32_t>(colorAttachments.size());
    m_info.pColorAttachments = reinterpret_cast<const VkAttachmentReference*>(colorAttachments.data());
    m_info.pResolveAttachments = reinterpret_cast<const VkAttachmentReference*>(resolveAttachments.data());
    m_info.pDepthStencilAttachment = reinterpret_cast<const VkAttachmentReference*>(depthStencilAttachment);
    m_info.preserveAttachmentCount = static_cast<uint32_t>(preserveAttachments.size());
    m_info.pPreserveAttachments = preserveAttachments.data();
}

void RenderPassCreateInfo::marshal() const {
    m_subpasses.clear();

    m_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkRenderPassCreateFlags>(flags);
    m_info.attachmentCount = static_cast<uint32_t>(attachments.size());
    m_info.pAttachments = reinterpret_cast<const VkAttachmentDescription*>(attachments.data());

    m_subpasses.reserve(subpasses.size());
    for (auto& subpass : subpasses) {
        subpass.marshal();
        m_subpasses.push_back(subpass.info());
    }

    m_info.subpassCount = static_cast<uint32_t>(m_subpasses.size());
    m_info.pSubpasses = m_subpasses.data();
    m_info.dependencyCount = static_cast<uint32_t>(dependencies.size());
    m_info.pDependencies = reinterpret_cast<const VkSubpassDependency*>(dependencies.data());
}

RenderPass::RenderPass(Device& device, const RenderPassCreateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateRenderPass(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_renderPass));
    m_device = &device;
}

RenderPass::RenderPass(RenderPass&& other) {
    m_device = other.m_device;
    m_renderPass = other.m_renderPass;
    m_info = std::move(other.m_info);
    other.m_renderPass = VK_NULL_HANDLE;
}

RenderPass& RenderPass::operator = (RenderPass&& other) {
    vkDestroyRenderPass(m_device->handle(), m_renderPass, device().instance().callbacks());
    m_device = other.m_device;
    m_renderPass = other.m_renderPass;
    m_info = std::move(other.m_info);
    other.m_renderPass = VK_NULL_HANDLE;
    return *this;
}

RenderPass::~RenderPass() {
    vkDestroyRenderPass(m_device->handle(), m_renderPass, device().instance().callbacks());
}