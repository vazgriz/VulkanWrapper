#include "VulkanWrapper/Sampler.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

void vk::SamplerCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkSamplerCreateFlags>(flags);
    m_info.magFilter = static_cast<VkFilter>(magFilter);
    m_info.minFilter = static_cast<VkFilter>(minFilter);
    m_info.mipmapMode = static_cast<VkSamplerMipmapMode>(mipmapMode);
    m_info.addressModeU = static_cast<VkSamplerAddressMode>(addressModeU);
    m_info.addressModeV = static_cast<VkSamplerAddressMode>(addressModeV);
    m_info.addressModeW = static_cast<VkSamplerAddressMode>(addressModeW);
    m_info.mipLodBias = mipLodBias;
    m_info.anisotropyEnable = anisotropyEnable;
    m_info.maxAnisotropy = maxAnisotropy;
    m_info.compareEnable = compareEnable;
    m_info.compareOp = static_cast<VkCompareOp>(compareOp);
    m_info.minLod = minLod;
    m_info.maxLod = maxLod;
    m_info.borderColor = static_cast<VkBorderColor>(borderColor);
    m_info.unnormalizedCoordinates = unnormalizedCoordinates;
}

vk::Sampler::Sampler(Device& device, const vk::SamplerCreateInfo& info) : m_device(device) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateSampler(device.handle(), m_info.getInfo(), device.instance().callbacks(), &m_sampler));
}

vk::Sampler::Sampler(Sampler&& other) :m_device(other.m_device) {
    m_sampler = other.m_sampler;
    m_info = std::move(other.m_info);
    other.m_sampler = VK_NULL_HANDLE;
}

vk::Sampler::~Sampler() {
    vkDestroySampler(m_device.handle(), m_sampler, m_device.instance().callbacks());
}