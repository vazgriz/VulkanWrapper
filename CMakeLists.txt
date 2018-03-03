cmake_minimum_required(VERSION 3.9)

find_library(VULKAN_LIB HINTS "${VK_SDK_PATH}/lib")

add_subdirectory(src)
add_subdirectory(samples/Test)