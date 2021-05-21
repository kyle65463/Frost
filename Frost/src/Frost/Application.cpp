#include "pch.h"
#include "application.h"

#include "GLFW/glfw3.h"
#include "events/key_event.h"

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
	}

	Application::~Application()
	{
	}

	void Application::onEvent(Event &e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));
		FS_CORE_TRACE("{0}", e);

		for (auto it = layerStack.end() - 1; it != layerStack.begin(); it--)
		{
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
			for (Layer *layer : layerStack)
			{
				layer->onUpdate();
			}
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