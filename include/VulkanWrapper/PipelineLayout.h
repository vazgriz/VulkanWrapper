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
    class PipelineLayout;

    struct PipelineLayoutInfo {
        PipelineLayoutInfo() = default;
        PipelineLayoutInfo(const PipelineLayout& pipelineLayout);
        PipelineLayoutInfo(PipelineLayoutInfo&& other);
        PipelineLayoutInfo& operator = (PipelineLayoutInfo&& other);
        std::vector<DescriptorSetLayoutCreateInfo> descriptorSetLayouts;
        std::vector<PushConstantRange> pushConstantRanges;
    };

    class PipelineLayoutCreateInfo : public InfoMixin<PipelineLayoutCreateInfo, VkPipelineLayoutCreateInfo> {
    public:
        std::vector<std::reference_wrapper<const DescriptorSetLayout>> setLayouts;
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
        PipelineLayout(PipelineLayout&& other);
        PipelineLayout& operator = (PipelineLayout&& other);
        ~PipelineLayout();

        VkPipelineLayout handle() const { return m_pipelineLayout; }
        Device& device() const { return *m_device; }

        const std::vector<DescriptorSetLayoutCreateInfo>& layoutInfos() const { return m_layoutInfos; }
        const std::vector<PushConstantRange>& pushConstantRanges() const { return m_info.pushConstantRanges; }

    private:
        VkPipelineLayout m_pipelineLayout;
        Device* m_device;

        PipelineLayoutCreateInfo m_info;
        std::vector<DescriptorSetLayoutCreateInfo> m_layoutInfos;
    };
}