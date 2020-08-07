#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class Device;

    class FenceCreateInfo : public InfoMixin<FenceCreateInfo, VkFenceCreateInfo> {
    public:
        FenceCreateFlags flags;

        void marshal() const;
    };

    class Fence {
    public:
        Fence(Device& device, const FenceCreateInfo& fence);
        Fence(const Fence& other) = delete;
        Fence& operator = (const Fence& other) = delete;
        Fence(Fence&& other);
        Fence& operator = (Fence&& other);
        ~Fence();

        VkFence handle() const { return m_fence; }
        Device& device() const { return *m_device; }

        FenceCreateFlags flags() const { return m_info.flags; }

        VkResult wait(uint64_t timeout = ~0ull) const;
        static VkResult wait(const Device& device, ArrayProxy<const Fence> fences, bool waitAll, uint64_t timeout = ~0ull);

        void reset();
        static void reset(const Device& device, ArrayProxy<Fence> fences);

    private:
        VkFence m_fence;
        Device* m_device;

        FenceCreateInfo m_info;
    };
}