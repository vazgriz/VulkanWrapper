#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class Device;

    class Pipeline {
    public:
        virtual ~Pipeline();

        VkPipeline handle() const { return m_pipeline; }
        Device& device() const { return m_device; }

    protected:
        Pipeline(Device& device);

        VkPipeline m_pipeline;
        Device& m_device;
    };
}