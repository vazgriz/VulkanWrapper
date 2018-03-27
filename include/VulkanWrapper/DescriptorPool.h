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
        Device& device() const { return **m_deviceRef; }

        DescriptorPoolCreateFlags flags() const { return m_info.flags; }
        uint32_t maxSets() const { return m_info.maxSets; }
        const std::vector<DescriptorPoolSize>& poolSizes() const { return m_info.poolSizes; }

        std::vector<vk::DescriptorSet> allocate(const DescriptorSetAllocateInfo& info);

    private:
        VkDescriptorPool m_descriptorPool;
        VkDevice m_device;
        Device** m_deviceRef;

        DescriptorPoolCreateInfo m_info;
    };
}