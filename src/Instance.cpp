#include "VulkanWrapper/Instance.h"

using namespace vk;

void ApplicationInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.pApplicationName = applicationName.c_str();
    m_info.applicationVersion = applicationVersion;

    if (engineName.size() > 0) {
        m_info.pEngineName = engineName.c_str();
    } else {
        m_info.pEngineName = nullptr;
    }

    m_info.engineVersion = engineVersion;
    m_info.apiVersion = apiVersion;
}

void InstanceCreateInfo::marshal() const {
    m_layers.clear();
    m_extensions.clear();

    m_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    m_info.flags = static_cast<VkInstanceCreateFlags>(flags);

    //copy info to temporary variables
    if (applicationInfo != nullptr) {
        applicationInfo->marshal();
        m_info.pApplicationInfo = applicationInfo->getInfo();
    } else {
        m_info.pApplicationInfo = nullptr;
    }

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
}

Instance::Instance(const InstanceCreateInfo& info, const VkAllocationCallbacks* callbacks) {
    if (callbacks != nullptr) {
        this->m_callbacks = *callbacks;
        m_callbacksPtr = &this->m_callbacks;
    }

    m_info = info;
    m_info.marshal();

    vkCreateInstance(m_info.getInfo(), this->callbacks(), &m_instance);

    EnumeratePhysicalDevices();
    if (m_info.applicationInfo != nullptr) {
        m_appInfo = *m_info.applicationInfo;
        m_info.applicationInfo = &m_appInfo;
    }
}

Instance::Instance(Instance&& other) {
    m_instance = other.m_instance;
    m_callbacks = other.m_callbacks;
    m_callbacksPtr = other.m_callbacksPtr;
    m_physicalDevices = std::move(other.m_physicalDevices);
    m_info = std::move(other.m_info);
    if (m_info.applicationInfo != nullptr) {
        m_appInfo = std::move(other.m_appInfo);
        m_info.applicationInfo = &m_appInfo;
    }
    other.m_instance = VK_NULL_HANDLE;
}

Instance& Instance::operator = (Instance&& other) {
    vkDestroyInstance(m_instance, callbacks());
    m_instance = other.m_instance;
    m_callbacks = other.m_callbacks;
    m_callbacksPtr = other.m_callbacksPtr;
    m_physicalDevices = std::move(other.m_physicalDevices);
    m_info = std::move(other.m_info);
    if (m_info.applicationInfo != nullptr) {
        m_appInfo = std::move(other.m_appInfo);
        m_info.applicationInfo = &m_appInfo;
    }
    other.m_instance = VK_NULL_HANDLE;
    return *this;
}

void Instance::EnumeratePhysicalDevices() {
    uint32_t count;
    vkEnumeratePhysicalDevices(m_instance, &count, nullptr);
    std::vector<VkPhysicalDevice> physicalDevices(count);
    vkEnumeratePhysicalDevices(m_instance, &count, physicalDevices.data());

    for (auto physicalDevice : physicalDevices) {
        this->m_physicalDevices.emplace_back(*this, physicalDevice);
    }
}

std::vector<LayerProperties> Instance::availableLayers() {
    uint32_t count;
    vkEnumerateInstanceLayerProperties(&count, nullptr);
    std::vector<VkLayerProperties> properties(count);
    vkEnumerateInstanceLayerProperties(&count, properties.data());

    std::vector<LayerProperties> result;
    result.reserve(count);
    for (auto& prop : properties) {
        result.emplace_back(prop);
    }

    return result;
}

std::vector<ExtensionProperties> Instance::availableExtensions(const std::string& layerName) {
    const char* pLayerName = nullptr;
    if (layerName.size() > 0) pLayerName = layerName.c_str();

    uint32_t count;
    vkEnumerateInstanceExtensionProperties(pLayerName, &count, nullptr);
    std::vector<VkExtensionProperties> properties(count);
    vkEnumerateInstanceExtensionProperties(pLayerName, &count, properties.data());

    std::vector<ExtensionProperties> result;
    result.reserve(count);
    for (auto& prop : properties) {
        result.emplace_back(prop);
    }

    return result;
}

Instance::~Instance() {
    vkDestroyInstance(m_instance, callbacks());
}