#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class Device;
    class CommandBufferAllocateInfo;
    class CommandBuffer;

    class CommandPoolCreateInfo : public Info<VkCommandPoolCreateInfo> {
    public:
        CommandPoolCreateFlags flags;
        uint32_t queueFamilyIndex;

        void marshal() const;
    };

    class CommandPool {
    public:
        CommandPool(Device& device, const CommandPoolCreateInfo& info);
        CommandPool(const CommandPool& other) = delete;
        CommandPool& operator = (const CommandPool& other) = delete;
        CommandPool(CommandPool&& other);
        ~CommandPool();

        VkCommandPool handle() const { return m_commandPool; }
        Device& device() const { return m_device; }

        static std::vector<CommandBuffer> allocate(const CommandBufferAllocateInfo& info);

    private:
        VkCommandPool m_commandPool;
        Device& m_device;
        uint32_t m_queueFamilyIndex;
    };
}