#include "VulkanWrapper/Instance.h"
#include <cstring>
#include <iostream>
#include <string>

void vk::ApplicationInfo::Write(VkApplicationInfo& info) const {
    info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    info.pApplicationName = applicationName.c_str();
    info.applicationVersion = applicationVersion;
    info.pEngineName = engineName.c_str();
    info.engineVersion = engineVersion;
    info.apiVersion = apiVersion;
}

void vk::InstanceCreateInfo::Write(void* ptr) const {
    VkInstanceCreateInfo& info = *reinterpret_cast<VkInstanceCreateInfo*>(ptr);
    info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    info.flags = static_cast<VkInstanceCreateFlags>(flags);

    //copy info to temporary variables
    if (applicationInfo != nullptr) {
        pApplicationInfo = Marshal(*applicationInfo);
        info.pApplicationInfo = reinterpret_cast<const VkApplicationInfo*>(pApplicationInfo.data());
    } else {
        info.pApplicationInfo = nullptr;
    }

    for (auto& str : enabledLayerNames) {
        ppEnabledLayerNames.push_back(str.c_str());
    }

    for (auto& str : enabledExtensionNames) {
        ppEnabledExtensionNames.push_back(str.c_str());
    }

    info.enabledLayerCount = static_cast<uint32_t>(ppEnabledLayerNames.size());
    info.ppEnabledLayerNames = ppEnabledLayerNames.data();
    info.enabledExtensionCount = static_cast<uint32_t>(ppEnabledExtensionNames.size());
    info.ppEnabledExtensionNames = ppEnabledExtensionNames.data();
}

vk::Instance::Instance(const InstanceCreateInfo& info, const VkAllocationCallbacks* callbacks) {
    if (callbacks != nullptr) {
        this->callbacks = *callbacks;
        callbacksPtr = &this->callbacks;
    }

    std::vector<char> buffer = vk::CreateInfo::Marshal(info);

    VKW_CHECK(vkCreateInstance(
        reinterpret_cast<VkInstanceCreateInfo*>(buffer.data()),
        GetCallbacks(),
        &instance
    ));

    EnumeratePhysicalDevices();
}

void vk::Instance::EnumeratePhysicalDevices() {
    uint32_t count;
    vkEnumeratePhysicalDevices(instance, &count, nullptr);
    std::vector<VkPhysicalDevice> physicalDevices(count);
    vkEnumeratePhysicalDevices(instance, &count, physicalDevices.data());

    for (auto physicalDevice : physicalDevices) {
        this->physicalDevices.push_back(vk::PhysicalDevice(physicalDevice));
    }
}

std::vector<vk::LayerProperties> vk::Instance::GetAvailableLayers() {
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

std::vector<vk::ExtensionProperties> vk::Instance::GetAvailableExtensions(const char* layerName) {
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
    vkDestroyInstance(instance, GetCallbacks());
}