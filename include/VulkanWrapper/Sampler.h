#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;

    class SamplerCreateInfo : public InfoMixin<SamplerCreateInfo, VkSamplerCreateInfo> {
    public:
        SamplerCreateFlags flags;
        Filter magFilter;
        Filter minFilter;
        SamplerMipmapMode mipmapMode;
        SamplerAddressMode addressModeU;
        SamplerAddressMode addressModeV;
        SamplerAddressMode addressModeW;
        float mipLodBias;
        bool anisotropyEnable;
        float maxAnisotropy;
        bool compareEnable;
        CompareOp compareOp;
        float minLod;
        float maxLod;
        BorderColor borderColor;
        bool unnormalizedCoordinates;

        void marshal() const;
    };

    class Sampler {
    public:
        Sampler(Device& device, const SamplerCreateInfo& info);
        Sampler(const Sampler& other) = delete;
        Sampler& operator = (const Sampler& other) = delete;
        Sampler(Sampler&& other);
        Sampler& operator = (Sampler&& other);
        ~Sampler();

        VkSampler handle() const { return m_sampler; }
        Device& device() const { return *m_device; }

        SamplerCreateFlags flags() const { return m_info.getInfo().flags; }
        Filter magFilter() const { return m_info.getInfo().magFilter; }
        Filter minFilter() const { return m_info.getInfo().minFilter; }
        SamplerMipmapMode mipmapMode() const { return m_info.getInfo().mipmapMode; }
        SamplerAddressMode addressModeU() const { return m_info.getInfo().addressModeU; }
        SamplerAddressMode addressModeV() const { return m_info.getInfo().addressModeV; }
        SamplerAddressMode addressModeW() const { return m_info.getInfo().addressModeW; }
        float mipLodBias() const { return m_info.getInfo().mipLodBias; }
        bool anisotropyEnable() const { return m_info.getInfo().anisotropyEnable; }
        float maxAnisotropy() const { return m_info.getInfo().maxAnisotropy; }
        bool compareEnable() const { return m_info.getInfo().compareEnable; }
        CompareOp compareOp() const { return m_info.getInfo().compareOp; }
        float minLod() const { return m_info.getInfo().minLod; }
        float maxLod() const { return m_info.getInfo().maxLod; }
        BorderColor borderColor() const { return m_info.getInfo().borderColor; }
        bool unnormalizedCoordinates() const { return m_info.getInfo().unnormalizedCoordinates; }

    private:
        VkSampler m_sampler;
        Device* m_device;

        InfoChain<SamplerCreateInfo> m_info;
    };
}