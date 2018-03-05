cmake_minimum_required(VERSION 3.9)
project(VulkanWrapper)

add_library(VulkanWrapper
    Instance.cpp
    Surface.cpp
    PhysicalDevice.cpp
    Device.cpp
    Queue.cpp
    Swapchain.cpp
    Semaphore.cpp
)
target_include_directories(VulkanWrapper PUBLIC "$ENV{VK_SDK_PATH}/include" "${CMAKE_SOURCE_DIR}/include")