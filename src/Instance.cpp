#include "VulkanWrapper/Instance.h"

void vk::ApplicationInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = &next->info();
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

void vk::InstanceCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    m_info.flags = static_cast<VkInstanceCreateFlags>(flags);

    //copy info to temporary variables
    if (applicationInfo != nullptr) {
        applicationInfo->marshal();
        m_info.pApplicationInfo = &applicationInfo->info();
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

vk::Instance::Instance(const InstanceCreateInfo& info, const VkAllocationCallbacks* callbacks) {
    if (callbacks != nullptr) {
        this->m_callbacks = *callbacks;
        m_callbacksPtr = &this->m_callbacks;
    }

    info.marshal();

    vkCreateInstance(
        &info.info(),
        this->callbacks(),
        &m_instance
    );

    EnumeratePhysicalDevices();
    m_layers = info.enabledLayerNames;
    m_extensions = info.enabledExtensionNames;
}

vk::Instance::Instance(vk::Instance&& other) {
    m_instance = other.m_instance;
    m_callbacks = other.m_callbacks;
    m_callbacksPtr = other.m_callbacksPtr;
    m_physicalDevices = std::move(other.m_physicalDevices);
    m_layers = std::move(other.m_layers);
    m_extensions = std::move(other.m_extensions);
    other.m_instance = VK_NULL_HANDLE;
}

void vk::Instance::EnumeratePhysicalDevices() {
    uint32_t count;
    vkEnumeratePhysicalDevices(m_instance, &count, nullptr);
    std::vector<VkPhysicalDevice> physicalDevices(count);
    vkEnumeratePhysicalDevices(m_instance, &count, physicalDevices.data());

    for (auto physicalDevice : physicalDevices) {
        this->m_physicalDevices.emplace_back(*this, physicalDevice);
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
        result.emplace_back(prop);
    }

    return result;
}

std::vector<vk::ExtensionProperties> vk::Instance::availableExtensions(const std::string& layerName) {
    const char* pLayerName = nullptr;
    if (layerName.size() > 0) pLayerName = layerName.c_str();

    uint32_t count;
    vkEnumerateInstanceExtensionProperties(pLayerName, &count, nullptr);
    std::vector<VkExtensionProperties> properties(count);
    vkEnumerateInstanceExtensionProperties(pLayerName, &count, properties.data());

    std::vector<vk::ExtensionProperties> result;
    result.reserve(count);
    for (auto& prop : properties) {
        result.emplace_back(prop);
    }

    return result;
}

vk::Instance::~Instance() {
    vkDestroyInstance(m_instance, callbacks());
}