#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"
#include "Pipeline.h"

namespace vk {
    class Device;

    class ComputePipelineCreateInfo : public InfoMixin<ComputePipelineCreateInfo, VkComputePipelineCreateInfo> {
    public:
        PipelineCreateFlags flags;
        PipelineShaderStageCreateInfo stage;
        const PipelineLayout* layout;
        const Pipeline* basePipelineHandle;
        int32_t basePipelineIndex;

        void marshal() const;
    };

    class ComputePipeline : public Pipeline {
    public:
        ComputePipeline(Device& device, const ComputePipelineCreateInfo& info);
        ComputePipeline(const ComputePipeline& other) = delete;
        ComputePipeline& operator = (const ComputePipeline& other) = delete;
        ComputePipeline(ComputePipeline&& other);
        ComputePipeline& operator = (ComputePipeline&& other);
        //no destructor, handled by vk::Pipeline

        PipelineCreateFlags flags() const { return m_info.flags; }

    private:
        ComputePipelineCreateInfo m_info;
    };
}