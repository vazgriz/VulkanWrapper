#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"
#include "VulkanWrapper/PhysicalDevice.h"
#include "VulkanWrapper/Queue.h"
#include "VulkanWrapper/CommandBuffer.h"

void vk::DeviceQueueCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = static_cast<VkDeviceQueueCreateFlags>(flags);
    m_info.queueFamilyIndex = queueFamilyIndex;
    m_info.queueCount = queueCount;

    if (queueCount > 0) {
        m_info.pQueuePriorities = queuePriorities.data();
    }
}

void vk::DeviceCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    m_info.flags = static_cast<VkDeviceCreateFlags>(flags);

    m_queueInfos.reserve(queueCreateInfos.size());
    for (auto& queueCreateInfo : queueCreateInfos) {
        queueCreateInfo.marshal();
        m_queueInfos.push_back(*queueCreateInfo.getInfo());
    }

    m_info.queueCreateInfoCount = static_cast<uint32_t>(m_queueInfos.size());
    m_info.pQueueCreateInfos = m_queueInfos.data();

    for (auto& str : enabledLayerNames) {
        m_layers.push_back(str.c_str());
    }

    for (auto& str : enabledExtensionNames) {
        m_extensions.push_back(str.c_str());
    }

    m_info.enabledLayerCount = static_cast<uint32_t>(m_layers.size());
    m_info.ppEnabledLayerNames = m_layers.data();
    m_info.enabledExtensionCount = static_cast<uint32_t>(m_extensions.size());
    m_info.ppEnabledExtensionNames = m_extensions.data();

    if (enabledFeatures != nullptr) {
        m_info.pEnabledFeatures = enabledFeatures;
    }
}

vk::Device::Device(const PhysicalDevice& physicalDevice, const DeviceCreateInfo& info) : m_instance(physicalDevice.instance()), m_physicalDevice(physicalDevice) {
    info.marshal();

    VKW_CHECK(vkCreateDevice(physicalDevice.handle(), info.getInfo(), physicalDevice.instance().callbacks(), &m_device));

    m_extensions = info.enabledExtensionNames;
    getQueues(info);
}

vk::Device::Device(Device&& other) : m_instance(other.instance()), m_physicalDevice(other.physicalDevice()) {
    m_device = other.m_device;
    m_extensions = std::move(other.m_extensions);
    m_queueMap = std::move(other.m_queueMap);
    other.m_device = VK_NULL_HANDLE;
}

const std::vector<std::string>& vk::Device::layers() const {
    return m_instance.layers();
}

vk::Device::~Device() {
    vkDestroyDevice(m_device, m_instance.callbacks());
}

const vk::Queue& vk::Device::getQueue(uint32_t familyIndex, uint32_t queueIndex) const {
    return m_queueMap.at(familyIndex)[queueIndex];
}

void vk::Device::getQueues(const DeviceCreateInfo& info) {
    for (auto& queueInfo : info.queueCreateInfos) {
        std::vector<Queue> queues;
        queues.reserve(queueInfo.queueCount);

        for (uint32_t i = 0; i < queueInfo.queueCount; i++) {
            VkQueue queue;
            vkGetDeviceQueue(m_device, queueInfo.queueFamilyIndex, i, &queue);
            queues.emplace_back(*this, queue, i);
        }

        m_queueMap.emplace(queueInfo.queueFamilyIndex, std::move(queues));
    }
}

void vk::Device::waitIdle() const {
    vkDeviceWaitIdle(m_device);
}