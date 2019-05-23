#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"
#include "VulkanWrapper/PipelineLayout.h"

namespace vk {
    class Device;
    class ShaderModule;

    class SpecializationInfo : public InfoMixin<SpecializationInfo, VkSpecializationInfo> {
    public:
        std::vector<vk::SpecializationMapEntry> mapEntries;
        size_t dataSize;
        const void* data;

        void marshal() const;
    };

    class PipelineShaderStageCreateInfo : public InfoMixin<PipelineShaderStageCreateInfo, VkPipelineShaderStageCreateInfo> {
    public:
        PipelineShaderStageCreateFlags flags;
        ShaderStageFlags stage;
        const ShaderModule* module;
        std::string name;
        SpecializationInfo* specializationInfo;

        void marshal() const;
    };

    class Pipeline {
    public:
        Pipeline& operator = (Pipeline&& other);
        virtual ~Pipeline();

        VkPipeline handle() const { return m_pipeline; }
        Device& device() const { return *m_deviceRef; }

        const PipelineLayoutInfo& layoutInfo() { return m_layoutInfo; }

    protected:
        Pipeline(Device& device, const PipelineLayout& pipelineLayout);
        Pipeline(Pipeline&& other);

        VkPipeline m_pipeline;
        VkDevice m_device;
        Device* m_deviceRef;
        PipelineLayoutInfo m_layoutInfo;
    };
}