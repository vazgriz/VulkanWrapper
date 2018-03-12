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

    class DescriptorSetAllocateInfo : public Info<VkDescriptorSetAllocateInfo> {
    public:
        const DescriptorPool* descriptorPool;
        std::vector<std::reference_wrapper<DescriptorSetLayout>> setLayouts;

        void marshal() const;

    private:
        mutable std::vector<VkDescriptorSetLayout> m_layouts;
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

    private:
        VkDescriptorSet m_descriptorSet;
        Device& m_device;
        DescriptorPool& m_pool;
        bool m_destructorEnabled;
    };
}