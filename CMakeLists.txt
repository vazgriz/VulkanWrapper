cmake_minimum_required(VERSION 3.9)

find_library(VULKAN_LIB NAMES vulkan-1)
find_library(GLFW_LIB NAMES glfw3)

set(GLFW_INCLUDE)
set(GLSL_COMPILER)

add_subdirectory(src)
add_subdirectory(samples/Test)
add_subdirectory(samples/HelloTriangle)
add_subdirectory(samples/Vulkan-Tutorial)
