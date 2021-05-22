cmake_minimum_required(VERSION 3.20)

project(Frost)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

add_library(${PROJECT_NAME} SHARED ${SOURCES} 
    external/imgui/backends/imgui_impl_glfw.h 
    external/imgui/backends/imgui_impl_glfw.cpp 
    external/imgui/backends/imgui_impl_opengl3.h
    external/imgui/backends/imgui_impl_opengl3.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC external_libs)
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_precompile_headers(${PROJECT_NAME} PUBLIC src/pch.h)

if(WIN32)
    target_compile_options(${PROJECT_NAME} PUBLIC -DFS_PLATFORM_WINDOWS)
    target_compile_options(${PROJECT_NAME} PUBLIC -DFS_BUILD_DLL)
    target_link_libraries(${PROJECT_NAME} PUBLIC opengl32)
endif(WIN32)

if(APPLE)
    target_compile_options(${PROJECT_NAME} PUBLIC -DFS_PLATFORM_MACOSX)
endif(APPLE)