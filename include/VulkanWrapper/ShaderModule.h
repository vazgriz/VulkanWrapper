#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/CreateInfo.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"

namespace vk {
    class Device;

    class ShaderModuleCreateInfo : public CreateInfo<VkShaderModuleCreateInfo> {
    public:
        std::vector<char> code;

        void marshal() const;
    };

    class ShaderModule {
    public:
        ShaderModule(Device& device, const ShaderModuleCreateInfo& info);
        ShaderModule(const ShaderModule& other) = delete;
        ShaderModule& operator = (const ShaderModule& other) = delete;
        ShaderModule(ShaderModule&& other) = default;
        ~ShaderModule();

        VkShaderModule handle() const { return m_shaderModule; }
        Device& device() const { return m_device; }

    private:
        VkShaderModule m_shaderModule;
        Device& m_device;
    };
}