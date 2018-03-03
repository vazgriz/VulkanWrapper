cmake_minimum_required(VERSION 3.9)
project(HelloTriangle)

add_executable(HelloTriangle main.cpp)
target_include_directories(HelloTriangle PUBLIC VulkanWrapper)
target_link_libraries(HelloTriangle VulkanWrapper ${VULKAN_LIB})
