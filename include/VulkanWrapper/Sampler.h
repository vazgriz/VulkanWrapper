#pragma once
#include <vulkan/vulkan.h>
#include "VulkanWrapper/Info.h"
#include "VulkanWrapper/ArrayProxy.h"
#include "VulkanWrapper/enums.h"
#include "VulkanWrapper/Utilities.h"
#include "VulkanWrapper/structs.h"

namespace vk {
    class Device;

    class SamplerCreateInfo : public Info<VkSamplerCreateInfo> {
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
        ~Sampler();

        VkSampler handle() const { return m_sampler; }
        Device& device() const { return m_device; }

    private:
        VkSampler m_sampler;
        Device& m_device;
    };
}