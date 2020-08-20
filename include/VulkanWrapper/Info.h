#pragma once
#include <vector>
#include <queue>
#include "VulkanWrapper/ArrayProxy.h"

namespace vk {
    class Info {
    public:
        virtual void marshal() const = 0;
        virtual Info* clone() const = 0;
        virtual const void* info() const = 0;

        Info* next = nullptr;

        const void* nextInfo() const { return next; }
    };

    template <typename T, typename VK_T>
    class InfoMixin : public Info {
    public:
        Info* clone() const override { return new T(*dynamic_cast<const T*>(this)); }
        const void* info() const override { return &m_info; }
        const VK_T* getInfo() const { return &m_info; }
        VK_T* getMutableInfo() { return &m_info; }

    protected:
        mutable VK_T m_info;
    };
}