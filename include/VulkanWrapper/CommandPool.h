#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class Device;
    class CommandBuffer;
    class CommandPool;

    class CommandBufferAllocateInfo : public InfoMixin<CommandBufferAllocateInfo, VkCommandBufferAllocateInfo> {
    public:
        CommandPool* commandPool;
        CommandBufferLevel level;
        uint32_t commandBufferCount;

        void marshal() const;
    };

    class CommandPoolCreateInfo : public InfoMixin<CommandPoolCreateInfo, VkCommandPoolCreateInfo> {
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
        CommandPool& operator = (CommandPool&& other);
        ~CommandPool();

        VkCommandPool handle() const { return m_commandPool; }
        Device& device() const { return *m_device; }

        CommandPoolCreateFlags flags() const { return m_info.flags; }
        uint32_t queueFamilyIndex() const { return m_info.queueFamilyIndex; }

        static std::vector<CommandBuffer> allocate(const CommandBufferAllocateInfo& info);

    private:
        VkCommandPool m_commandPool;
        Device* m_device;

        CommandPoolCreateInfo m_info;
    };
}