#include "VulkanWrapper/Pipeline.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

vk::Pipeline::Pipeline(Device& device) : m_device(device) { }

vk::Pipeline::Pipeline(vk::Pipeline&& other) : m_device(other.device()) {
    m_pipeline = other.m_pipeline;
    other.m_pipeline = VK_NULL_HANDLE;
}

vk::Pipeline::~Pipeline() {
    vkDestroyPipeline(m_device.handle(), m_pipeline, m_device.instance().callbacks());
}