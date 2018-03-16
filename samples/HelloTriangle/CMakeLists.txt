cmake_minimum_required(VERSION 3.9)
project(HelloTriangle)

add_custom_command(OUTPUT hello.frag
	COMMAND ${GLSL_COMPILER} ${PROJECT_SOURCE_DIR}/hello.frag -o ${PROJECT_BINARY_DIR}/hello.frag.spv
	DEPENDS hello.frag)

add_custom_command(OUTPUT hello.vert
	COMMAND ${GLSL_COMPILER} ${PROJECT_SOURCE_DIR}/hello.vert -o ${PROJECT_BINARY_DIR}/hello.vert.spv
	DEPENDS hello.vert)

add_custom_target(HelloTriangle_CompileShaders ALL
	DEPENDS hello.frag hello.vert)

add_executable(HelloTriangle main.cpp)
target_include_directories(HelloTriangle PUBLIC VulkanWrapper ${GLFW_INCLUDE} ${GLM_INCLUDE})
target_link_libraries(HelloTriangle VulkanWrapper ${VULKAN_LIB} ${GLFW_LIB})
add_dependencies(HelloTriangle HelloTriangle_CompileShaders)