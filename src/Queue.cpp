#include "VulkanWrapper/VulkanWrapper.h"

vk::Queue::Queue(Device& device, VkQueue queue, uint32_t index) : m_device(device) {
    m_queue = queue;
    m_familyIndex = index;
}