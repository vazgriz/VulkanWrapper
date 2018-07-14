#include <iostream>
#include <string>
#include <VulkanWrapper/Instance.h>

int main() {
    auto layers = vk::Instance::availableLayers();
    auto extensions = vk::Instance::availableExtensions();

    std::cout << layers.size() << " available layers\n";
    for (auto& layer : layers) {
        std::cout << "    " << layer.layerName << "\n";
    }

    std::cout << extensions.size() << " available extensions\n";
    for (auto& extension : extensions) {
        std::cout << "    " << extension.extensionName << "\n";
    }

    vk::InstanceCreateInfo info = {};
    info.enabledLayerNames = { "VK_LAYER_LUNARG_standard_validation" };

    vk::Instance instance(info);
    auto& physicalDevices = instance.physicalDevices();

    std::cout << physicalDevices.size() << " physical devices available\n";
    for (auto& physicalDevice : physicalDevices) {
        std::cout << "    " << physicalDevice.properties().deviceName << "\n";
    }

    std::cin.ignore();
    return 0;
}