#pragma once

#include "core.h"
#include "events/event.h"
#include "events/application_event.h"
#include "window.h"
#include "layer_stack.h"

namespace Frost
{
	class FROST_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void onEvent(Event &e);
		void pushLayer(Layer *layer);
		void pushOverlay(Layer *overlay);

		// Getters
		inline static Application &get() { return *instance; }
		inline Window &getWindow() { return *window; }

	private:
		bool onWindowClose(WindowCloseEvent &e);
		std::unique_ptr<Window> window;
		bool running = true;
		LayerStack layerStack;
		static Application *instance;
	};

	Application *CreateApplication();
}
