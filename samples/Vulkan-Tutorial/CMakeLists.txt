cmake_minimum_required(VERSION 3.9)
project(Vulkan_Tutorial)

add_custom_command(OUTPUT shader.frag
	COMMAND ${GLSL_COMPILER} ${PROJECT_SOURCE_DIR}/shader.frag -o ${PROJECT_BINARY_DIR}/shader.frag.spv
	DEPENDS shader.frag)

add_custom_command(OUTPUT shader.vert
	COMMAND ${GLSL_COMPILER} ${PROJECT_SOURCE_DIR}/shader.vert -o ${PROJECT_BINARY_DIR}/shader.vert.spv
	DEPENDS shader.frag)

add_custom_target(Vulkan_Tutorial_CompileShaders ALL
	DEPENDS shader.frag shader.vert)

add_executable(Vulkan_Tutorial main.cpp)
target_include_directories(Vulkan_Tutorial PUBLIC VulkanWrapper ${GLFW_INCLUDE})
target_link_libraries(Vulkan_Tutorial VulkanWrapper ${VULKAN_LIB} ${GLFW_LIB})
add_dependencies(Vulkan_Tutorial Vulkan_Tutorial_CompileShaders)