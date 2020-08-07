#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"
#include "VulkanWrapper/DescriptorSetLayout.h"

namespace vk {
    class Device;
    class DescriptorPool;
    class DescriptorSet;
    class Sampler;
    class ImageView;
    class BufferView;
    class Buffer;

    struct DescriptorImageInfo {
        const Sampler* sampler;
        const ImageView* imageView;
        ImageLayout imageLayout;

        void marshal() const;
        const VkDescriptorImageInfo& getInfo() const { return m_info; }

    private:
        mutable VkDescriptorImageInfo m_info;
    };

    struct DescriptorBufferInfo {
        const Buffer* buffer;
        DeviceSize offset;
        DeviceSize range;

        void marshal() const;
        const VkDescriptorBufferInfo& getInfo() const { return m_info; }

    private:
        mutable VkDescriptorBufferInfo m_info;
    };

    class WriteDescriptorSet : public InfoMixin<WriteDescriptorSet, VkWriteDescriptorSet> {
    public:
        const DescriptorSet* dstSet;
        uint32_t dstBinding;
        uint32_t dstArrayElement;
        DescriptorType descriptorType;
        std::vector<DescriptorImageInfo> imageInfo;
        std::vector<DescriptorBufferInfo> bufferInfo;
        std::vector<std::reference_wrapper<const BufferView>> texelBufferView;

        void marshal() const;

    private:
        mutable std::vector<VkDescriptorImageInfo> m_imageInfo;
        mutable std::vector<VkDescriptorBufferInfo> m_bufferInfo;
        mutable std::vector<VkBufferView> m_texelBufferView;
    };

    class CopyDescriptorSet : public InfoMixin<CopyDescriptorSet, VkCopyDescriptorSet> {
    public:
        const DescriptorSet* srcSet;
        uint32_t srcBinding;
        uint32_t srcArrayElement;
        const DescriptorSet* dstSet;
        uint32_t dstBinding;
        uint32_t dstArrayElement;
        uint32_t descriptorCount;

        void marshal() const;
    };

    class DescriptorSet {
    public:
        DescriptorSet(Device& device, vk::DescriptorPool& pool, VkDescriptorSet descriptorSet, std::vector<DescriptorSetLayoutCreateInfo> layoutInfos);
        DescriptorSet(const DescriptorSet& other) = delete;
        DescriptorSet& operator = (const DescriptorSet& other) = delete;
        DescriptorSet(DescriptorSet&& other);
        DescriptorSet& operator = (DescriptorSet&& other);
        ~DescriptorSet();

        VkDescriptorSet handle() const { return m_descriptorSet; }
        Device& device() const { return *m_deviceRef; }
        DescriptorPool& pool() const { return *m_pool; }

        void setDestructorEnabled(bool value) { m_destructorEnabled = value; }

        const std::vector<DescriptorSetLayoutCreateInfo>& layoutInfos() const { return m_layoutInfos; }

        static void update(const Device& device, ArrayProxy<const WriteDescriptorSet> writes, ArrayProxy<const CopyDescriptorSet> copies);

    private:
        VkDescriptorSet m_descriptorSet;
        VkDevice m_device;
        Device* m_deviceRef;
        DescriptorPool* m_pool;

        bool m_destructorEnabled;
        std::vector<DescriptorSetLayoutCreateInfo> m_layoutInfos;
    };
}