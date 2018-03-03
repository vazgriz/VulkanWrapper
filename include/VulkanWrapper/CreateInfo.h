#pragma once
#include <vector>

namespace vk {
    class CreateInfo {
    public:
        CreateInfo();

        virtual size_t GetSize() const = 0;
        virtual void Write(void* ptr) const = 0;
        static std::vector<char> Marshal(const CreateInfo& info);

        CreateInfo* next;
    };

    template<typename T>
    class CreateInfo_ : public CreateInfo {
    public:
        size_t GetSize() const {
            return sizeof(T);
        }
    };
}