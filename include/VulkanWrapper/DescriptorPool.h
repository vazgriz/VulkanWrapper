#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;
    class DescriptorSetAllocateInfo;
    class DescriptorSet;
    class DescriptorSetLayout;
    class DescriptorPool;

    class DescriptorSetAllocateInfo : public Info<VkDescriptorSetAllocateInfo> {
    public:
        const DescriptorPool* descriptorPool;
        std::vector<std::reference_wrapper<DescriptorSetLayout>> setLayouts;

        void marshal() const;

    private:
        mutable std::vector<VkDescriptorSetLayout> m_layouts;
    };

    class DescriptorPoolCreateInfo : public Info<VkDescriptorPoolCreateInfo> {
    public:
        DescriptorPoolCreateFlags flags;
        uint32_t maxSets;
        std::vector<DescriptorPoolSize> poolSizes;

        void marshal() const;
    };

    class DescriptorPool {
    public:
        DescriptorPool(Device& device, const DescriptorPoolCreateInfo& info);
        DescriptorPool(const DescriptorPool& other) = delete;
        DescriptorPool& operator = (const DescriptorPool& other) = delete;
        DescriptorPool(DescriptorPool&& other);
        ~DescriptorPool();

        VkDescriptorPool handle() const { return m_descriptorPool; }
        Device& device() const { return m_device; }

        std::vector<vk::DescriptorSet> allocate(const DescriptorSetAllocateInfo& info);

    private:
        VkDescriptorPool m_descriptorPool;
        Device& m_device;
    };
}