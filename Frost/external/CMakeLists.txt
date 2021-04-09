add_subdirectory(glfw)
add_subdirectory(spdlog)

add_library(external_libs INTERFACE)

target_link_libraries(external_libs 
    INTERFACE 
    spdlog
    glfw
)

target_include_directories(external_libs
    INTERFACE
    glfw/include
    spdlog/include
)