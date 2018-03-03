cmake_minimum_required(VERSION 3.9)
project(VulkanWrapper)

add_library(VulkanWrapper
    CreateInfo.cpp
    Utilities.cpp
    Instance.cpp
    PhysicalDevice.cpp
)
target_include_directories(VulkanWrapper PUBLIC "$ENV{VK_SDK_PATH}/include" "${CMAKE_SOURCE_DIR}/include")