#include "pch.h"
#include "application.h"

#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "frost/events/key_event.h"
#include "frost/input.h"

namespace Frost
{
	#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	
	Application* Application::instance = NULL;
	Application::Application()
	{
		FS_CORE_ASSERT(!instance, "Application already exists");
		instance = this;
		window = std::unique_ptr<Window>(Window::create());
		window->setEventCallback(BIND_EVENT_FN(onEvent));

		imGuiLayer = new ImGuiLayer();
		pushOverlay(imGuiLayer);

		glGenVertexArrays(1, &vertexArray);
		glBindVertexArray(vertexArray);

		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		vertexBuffer.reset(VertexBuffer::create(vertices, sizeof(vertices)));

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		unsigned int indices[3] = { 0, 1, 2 };
		indexBuffer.reset(IndexBuffer::create(indices, sizeof(indices) / sizeof(uint32_t)));

		std::string vertexSrc = R"(
			#version 330 core

			layout(location=0) in vec3 a_Position;

			void main()
			{
				gl_Position = vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location=0) out vec4 color;

			void main()
			{
				color = vec4(0.8, 0.2, 0.3, 1.0);
			}
		)";
		
		shader = new Shader(vertexSrc, fragmentSrc);
	}

	Application::~Application()
	{
	}

	void Application::onEvent(Event &e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));
		
		for (auto it = layerStack.end() - 1; it >= layerStack.begin(); it--)
		{
			// it--;
			(*it)->onEvent(e);
			if(e.handled)
				break;
		}
	}

	bool Application::onWindowClose(WindowCloseEvent &e)
	{
		running = false;
		return true;
	}

	void Application::Run()
	{
		while (running)
		{
			glClearColor(1.0, 1.0, 0.5, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			shader->bind();
			glBindVertexArray(vertexArray);
			glDrawElements(GL_TRIANGLES, indexBuffer->getCount(), GL_UNSIGNED_INT, nullptr);
			
			for (Layer *layer : layerStack)
				layer->onUpdate();

			imGuiLayer->begin();
			for (Layer *layer : layerStack)
				layer->onImGuiRender();
			imGuiLayer->end();

			window->onUpdate();
		}
	}


	void Application::pushLayer(Layer *layer)
	{
		layerStack.pushLayer(layer);
		layer->onAttach();
	}

	void Application::pushOverlay(Layer *overlay)
	{
		layerStack.pushOverlay(overlay);
		overlay->onAttach();
	}
}