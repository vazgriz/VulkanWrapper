#include "VulkanWrapper/DescriptorSet.h"
#include "VulkanWrapper/DescriptorPool.h"
#include "VulkanWrapper/Sampler.h"
#include "VulkanWrapper/Buffer.h"
#include "VulkanWrapper/BufferView.h"
#include "VulkanWrapper/ImageView.h"
#include "VulkanWrapper/Device.h"

void vk::DescriptorImageInfo::marshal() const {
    m_info.sampler = sampler->handle();
    m_info.imageView = imageView->handle();
    m_info.imageLayout = static_cast<VkImageLayout>(imageLayout);
}

void vk::DescriptorBufferInfo::marshal() const {
    m_info.buffer = buffer->handle();
    m_info.offset = offset;
    m_info.range = range;
}

void vk::WriteDescriptorSet::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.dstSet = dstSet->handle();
    m_info.dstBinding = dstBinding;
    m_info.dstArrayElement = dstArrayElement;
    m_info.descriptorType = static_cast<VkDescriptorType>(descriptorType);
    switch (descriptorType) {
        case vk::DescriptorType::Sampler:
        case vk::DescriptorType::CombinedImageSampler:
        case vk::DescriptorType::SampledImage:
        case vk::DescriptorType::StorageImage:
        case vk::DescriptorType::InputAttachment:
        {
            m_info.descriptorCount = static_cast<uint32_t>(imageInfo.size());

            m_imageInfo.reserve(imageInfo.size());
            for (auto& info : imageInfo) {
                info.marshal();
                m_imageInfo.push_back(info.getInfo());
            }

            m_info.pImageInfo = m_imageInfo.data();
            break;
        }
        case vk::DescriptorType::UniformTexelBuffer:
        case vk::DescriptorType::StorageTexelBuffer:
        {
            m_info.descriptorCount = static_cast<uint32_t>(texelBufferView.size());

            m_texelBufferView.reserve(texelBufferView.size());
            for (const vk::BufferView& info : texelBufferView) {
                m_texelBufferView.push_back(info.handle());
            }

            m_info.pTexelBufferView = m_texelBufferView.data();
            break;
        }
        case vk::DescriptorType::UniformBuffer:
        case vk::DescriptorType::StorageBuffer:
        case vk::DescriptorType::UniformBufferDynamic:
        case vk::DescriptorType::StorageBufferDynamic:
        {
            m_info.descriptorCount = static_cast<uint32_t>(bufferInfo.size());

            m_bufferInfo.reserve(bufferInfo.size());
            for (auto& info : bufferInfo) {
                info.marshal();
                m_bufferInfo.push_back(info.getInfo());
            }

            m_info.pBufferInfo = m_bufferInfo.data();
            break;
        }
    }
}

void vk::CopyDescriptorSet::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.srcSet = srcSet->handle();
    m_info.srcBinding = srcBinding;
    m_info.srcArrayElement = srcArrayElement;
    m_info.dstSet = dstSet->handle();
    m_info.dstBinding = dstBinding;
    m_info.dstArrayElement = m_info.dstArrayElement;
    m_info.descriptorCount = descriptorCount;
}

vk::DescriptorSet::DescriptorSet(Device& device, vk::DescriptorPool& pool, VkDescriptorSet descriptorSet) : m_device(device), m_pool(pool) {
    m_descriptorSet = descriptorSet;
    m_destructorEnabled = false;
}

vk::DescriptorSet::DescriptorSet(vk::DescriptorSet&& other) : m_device(other.device()), m_pool(other.pool()) {
    m_descriptorSet = other.m_descriptorSet;
    m_destructorEnabled = other.m_destructorEnabled;
    other.m_descriptorSet = VK_NULL_HANDLE;
}

vk::DescriptorSet::~DescriptorSet() {
    if (m_destructorEnabled) vkFreeDescriptorSets(m_device.handle(), m_pool.handle(), 1, &m_descriptorSet);
}

void vk::DescriptorSet::update(const Device& device, vk::ArrayProxy<const WriteDescriptorSet> writes, vk::ArrayProxy<const CopyDescriptorSet> copies) {
    std::vector<VkWriteDescriptorSet> vkWrites;
    vkWrites.reserve(writes.size());
    for (auto& write : writes) {
        write.marshal();
        vkWrites.push_back(*write.getInfo());
    }

    std::vector<VkCopyDescriptorSet> vkCopies;
    vkCopies.reserve(copies.size());
    for (auto& copy : copies) {
        copy.marshal();
        vkCopies.push_back(*copy.getInfo());
    }

    vkUpdateDescriptorSets(device.handle(), writes.size(), vkWrites.data(), copies.size(), vkCopies.data());
}