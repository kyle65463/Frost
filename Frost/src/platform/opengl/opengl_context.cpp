#include "pch.h"

#include "opengl_context.h"
#include <glad/glad.h>
#include "GLFW/glfw3.h"

namespace Frost
{
    OpenGLContext::OpenGLContext(GLFWwindow *window) : window(window)
    {
        FS_CORE_ASSERT(window, "Window is null!");
    }

    void OpenGLContext::init()
    {
        glfwMakeContextCurrent(window);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        FS_CORE_ASSERT(status, "Failed to initialize glad");
    }

    void OpenGLContext::swapBuffers()
    {
        glfwSwapBuffers(window);
    }
}