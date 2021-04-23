add_library(glad src/glad.c include/glad/glad.h include/KHR/khrplatform.h)

target_link_libraries(glad PUBLIC ${OPENGL_LIBRARIES})

target_include_directories(glad
    PUBLIC
    include
)