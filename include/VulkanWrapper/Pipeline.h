#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;
    class ShaderModule;

    class PipelineShaderStageCreateInfo : public Info<VkPipelineShaderStageCreateInfo> {
    public:
        PipelineShaderStageCreateFlags flags;
        ShaderStageFlags stage;
        const ShaderModule* module;
        std::string name;
        const SpecializationInfo* specializationInfo;

        void marshal() const;
    };

    class Pipeline {
    public:
        virtual ~Pipeline();

        VkPipeline handle() const { return m_pipeline; }
        Device& device() const { return m_device; }

    protected:
        Pipeline(Device& device);
        Pipeline(Pipeline&& other);

        VkPipeline m_pipeline;
        Device& m_device;
    };
}