#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;
    class DescriptorPool;
    class DescriptorSetLayout;
    class DescriptorSet;
    class Sampler;
    class ImageView;
    class BufferView;
    class Buffer;

    class DescriptorSetAllocateInfo : public Info<VkDescriptorSetAllocateInfo> {
    public:
        const DescriptorPool* descriptorPool;
        std::vector<std::reference_wrapper<DescriptorSetLayout>> setLayouts;

        void marshal() const;

    private:
        mutable std::vector<VkDescriptorSetLayout> m_layouts;
    };

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

    class WriteDescriptorSet : public Info<VkWriteDescriptorSet> {
    public:
        const DescriptorSet* dstSet;
        uint32_t dstBinding;
        uint32_t dstArrayElement;
        DescriptorType descriptorType;
        std::vector<DescriptorImageInfo> imageInfo;
        std::vector<DescriptorBufferInfo> bufferInfo;
        std::vector<std::reference_wrapper<const BufferView>> texelBufferView;

        void marshal() const;
    };
    
    class CopyDescriptorSet : public Info<VkCopyDescriptorSet> {
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
        DescriptorSet(Device& device, vk::DescriptorPool& pool, VkDescriptorSet descriptorSet);
        DescriptorSet(const DescriptorSet& other) = delete;
        DescriptorSet& operator = (const DescriptorSet& other) = delete;
        DescriptorSet(DescriptorSet&& other);
        ~DescriptorSet();

        VkDescriptorSet handle() const { return m_descriptorSet; }
        Device& device() const { return m_device; }
        DescriptorPool& pool() const { return m_pool; }

        void setDestructorEnabled(bool value) { m_destructorEnabled = value; }

        static void update(const Device& device, ArrayProxy<WriteDescriptorSet> writes, ArrayProxy<CopyDescriptorSet> copies);

    private:
        VkDescriptorSet m_descriptorSet;
        Device& m_device;
        DescriptorPool& m_pool;
        bool m_destructorEnabled;
    };
}