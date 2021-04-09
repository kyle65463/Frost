add_subdirectory(glfw)
add_subdirectory(spdlog)
add_subdirectory(glad)
add_subdirectory(imgui)

add_library(external_libs INTERFACE)

target_link_libraries(external_libs 
    INTERFACE 
    spdlog
    glfw
    glad
    imgui
)

target_include_directories(external_libs
    INTERFACE
    glfw/include
    spdlog/include
    glad/include
    imgui
)