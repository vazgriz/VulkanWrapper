#include "VulkanWrapper/CreateInfo.h"

vk::CreateInfo::CreateInfo() {
    next = nullptr;
}

void Align(size_t& size, size_t alignment) {
    size_t unalign = size % alignment;

    if (unalign == 0) {
        return;
    } else {
        size += alignment - unalign;
    }
}

std::vector<char> vk::CreateInfo::Marshal(const vk::CreateInfo& info) {
    size_t totalSize = 0;
    std::vector<char> buffer(info.GetSize());

    const CreateInfo* current = &info;
    while (true) {
        size_t index = totalSize;
        current->Write(&buffer[index]);

        current = current->next;
        if (current != nullptr) {
            totalSize += current->GetSize();
            Align(totalSize, 16);
            buffer.reserve(totalSize);
        } else {
            break;
        }
    }

    return buffer;
}