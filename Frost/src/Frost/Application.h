#pragma once

#include "frost/core.h"
#include "frost/events/event.h"
#include "frost/events/application_event.h"
#include "frost/window.h"
#include "frost/layer_stack.h"
#include "frost/imgui/imgui_layer.h"
#include "frost/renderer/shader.h"
#include "frost/renderer/vertex_array.h"
#include "frost/renderer/orthographic_camera.h"

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
		std::shared_ptr<Shader>  shader;
		ImGuiLayer* imGuiLayer;
		bool running = true;
		LayerStack layerStack;
		static Application *instance;
		std::shared_ptr<VertexArray> vertexArray;
		OrthographicCamera camera;
	};

	Application *CreateApplication();
}
