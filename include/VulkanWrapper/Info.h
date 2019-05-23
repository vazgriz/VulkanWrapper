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

    protected:
        mutable VK_T m_info;
    };

    template<typename T>
    class InfoChain {
    public:
        InfoChain() : m_info({}) {}
        InfoChain(const InfoChain& other) = delete;
        InfoChain& operator = (const InfoChain& other) = delete;
        InfoChain(InfoChain&& other) = default;
        InfoChain& operator = (InfoChain&& other) = default;

        void operator = (const T& info) {
            m_info = info;

            //m_chain.clear();

            Info* prev = dynamic_cast<Info*>(&this->m_info);
            Info* current = m_info.next;
            while (current != nullptr) {
                //m_chain.emplace_back(std::unique_ptr<Info>(current->clone()));
                //prev->next = m_chain.back().get();
                prev = current;
                current = current->next;
            }
        }

        T& getInfo() {
            return m_info;
        }

        const T& getInfo() const {
            return m_info;
        }

    private:
        T m_info;
        //std::vector<std::unique_ptr<Info>> m_chain;
        std::vector<std::unique_ptr<int>> asdf;
    };
}