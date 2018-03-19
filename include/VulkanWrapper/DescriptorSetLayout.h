#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;
    class Sampler;

    class DescriptorSetLayoutBinding : public Info<VkDescriptorSetLayoutBinding> {
    public:
        uint32_t binding;
        DescriptorType descriptorType;
        uint32_t descriptorCount;
        ShaderStageFlags stageFlags;
        std::vector<std::reference_wrapper<Sampler>> immutableSamplers;

        void marshal() const;

    private:
        mutable std::vector<VkSampler> m_samplers;
    };

    class DescriptorSetLayoutCreateInfo : public Info<VkDescriptorSetLayoutCreateInfo> {
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
        DescriptorSetLayout(DescriptorSetLayout&& other);
        ~DescriptorSetLayout();

        VkDescriptorSetLayout handle() const { return m_descriptorSetLayout; }
        Device& device() const { return m_device; }

    private:
        VkDescriptorSetLayout m_descriptorSetLayout;
        Device& m_device;
    };
}