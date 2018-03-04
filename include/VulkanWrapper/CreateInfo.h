#pragma once
#include <vector>
#include <queue>
#include "VulkanWrapper/ArrayProxy.h"

namespace vk {
    template<typename T>
    class CreateInfo {
    public:
        size_t size() const {
            return sizeof(T);
        }

        const T& info() const { return m_info; }

        virtual void marshal() const = 0;
        CreateInfo* next = nullptr;

    protected:
        mutable T m_info;
    };
}