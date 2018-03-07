#include "VulkanWrapper/VulkanWrapper.h"

void vk::FramebufferCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = &next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = 0;
    m_info.renderPass = renderPass->handle();
    
    m_attachments.reserve(attachments.size());
    for (vk::ImageView& attachment : attachments) {
        m_attachments.push_back(attachment.handle());
    }

    m_info.attachmentCount = static_cast<uint32_t>(m_attachments.size());
    m_info.pAttachments = m_attachments.data();
    m_info.width = width;
    m_info.height = height;
    m_info.layers = layers;
}

vk::Framebuffer::Framebuffer(Device& device, const FramebufferCreateInfo& info) : m_device(device) {
    info.marshal();

    VKW_CHECK(vkCreateFramebuffer(device.handle(), &info.info(), device.instance().callbacks(), &m_framebuffer));
}

vk::Framebuffer::~Framebuffer() {
    vkDestroyFramebuffer(m_device.handle(), m_framebuffer, m_device.instance().callbacks());
}