#include "pch.h"
#include "application.h"

#include "frost/events/key_event.h"
#include "frost/renderer/buffer.h"
#include "frost/renderer/renderer.h"

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
		
		vertexArray.reset(VertexArray::create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		BufferLayout layout = {
			{ShaderDataType::Float3, "a_Position"},
			{ShaderDataType::Float4, "a_Color"}
		};

		std::shared_ptr<VertexBuffer> vertexBuffer;
		vertexBuffer.reset(VertexBuffer::create(vertices, sizeof(vertices)));
		vertexBuffer->setLayout(layout);

		unsigned int indices[3] = {0, 1, 2};
		std::shared_ptr<IndexBuffer> indexBuffer;
		indexBuffer.reset(IndexBuffer::create(indices, sizeof(indices) / sizeof(uint32_t)));

		vertexArray->addVertexBuffer(vertexBuffer);
		vertexArray->setIndexBuffer(indexBuffer);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location=0) in vec3 a_Position;
			layout(location=1) in vec4 a_Color;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location=0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = v_Color;
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
			// Clear the screen
			RenderCommand::setClearColor({1.0, 1.0, 0.5, 1.0});
			RenderCommand::clear();
			
			// Render the scene
			Renderer::beginScene();
			shader->bind();
			Renderer::submit(vertexArray);
			Renderer::endScene();

			// Update layers
			for (Layer *layer : layerStack)
				layer->onUpdate();
			
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