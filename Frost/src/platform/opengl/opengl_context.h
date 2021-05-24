#pragma once

#include "frost/renderer/graphics_context.h"

struct GLFWwindow;

namespace Frost
{
    class OpenGLContext : public GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow* window);
        ~OpenGLContext();

        void init() override;
        void swapBuffers() override;

     private:
        GLFWwindow *window;
    };
}