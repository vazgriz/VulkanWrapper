#include "VulkanWrapper/Framebuffer.h"
#include "VulkanWrapper/RenderPass.h"
#include "VulkanWrapper/ImageView.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

void FramebufferCreateInfo::marshal() const {
    m_attachments.clear();

    m_info.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = 0;
    m_info.renderPass = renderPass->handle();

    m_attachments.reserve(attachments.size());
    for (const ImageView& attachment : attachments) {
        m_attachments.push_back(attachment.handle());
    }

    m_info.attachmentCount = static_cast<uint32_t>(m_attachments.size());
    m_info.pAttachments = m_attachments.data();
    m_info.width = width;
    m_info.height = height;
    m_info.layers = layers;
}

Framebuffer::Framebuffer(Device& device, const FramebufferCreateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateFramebuffer(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_framebuffer));
    m_device = &device;
}

Framebuffer::Framebuffer(Framebuffer&& other) {
    m_device = other.m_device;
    m_framebuffer = other.m_framebuffer;
    m_info = std::move(other.m_info);
    other.m_framebuffer = VK_NULL_HANDLE;
}

Framebuffer& Framebuffer::operator = (Framebuffer&& other) {
    vkDestroyFramebuffer(m_device->handle(), m_framebuffer, device().instance().callbacks());
    m_device = other.m_device;
    m_framebuffer = other.m_framebuffer;
    m_info = std::move(other.m_info);
    other.m_framebuffer = VK_NULL_HANDLE;
    return *this;
}

Framebuffer::~Framebuffer() {
    vkDestroyFramebuffer(m_device->handle(), m_framebuffer, device().instance().callbacks());
}