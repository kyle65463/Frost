#include "pch.h"
#include "windows_input.h"
#include "frost/application.h"
#include "GLFW/glfw3.h"

namespace Frost
{
    Input* Input::instance = new WindowsInput();

    bool WindowsInput::isKeyPressedImpl(int keycode)
    {
        GLFWwindow *window = static_cast<GLFWwindow *>(Application::get().getWindow().getNativeWindow());
        int state = glfwGetKey(window, keycode);

        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::isMouseButtonPressedImpl(int button)
    {
        GLFWwindow *window = static_cast<GLFWwindow *>(Application::get().getWindow().getNativeWindow());
        int state = glfwGetMouseButton(window, button);

        return state == GLFW_PRESS;
    }

    std::pair<double, double> WindowsInput::getMousePosImpl()
    {
    GLFWwindow *window = static_cast<GLFWwindow *>(Application::get().getWindow().getNativeWindow());
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);

        return {xPos, yPos};
    }

    double WindowsInput::getMousePosXImpl()
    {
        auto[xPos, yPos] = getMousePosImpl();
        return xPos;
    }

    double WindowsInput::getMousePosYImpl()
    {
        auto[xPos, yPos] = getMousePosImpl();
        return yPos;
    }
}