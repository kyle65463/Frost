file(GLOB SOURCES *.cpp *.h)
add_library(imgui ${SOURCES})
target_link_libraries(imgui PUBLIC imm32)

if(WIN32)
    target_compile_options(imgui PRIVATE -DPLATFORM_WINDOWS)
endif(WIN32)