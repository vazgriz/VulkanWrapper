#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class Device;
    class Semaphore;
    class Fence;

    class SubmitInfo : public CreateInfo<VkSubmitInfo> {
    public:
        std::vector<std::reference_wrapper<Semaphore>> waitSemaphores;
        std::vector<PipelineStageFlags> waitDstStageMask;
        std::vector<std::reference_wrapper<CommandBuffer>> commandBuffers;
        std::vector<std::reference_wrapper<Semaphore>> signalSemaphores;

        void marshal() const;

    private:
        mutable std::vector<VkSemaphore> m_waitSemaphores;
        mutable std::vector<VkCommandBuffer> m_commandBuffers;
        mutable std::vector<VkSemaphore> m_signalSemaphores;
    };

    class Queue {
    public:
        Queue(Device& device, VkQueue queue, uint32_t index);

        VkQueue handle() const { return m_queue; }
        Device& device() const { return m_device; }

        uint32_t familyIndex() const { return m_familyIndex; }

        void submit(ArrayProxy<const SubmitInfo> infos, const Fence* fence) const;

    private:
        VkQueue m_queue;
        Device& m_device;
        uint32_t m_familyIndex;
    };
}