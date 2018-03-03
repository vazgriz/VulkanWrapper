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

std::vector<char> vk::CreateInfo::marshal(const vk::CreateInfo& info) {
    size_t totalSize = 0;
    std::vector<char> buffer(info.size());

    const CreateInfo* current = &info;
    while (true) {
        size_t index = totalSize;
        current->write(&buffer[index]);

        current = current->next;
        if (current != nullptr) {
            totalSize += current->size();
            Align(totalSize, 16);
            buffer.reserve(totalSize);
        } else {
            break;
        }
    }

    return buffer;
}