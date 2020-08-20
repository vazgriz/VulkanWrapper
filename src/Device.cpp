#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"
#include "VulkanWrapper/PhysicalDevice.h"
#include "VulkanWrapper/Queue.h"
#include "VulkanWrapper/CommandBuffer.h"

using namespace vk;

void DeviceQueueCreateInfo::marshal() const {
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

void DeviceCreateInfo::marshal() const {
    m_queueInfos.clear();
    m_layers.clear();
    m_extensions.clear();

    m_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

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

Device::Device(const PhysicalDevice& physicalDevice, const DeviceCreateInfo& info) {
    m_info = info;
    m_info.marshal();

    VKW_CHECK(vkCreateDevice(physicalDevice.handle(), m_info.getInfo(), physicalDevice.instance().callbacks(), &m_device));
    m_instance = &physicalDevice.instance();
    m_physicalDevice = &physicalDevice;

    getQueues(info);
}

Device::Device(Device&& other) {
    m_instance = other.m_instance;
    m_physicalDevice = other.m_physicalDevice;
    m_device = other.m_device;
    m_info = std::move(other.m_info);
    m_queueMap = std::move(other.m_queueMap);
    other.m_device = VK_NULL_HANDLE;
}

Device& Device::operator = (Device&& other) {
    vkDestroyDevice(m_device, instance().callbacks());
    m_instance = other.m_instance;
    m_physicalDevice = other.m_physicalDevice;
    m_device = other.m_device;
    m_info = std::move(other.m_info);
    m_queueMap = std::move(other.m_queueMap);
    other.m_device = VK_NULL_HANDLE;
    return *this;
}

const std::vector<std::string>& Device::layers() const {
    return instance().layers();
}

Device::~Device() {
    vkDestroyDevice(m_device, instance().callbacks());
}

const Queue& Device::getQueue(uint32_t familyIndex, uint32_t queueIndex) const {
    return m_queueMap.at(familyIndex)[queueIndex];
}

void Device::getQueues(const DeviceCreateInfo& info) {
    for (auto& queueInfo : info.queueCreateInfos) {
        std::vector<Queue> queues;
        queues.reserve(queueInfo.queueCount);

        for (uint32_t i = 0; i < queueInfo.queueCount; i++) {
            VkQueue queue;
            vkGetDeviceQueue(m_device, queueInfo.queueFamilyIndex, i, &queue);
            queues.emplace_back(*this, queue, queueInfo.queueFamilyIndex);
        }

        m_queueMap.emplace(queueInfo.queueFamilyIndex, std::move(queues));
    }
}

void Device::waitIdle() const {
    vkDeviceWaitIdle(m_device);
}