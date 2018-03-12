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
    class PipelineLayout;

    class ComputePipelineCreateInfo : public Info<VkComputePipelineCreateInfo> {
    public:
        PipelineCreateFlags flags;
        PipelineShaderStageCreateInfo stage;
        const PipelineLayout* layout;
        const Pipeline* basePipelineHandle;
        int32_t basePipelineIndex;

        void marshal() const;
    };

    class ComputePipeline : public Pipeline {
        ComputePipeline(Device& device, const ComputePipelineCreateInfo& info);
        ComputePipeline(const ComputePipeline& other) = delete;
        ComputePipeline& operator = (const ComputePipeline& other) = delete;
        ComputePipeline(ComputePipeline&& other);
        //no destructor, handled by vk::Pipeline
    };
}