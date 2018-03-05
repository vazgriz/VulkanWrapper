#include "VulkanWrapper/Queue.h"

vk::Queue::Queue(Device& device, VkQueue queue) : m_device(device) {
    m_queue = queue;
}