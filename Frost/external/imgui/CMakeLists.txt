file(GLOB SOURCES *.cpp *.h)
add_library(imgui ${SOURCES})
target_link_libraries(imgui PUBLIC imm32)