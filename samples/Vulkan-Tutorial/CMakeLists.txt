cmake_minimum_required(VERSION 3.9)
project(Vulkan_Tutorial)

set(TINYOBJ_INCLUDE)

set(SHADER_SOURCES
    "${PROJECT_SOURCE_DIR}/shader.vert" ;
    "${PROJECT_SOURCE_DIR}/shader.frag" ;
)
set(SPIRV_BINARY_FILES)

foreach(SHADER_SOURCE ${SHADER_SOURCES})
    get_filename_component(FILE_NAME ${SHADER_SOURCE} NAME)
    set(SPIRV "${PROJECT_BINARY_DIR}/shaders/${FILE_NAME}.spv")
    add_custom_command(
        OUTPUT ${SPIRV}
        COMMAND ${GLSL_COMPILER} ${SHADER_SOURCE} -o ${SPIRV}
        DEPENDS ${SHADER_SOURCE})
    list(APPEND SPIRV_BINARY_FILES ${SPIRV})
endforeach(SHADER_SOURCE)

add_custom_target(
    Vulkan_Tutorial_CompileShaders 
    DEPENDS ${SPIRV_BINARY_FILES}
)

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