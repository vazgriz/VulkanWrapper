#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;

    class DescriptorSetLayoutBinding : public CreateInfo<VkDescriptorSetLayoutBinding> {
    public:
        uint32_t binding;
        DescriptorType descriptorType;
        size_t descriptorCount;
        ShaderStageFlags stageFlags;
        const VkSampler* pImmutableSamplers;

        void marshal() const;
    };

    class DescriptorSetLayoutCreateInfo : public CreateInfo<VkDescriptorSetLayoutCreateInfo> {
    public:
        DescriptorSetLayoutCreateFlags flags;
        std::vector<DescriptorSetLayoutBinding> bindings;

        void marshal() const;

    private:
        mutable std::vector<VkDescriptorSetLayoutBinding> m_bindings;
    };

    class DescriptorSetLayout {
    public:
        DescriptorSetLayout(Device& device, const DescriptorSetLayoutCreateInfo& info);
        DescriptorSetLayout(const DescriptorSetLayout& other) = delete;
        DescriptorSetLayout& operator = (const DescriptorSetLayout& other) = delete;
        DescriptorSetLayout(DescriptorSetLayout&& other) = default;
        ~DescriptorSetLayout();

        VkDescriptorSetLayout handle() const { return m_descriptorSetLayout; }
        Device& device() const { return m_device; }

    private:
        VkDescriptorSetLayout m_descriptorSetLayout;
        Device& m_device;
    };
}