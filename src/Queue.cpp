#include "VulkanWrapper/Queue.h"

vk::Queue::Queue(const Device& device, VkQueue queue) : m_device(device) {
    m_queue = queue;
}