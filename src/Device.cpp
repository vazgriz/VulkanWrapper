#include "VulkanWrapper/Device.h"

void vk::DeviceQueueCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
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

    m_queueInfos.resize(queueCreateInfos.size());
    for (size_t i = 0; i < queueCreateInfos.size(); i++) {
        queueCreateInfos[i].marshal();
        std::memcpy(&m_queueInfos[i], &queueCreateInfos[i].info(), sizeof(VkDeviceQueueCreateInfo));
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
    m_info.ppEnabledExtensionNames = m_layers.data();

    if (enabledFeatures != nullptr) {
        m_info.pEnabledFeatures = enabledFeatures;
    }
}

vk::Device::Device(const PhysicalDevice& physicalDevice, const DeviceCreateInfo& info) : m_instance(physicalDevice.instance()) {
    info.marshal();

    VKW_CHECK(vkCreateDevice(physicalDevice.handle(), &info.info(), physicalDevice.instance().callbacks(), &m_device));

    m_extensions = info.enabledExtensionNames;
}

vk::Device::~Device() {
    vkDestroyDevice(m_device, m_instance.callbacks());
}