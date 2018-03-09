#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;
    class DescriptorSetLayout;

    class PipelineLayoutCreateInfo : public CreateInfo<VkPipelineLayoutCreateInfo> {
    public:
        std::vector<std::reference_wrapper<DescriptorSetLayout>> setLayouts;
        std::vector<PushConstantRange> pushConstantRanges;

        void marshal() const;

    private:
        mutable std::vector<VkDescriptorSetLayout> m_setLayouts;
    };

    class PipelineLayout {
    public:
        PipelineLayout(Device& device, const PipelineLayoutCreateInfo& info);
        PipelineLayout(const PipelineLayout& other) = delete;
        PipelineLayout& operator = (const PipelineLayout& other) = delete;
        PipelineLayout(PipelineLayout&& other) = default;
        ~PipelineLayout();

        VkPipelineLayout handle() const { return m_pipelineLayout; }
        Device& device() const { return m_device; }

    private:
        VkPipelineLayout m_pipelineLayout;
        Device& m_device;
    };
}