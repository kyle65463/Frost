#include "pch.h"
#include "application.h"
#include <GLFW/glfw3.h>

namespace Frost
{

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		// Init glfw
		if (!glfwInit())
		{
			std::cout << "ERROR::Failed to init glfw" << std::endl;
			return;
		}

		// Set GL version
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		// Create a window
		GLFWwindow *window = glfwCreateWindow(800, 600, "Test OpenGL", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "ERROR::Failed to create the window" << std::endl;
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(window);

		// Render loop
		while (!glfwWindowShouldClose(window))
		{
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwTerminate();
	}
}