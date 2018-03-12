#pragma once
#include <vector>
#include <queue>
#include "VulkanWrapper/ArrayProxy.h"

namespace vk {
    class Info_ {
    public:
        virtual void marshal() const = 0;
        Info_* next = nullptr;

        const void* info() const { return next; }
    };

    template<typename T>
    class Info : public Info_ {
    public:
        const T* getInfo() const { return &m_info; }
    protected:
        mutable T m_info;
    };
}