#include "VulkanWrapper/DescriptorSet.h"
#include "VulkanWrapper/DescriptorPool.h"
#include "VulkanWrapper/Sampler.h"
#include "VulkanWrapper/Buffer.h"
#include "VulkanWrapper/BufferView.h"
#include "VulkanWrapper/ImageView.h"
#include "VulkanWrapper/Device.h"

using namespace vk;

void DescriptorImageInfo::marshal() const {
    if (sampler != nullptr) {
        m_info.sampler = sampler->handle();
    } else {
        m_info.sampler = VK_NULL_HANDLE;
    }

    if (imageView != nullptr) {
        m_info.imageView = imageView->handle();
    } else {
        m_info.imageView = VK_NULL_HANDLE;
    }

    m_info.imageLayout = static_cast<VkImageLayout>(imageLayout);
}

void DescriptorBufferInfo::marshal() const {
    m_info.buffer = buffer->handle();
    m_info.offset = offset;
    m_info.range = range;
}

void WriteDescriptorSet::marshal() const {
    m_imageInfo.clear();
    m_bufferInfo.clear();
    m_texelBufferView.clear();

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
    case DescriptorType::Sampler:
    case DescriptorType::CombinedImageSampler:
    case DescriptorType::SampledImage:
    case DescriptorType::StorageImage:
    case DescriptorType::InputAttachment:
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
    case DescriptorType::UniformTexelBuffer:
    case DescriptorType::StorageTexelBuffer:
    {
        m_info.descriptorCount = static_cast<uint32_t>(texelBufferView.size());

        m_texelBufferView.reserve(texelBufferView.size());
        for (const BufferView& info : texelBufferView) {
            m_texelBufferView.push_back(info.handle());
        }

        m_info.pTexelBufferView = m_texelBufferView.data();
        break;
    }
    case DescriptorType::UniformBuffer:
    case DescriptorType::StorageBuffer:
    case DescriptorType::UniformBufferDynamic:
    case DescriptorType::StorageBufferDynamic:
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

void CopyDescriptorSet::marshal() const {
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

DescriptorSet::DescriptorSet(Device& device, DescriptorPool& pool, VkDescriptorSet descriptorSet, std::vector<DescriptorSetLayoutCreateInfo> layoutInfos) {
    m_device = device.handle();
    m_deviceRef = &device;
    m_pool = &pool;
    m_descriptorSet = descriptorSet;
    m_destructorEnabled = false;

    m_layoutInfos.resize(layoutInfos.size());
    for (size_t i = 0; i < m_layoutInfos.size(); i++) {
        m_layoutInfos[i] = layoutInfos[i];
    }
}

DescriptorSet::DescriptorSet(DescriptorSet&& other) {
    m_device = other.m_device;
    m_deviceRef = other.m_deviceRef;
    m_pool = other.m_pool;
    m_descriptorSet = other.m_descriptorSet;
    m_destructorEnabled = other.m_destructorEnabled;
    m_layoutInfos = std::move(other.m_layoutInfos);
    other.m_descriptorSet = VK_NULL_HANDLE;
}

DescriptorSet& DescriptorSet::operator = (DescriptorSet&& other) {
    if (m_destructorEnabled) vkFreeDescriptorSets(m_device, m_pool->handle(), 1, &m_descriptorSet);
    m_device = other.m_device;
    m_deviceRef = other.m_deviceRef;
    m_pool = other.m_pool;
    m_descriptorSet = other.m_descriptorSet;
    m_destructorEnabled = other.m_destructorEnabled;
    m_layoutInfos = std::move(other.m_layoutInfos);
    other.m_descriptorSet = VK_NULL_HANDLE;
    return *this;
}

DescriptorSet::~DescriptorSet() {
    if (m_destructorEnabled) vkFreeDescriptorSets(m_device, m_pool->handle(), 1, &m_descriptorSet);
}

void DescriptorSet::update(const Device& device, ArrayProxy<const WriteDescriptorSet> writes, ArrayProxy<const CopyDescriptorSet> copies) {
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