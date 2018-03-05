#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class Device;
    class CommandBufferAllocateInfo;
    class CommandBuffer;

    class CommandPoolCreateInfo : public CreateInfo<VkCommandPoolCreateInfo> {
    public:
        CommandPoolCreateFlags flags;
        uint32_t queueFamilyIndex;

        void marshal() const;
    };

    class CommandPool {
    public:
        CommandPool(Device& device, const CommandPoolCreateInfo& info);
        ~CommandPool();

        VkCommandPool handle() const { return m_commandPool; }
        Device& device() const { return m_device; }

        std::vector<CommandBuffer> allocate(const CommandBufferAllocateInfo& info) const;

    private:
        VkCommandPool m_commandPool;
        Device& m_device;
        uint32_t m_queueFamilyIndex;
    };
}