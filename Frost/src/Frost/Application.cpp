#include "pch.h"
#include "application.h"

#include "events/key_event.h"

namespace Frost
{
	#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		window = std::unique_ptr<Window>(Window::create());
		window->setEventCallback(BIND_EVENT_FN(onEvent));
	}

	Application::~Application()
	{
	}

	void Application::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));
		FS_CORE_TRACE("{0}", e);
	}

	bool Application::onWindowClose(WindowCloseEvent &e)
	{
		running = false;
		return true;
	}

	void Application::Run()
	{
		while(running)
		{
			window->onUpdate();
		}
	}
}