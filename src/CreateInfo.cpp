#include "VulkanWrapper/CreateInfo.h"

void Align(size_t& size, size_t alignment) {
    size_t unalign = size % alignment;

    if (unalign == 0) {
        return;
    } else {
        size += alignment - unalign;
    }
}

std::vector<char> vk::CreateInfo::marshal(const vk::CreateInfo& info) {
    size_t index = 0;
    size_t totalSize = info.size();
    std::vector<char> buffer(totalSize);

    const CreateInfo* current = &info;
    while (true) {
        current->write(&buffer[index]);
        current = current->next;

        if (current == nullptr) {
            break;
        } else {
            Align(totalSize, 16);
            index = totalSize;
            totalSize += current->size();
            buffer.reserve(totalSize);
        }
    }

    return buffer;
}