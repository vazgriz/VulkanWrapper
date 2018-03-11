#pragma once
#include <vector>
#include <queue>
#include "VulkanWrapper/ArrayProxy.h"

namespace vk {
    template<typename T>
    class Info {
    public:
        const T& info() const { return m_info; }

        virtual void marshal() const = 0;
        Info* next = nullptr;

    protected:
        mutable T m_info;
    };
}