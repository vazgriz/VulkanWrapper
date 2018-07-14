#include "VulkanWrapper/ShaderModule.h"
#include "VulkanWrapper/Device.h"
#include "VulkanWrapper/Instance.h"

using namespace vk;

void ShaderModuleCreateInfo::marshal() const {
    m_info.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    if (next != nullptr) {
        next->marshal();
        m_info.pNext = next->info();
    } else {
        m_info.pNext = nullptr;
    }

    m_info.flags = 0;
    m_info.codeSize = code.size();
    m_info.pCode = reinterpret_cast<const uint32_t*>(code.data());
}

ShaderModule::ShaderModule(Device& device, const ShaderModuleCreateInfo& info) {
    //don't copy to avoid expensive vector copy
    info.marshal();

    VKW_CHECK(vkCreateShaderModule(device.handle(), info.getInfo(), device.instance().callbacks(), &m_shaderModule));
    m_device = &device;
}

ShaderModule::ShaderModule(ShaderModule&& other) {
    m_device = other.m_device;
    m_shaderModule = other.m_shaderModule;
    other.m_shaderModule = VK_NULL_HANDLE;
}

ShaderModule& ShaderModule::operator = (ShaderModule&& other) {
    vkDestroyShaderModule(m_device->handle(), m_shaderModule, device().instance().callbacks());
    m_device = other.m_device;
    m_shaderModule = other.m_shaderModule;
    other.m_shaderModule = VK_NULL_HANDLE;
    return *this;
}

ShaderModule::~ShaderModule() {
    vkDestroyShaderModule(m_device->handle(), m_shaderModule, device().instance().callbacks());
}