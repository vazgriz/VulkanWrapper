cmake_minimum_required(VERSION 3.9)
project(Vulkan_Tutorial)

set(TINYOBJ_INCLUDE)

add_custom_command(OUTPUT shader.frag
	COMMAND ${GLSL_COMPILER} ${PROJECT_SOURCE_DIR}/shader.frag -o ${PROJECT_BINARY_DIR}/shader.frag.spv
	DEPENDS shader.frag)

add_custom_command(OUTPUT shader.vert
	COMMAND ${GLSL_COMPILER} ${PROJECT_SOURCE_DIR}/shader.vert -o ${PROJECT_BINARY_DIR}/shader.vert.spv
	DEPENDS shader.vert)

add_custom_target(Vulkan_Tutorial_CompileShaders ALL
	DEPENDS shader.frag shader.vert)

add_custom_command(OUTPUT chalet.jpg
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/chalet.jpg ${PROJECT_BINARY_DIR}/chalet.jpg
	DEPENDS chalet.jpg)

add_custom_command(OUTPUT chalet.obj
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/chalet.obj ${PROJECT_BINARY_DIR}/chalet.obj
	DEPENDS chalet.obj)

add_custom_target(Vulkan_Tutorial_Resources ALL
	DEPENDS chalet.jpg chalet.obj)

add_executable(Vulkan_Tutorial main.cpp)
target_include_directories(Vulkan_Tutorial PUBLIC VulkanWrapper ${GLFW_INCLUDE} ${GLM_INCLUDE} ${TINYOBJ_INCLUDE})
target_link_libraries(Vulkan_Tutorial VulkanWrapper ${VULKAN_LIB} ${GLFW_LIB})
add_dependencies(Vulkan_Tutorial Vulkan_Tutorial_CompileShaders Vulkan_Tutorial_Resources)