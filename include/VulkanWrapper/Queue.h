#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class Device;
    class CommandBuffer;
    class Semaphore;
    class Fence;
    class Swapchain;

    class SubmitInfo : public Info<VkSubmitInfo> {
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

    class PresentInfo : public Info<VkPresentInfoKHR> {
    public:
        std::vector<std::reference_wrapper<vk::Semaphore>> waitSemaphores;
        std::vector<std::reference_wrapper<vk::Swapchain>> swapchains;
        std::vector<uint32_t> imageIndices;
        std::vector<Result> results;

        void marshal() const;
        void unmarshal();

    private:
        mutable std::vector<VkSemaphore> m_waitSemaphores;
        mutable std::vector<VkSwapchainKHR> m_swapchains;
        mutable std::vector<VkResult> m_results;
    };

    class Queue {
    public:
        Queue(Device& device, VkQueue queue, uint32_t index);
        Queue(const Queue& other) = delete;
        Queue& operator = (const Queue& other) = delete;
        Queue(Queue&& other) = default;

        VkQueue handle() const { return m_queue; }
        Device& device() const { return **m_deviceRef; }

        uint32_t familyIndex() const { return m_familyIndex; }

        void waitIdle() const;
        void submit(ArrayProxy<const SubmitInfo> infos, const Fence* fence) const;
        Result present(PresentInfo& info) const;

    private:
        VkQueue m_queue;
        VkDevice m_device;
        Device** m_deviceRef;
        uint32_t m_familyIndex;
    };
}