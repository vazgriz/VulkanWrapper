cmake_minimum_required(VERSION 3.9)
project(Test)

find_library(VULKAN_LIB HINTS "${VK_SDK_PATH}/lib")

add_executable(Test main.cpp)
target_include_directories(Test PUBLIC VulkanWrapper)
target_link_libraries(Test VulkanWrapper ${VULKAN_LIB})
