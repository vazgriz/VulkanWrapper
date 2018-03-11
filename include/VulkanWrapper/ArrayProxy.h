#pragma once
//from https://github.com/KhronosGroup/Vulkan-Hpp

// Copyright (c) 2015-2017 The Khronos Group Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <array>
#include <vector>

namespace vk {
    template <typename T>
    class ArrayProxy {
    public:
        ArrayProxy(std::nullptr_t)
            : m_count(0)
            , m_ptr(nullptr) {
        }

        ArrayProxy(T & ptr)
            : m_count(1)
            , m_ptr(&ptr) {
        }

        ArrayProxy(uint32_t count, T * ptr)
            : m_count(count)
            , m_ptr(ptr) {
        }

        template <size_t N>
        ArrayProxy(std::array<typename std::remove_const<T>::type, N> & data)
            : m_count(N)
            , m_ptr(data.data()) {
        }

        template <size_t N>
        ArrayProxy(std::array<typename std::remove_const<T>::type, N> const& data)
            : m_count(N)
            , m_ptr(data.data()) {
        }

        template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
        ArrayProxy(std::vector<typename std::remove_const<T>::type, Allocator> & data)
            : m_count(static_cast<uint32_t>(data.size()))
            , m_ptr(data.data()) {
        }

        template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
        ArrayProxy(std::vector<typename std::remove_const<T>::type, Allocator> const& data)
            : m_count(static_cast<uint32_t>(data.size()))
            , m_ptr(data.data()) {
        }

        ArrayProxy(const std::initializer_list<typename std::remove_const<T>::type>& data)
            : m_count(static_cast<uint32_t>(data.end() - data.begin()))
            , m_ptr(data.begin()) {
        }

        const T * begin() const {
            return m_ptr;
        }

        const T * end() const {
            return m_ptr + m_count;
        }

        const T & front() const {
            return *m_ptr;
        }

        const T & back() const {
            return *(m_ptr + m_count - 1);
        }

        bool empty() const {
            return (m_count == 0);
        }

        uint32_t size() const {
            return m_count;
        }

        T * data() const {
            return m_ptr;
        }

    private:
        uint32_t  m_count;
        T *       m_ptr;
    };
}