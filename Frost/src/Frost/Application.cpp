#include "pch.h"
#include "application.h"

#include "frost/core/timestep.h"
#include "frost/events/key_event.h"
#include "glfw/glfw3.h"

namespace Frost
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application *Application::instance = NULL;
	Application::Application()
	{
		FS_CORE_ASSERT(!instance, "Application already exists");
		instance = this;
		window = std::unique_ptr<Window>(Window::create());
		window->setEventCallback(BIND_EVENT_FN(onEvent));

		imGuiLayer = new ImGuiLayer();
		pushOverlay(imGuiLayer);

		lastFrameTime = glfwGetTime();
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
			(*it)->onEvent(e);
			if (e.handled)
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
			float time = glfwGetTime();
			TimeStep timeStep = TimeStep(time - lastFrameTime);
			lastFrameTime = time;

			// Update layers
			for (Layer *layer : layerStack)
				layer->onUpdate(timeStep);

			// Update imgui layers
			imGuiLayer->begin();
			for (Layer *layer : layerStack)
				layer->onImGuiRender();
			imGuiLayer->end();

			// Update the window
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