#include "VulkanWrapper/Instance.h"
#include <cstring>
#include <iostream>
#include <string>

void vk::ApplicationInfo::write(void* ptr) const {
    VkApplicationInfo& info = *reinterpret_cast<VkApplicationInfo*>(ptr);
    info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    info.pApplicationName = applicationName.c_str();
    info.applicationVersion = applicationVersion;
    info.pEngineName = engineName.c_str();
    info.engineVersion = engineVersion;
    info.apiVersion = apiVersion;
}

void vk::InstanceCreateInfo::write(void* ptr) const {
    VkInstanceCreateInfo& info = *reinterpret_cast<VkInstanceCreateInfo*>(ptr);
    info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    info.flags = static_cast<VkInstanceCreateFlags>(flags);

    //copy info to temporary variables
    if (applicationInfo != nullptr) {
        m_applicationInfo = marshal(*applicationInfo);
        info.pApplicationInfo = reinterpret_cast<const VkApplicationInfo*>(m_applicationInfo.data());
    } else {
        info.pApplicationInfo = nullptr;
    }

    for (auto& str : enabledLayerNames) {
        m_enabledLayerNames.push_back(str.c_str());
    }

    for (auto& str : enabledExtensionNames) {
        m_enabledExtensionNames.push_back(str.c_str());
    }

    info.enabledLayerCount = static_cast<uint32_t>(m_enabledLayerNames.size());
    info.ppEnabledLayerNames = m_enabledLayerNames.data();
    info.enabledExtensionCount = static_cast<uint32_t>(m_enabledExtensionNames.size());
    info.ppEnabledExtensionNames = m_enabledExtensionNames.data();
}

vk::Instance::Instance(const InstanceCreateInfo& info, const VkAllocationCallbacks* callbacks) {
    if (callbacks != nullptr) {
        this->m_callbacks = *callbacks;
        m_callbacksPtr = &this->m_callbacks;
    }

    std::vector<char> buffer = vk::CreateInfo::marshal(info);

    vkCreateInstance(
        reinterpret_cast<VkInstanceCreateInfo*>(buffer.data()),
        this->callbacks(),
        &m_instance
    );

    EnumeratePhysicalDevices();
}

void vk::Instance::EnumeratePhysicalDevices() {
    uint32_t count;
    vkEnumeratePhysicalDevices(m_instance, &count, nullptr);
    std::vector<VkPhysicalDevice> physicalDevices(count);
    vkEnumeratePhysicalDevices(m_instance, &count, physicalDevices.data());

    for (auto physicalDevice : physicalDevices) {
        this->m_physicalDevices.push_back(vk::PhysicalDevice(physicalDevice));
    }
}

std::vector<vk::LayerProperties> vk::Instance::availableLayers() {
    uint32_t count;
    vkEnumerateInstanceLayerProperties(&count, nullptr);
    std::vector<VkLayerProperties> properties(count);
    vkEnumerateInstanceLayerProperties(&count, properties.data());

    std::vector<vk::LayerProperties> result;
    result.reserve(count);
    for (auto& prop : properties) {
        result.push_back(vk::LayerProperties(prop));
    }

    return result;
}

std::vector<vk::ExtensionProperties> vk::Instance::availableExtensions(const char* layerName) {
    uint32_t count;
    vkEnumerateInstanceExtensionProperties(layerName, &count, nullptr);
    std::vector<VkExtensionProperties> properties(count);
    vkEnumerateInstanceExtensionProperties(layerName, &count, properties.data());

    std::vector<vk::ExtensionProperties> result;
    result.reserve(count);
    for (auto& prop : properties) {
        result.push_back(vk::ExtensionProperties(prop));
    }

    return result;
}

vk::Instance::~Instance() {
    vkDestroyInstance(m_instance, callbacks());
}