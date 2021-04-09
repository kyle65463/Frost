#pragma once

#include "core.h"
#include "events/event.h"
#include "events/application_event.h"
#include "window.h"

namespace Frost
{
	class FROST_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void onEvent(Event &e);

	private:
		bool onWindowClose(WindowCloseEvent &e);
		std::unique_ptr<Window> window;
		bool running = true;
	};

	Application *CreateApplication();
}
