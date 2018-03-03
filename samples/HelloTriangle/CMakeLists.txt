cmake_minimum_required(VERSION 3.9)
project(HelloTriangle)

find_library(VULKAN_LIB HINTS "${VK_SDK_PATH}/lib")

add_executable(HelloTriangle main.cpp)
target_include_directories(HelloTriangle PUBLIC VulkanWrapper)
target_link_libraries(HelloTriangle VulkanWrapper ${VULKAN_LIB})
