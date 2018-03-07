#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class SemaphoreCreateInfo : public CreateInfo<VkSemaphoreCreateInfo> {
    public:
        void marshal() const;
    };

    class Semaphore {
    public:
        Semaphore(Device& device, const SemaphoreCreateInfo& info);
        Semaphore(const Semaphore& other) = delete;
        Semaphore& operator = (const Semaphore& other) = delete;
        Semaphore(Semaphore&& other) = default;
        ~Semaphore();

        VkSemaphore handle() const { return m_sempahore; }
        Device& device() const { return m_device; }

    private:
        VkSemaphore m_sempahore;
        Device& m_device;
    };
}