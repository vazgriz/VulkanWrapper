#pragma once
#include <vector>

namespace vk {
    class CreateInfo {
    public:
        CreateInfo();

        virtual size_t size() const = 0;
        virtual void write(void* ptr) const = 0;
        static std::vector<char> marshal(const CreateInfo& info);

        CreateInfo* next = nullptr;
    };

    template<typename T>
    class CreateInfo_ : public CreateInfo {
    public:
        size_t size() const {
            return sizeof(T);
        }
    };
}