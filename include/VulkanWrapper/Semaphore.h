#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class Device;
    class Semaphore;

    class SemaphoreCreateInfo : public InfoMixin<SemaphoreCreateInfo, VkSemaphoreCreateInfo> {
    public:
        void marshal() const;
    };

    class SemaphoreTypeCreateInfo : public InfoMixin<SemaphoreTypeCreateInfo, VkSemaphoreTypeCreateInfo> {
    public:
        void marshal() const;

        SemaphoreType semaphoreType;
        uint64_t initialValue;
    };

    class TimelineSemaphoreSubmitInfo : public InfoMixin<TimelineSemaphoreSubmitInfo, VkTimelineSemaphoreSubmitInfo> {
    public:
        void marshal() const;

        std::vector<uint64_t> waitSemaphoreValues;
        std::vector<uint64_t> signalSemaphoreValues;
    };

    class SemaphoreWaitInfo : public InfoMixin<SemaphoreWaitInfo, VkSemaphoreWaitInfo> {
    public:
        void marshal() const;

        SemaphoreWaitFlags flags;
        std::vector<std::reference_wrapper<Semaphore>> semaphores;
        std::vector<uint64_t> values;

    private:
        mutable std::vector<VkSemaphore> m_semaphores;
    };

    class SemaphoreSignalInfo : public InfoMixin<SemaphoreSignalInfo, VkSemaphoreSignalInfo> {
    public:
        void marshal() const;

        Semaphore* semaphore;
        uint64_t value;
    };

    class Semaphore {
    public:
        Semaphore(Device& device, const SemaphoreCreateInfo& info);
        Semaphore(const Semaphore& other) = delete;
        Semaphore& operator = (const Semaphore& other) = delete;
        Semaphore(Semaphore&& other);
        Semaphore& operator = (Semaphore&& other);
        ~Semaphore();

        VkSemaphore handle() const { return m_sempahore; }
        Device& device() const { return *m_device; }

        static vk::Result wait(vk::Device& device, vk::SemaphoreWaitInfo& info, uint64_t timeout);
        static void signal(vk::Device& device, vk::SemaphoreSignalInfo& info);

    private:
        VkSemaphore m_sempahore;
        Device* m_device;

        SemaphoreCreateInfo m_info;
    };
}