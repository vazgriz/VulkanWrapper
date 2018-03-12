#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"
#include "VulkanWrapper/Pipeline.h"

namespace vk {
    class RenderPass;
    class ShaderModule;
    class PipelineLayout;

    class PipelineVertexInputStateCreateInfo : public Info<VkPipelineVertexInputStateCreateInfo> {
    public:
        PipelineVertexInputStateCreateFlags flags;
        std::vector<VertexInputBindingDescription> vertexBindingDescriptions;
        std::vector<VertexInputAttributeDescription> vertexAttributeDescriptions;

        void marshal() const;
    };

    class PipelineInputAssemblyStateCreateInfo : public Info<VkPipelineInputAssemblyStateCreateInfo> {
    public:
        PipelineInputAssemblyStateCreateFlags flags;
        PrimitiveTopology topology;
        bool primitiveRestartEnable;

        void marshal() const;
    };

    class PipelineTessellationStateCreateInfo : public Info<VkPipelineTessellationStateCreateInfo> {
    public:
        PipelineTessellationStateCreateFlags flags;
        uint32_t patchControlPoints;

        void marshal() const;
    };

    class PipelineViewportStateCreateInfo : public Info<VkPipelineViewportStateCreateInfo> {
    public:
        PipelineViewportStateCreateFlags flags;
        std::vector<Viewport> viewports;
        std::vector<Rect2D> scissors;

        void marshal() const;
    };

    class PipelineRasterizationStateCreateInfo : public Info<VkPipelineRasterizationStateCreateInfo> {
    public:
        PipelineRasterizationStateCreateFlags flags;
        bool depthClampEnable;
        bool rasterizerDiscardEnable;
        PolygonMode polygonMode;
        CullModeFlags cullMode;
        FrontFace frontFace;
        bool depthBiasEnable;
        float depthBiasConstantFactor;
        float depthBiasClamp;
        float depthBiasSlopeFactor;
        float lineWidth;

        void marshal() const;
    };

    class PipelineMultisampleStateCreateInfo : public Info<VkPipelineMultisampleStateCreateInfo> {
    public:
        PipelineMultisampleStateCreateFlags flags;
        SampleCountFlags rasterizationSamples;
        bool sampleShadingEnable;
        float minSampleShading;
        std::vector<SampleMask> sampleMask;
        bool alphaToCoverageEnable;
        bool alphaToOneEnable;

        void marshal() const;
    };

    class PipelineDepthStencilStateCreateInfo : public Info<VkPipelineDepthStencilStateCreateInfo> {
    public:
        PipelineDepthStencilStateCreateFlags flags;
        bool depthTestEnable;
        bool depthWriteEnable;
        CompareOp depthCompareOp;
        bool depthBoundsTestEnable;
        bool stencilTestEnable;
        StencilOpState front;
        StencilOpState back;
        float minDepthBounds;
        float maxDepthBounds;

        void marshal() const;
    };

    class PipelineColorBlendStateCreateInfo : public Info<VkPipelineColorBlendStateCreateInfo> {
    public:
        PipelineColorBlendStateCreateFlags flags;
        bool logicOpEnable;
        LogicOp logicOp;
        std::vector<PipelineColorBlendAttachmentState> attachments;
        float blendConstants[4];

        void marshal() const;

    private:
        mutable std::vector<VkPipelineColorBlendAttachmentState> m_attachments;
    };

    class PipelineDynamicStateCreateInfo : public Info<VkPipelineDynamicStateCreateInfo> {
    public:
        PipelineDynamicStateCreateFlags flags;
        std::vector<DynamicState> dynamicStates;

        void marshal() const;
    };

    class GraphicsPipelineCreateInfo : public Info<VkGraphicsPipelineCreateInfo> {
    public:
        PipelineCreateFlags flags;
        std::vector<PipelineShaderStageCreateInfo> stages;
        const PipelineVertexInputStateCreateInfo* vertexInputState;
        const PipelineInputAssemblyStateCreateInfo* inputAssemblyState;
        const PipelineTessellationStateCreateInfo* tessellationState;
        const PipelineViewportStateCreateInfo* viewportState;
        const PipelineRasterizationStateCreateInfo* rasterizationState;
        const PipelineMultisampleStateCreateInfo* multisampleState;
        const PipelineDepthStencilStateCreateInfo* depthStencilState;
        const PipelineColorBlendStateCreateInfo* colorBlendState;
        const PipelineDynamicStateCreateInfo* dynamicState;
        const PipelineLayout* layout;
        const RenderPass* renderPass;
        uint32_t subpass;
        const Pipeline* basePipelineHandle;
        int32_t basePipelineIndex;

        void marshal() const;

    private:
        mutable std::vector<VkPipelineShaderStageCreateInfo> m_stages;
    };

    class GraphicsPipeline : public Pipeline {
    public:
        GraphicsPipeline(Device& device, const GraphicsPipelineCreateInfo& info);
        GraphicsPipeline(const GraphicsPipeline& other) = delete;
        GraphicsPipeline& operator = (const GraphicsPipeline& other) = delete;
        GraphicsPipeline(GraphicsPipeline&& other) : Pipeline(std::move(other)) { }
        //no destructor, handled by vk::Pipeline
    };
}