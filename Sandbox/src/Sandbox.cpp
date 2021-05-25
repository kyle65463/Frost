#include <frost.h>
#include <iostream>

#include "imgui.h"

class ExampleLayer : public Frost::Layer
{
public:
	ExampleLayer() : Layer("Example"), camera(-1.0f, 1.0f, -1.0f, 1.0f)
	{
		vertexArray.reset(Frost::VertexArray::create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f};

		Frost::BufferLayout layout = {
			{Frost::ShaderDataType::Float3, "a_Position"},
			{Frost::ShaderDataType::Float4, "a_Color"}};

		std::shared_ptr<Frost::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Frost::VertexBuffer::create(vertices, sizeof(vertices)));
		vertexBuffer->setLayout(layout);

		unsigned int indices[3] = {0, 1, 2};
		std::shared_ptr<Frost::IndexBuffer> indexBuffer;
		indexBuffer.reset(Frost::IndexBuffer::create(indices, sizeof(indices) / sizeof(uint32_t)));

		vertexArray->addVertexBuffer(vertexBuffer);
		vertexArray->setIndexBuffer(indexBuffer);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location=0) in vec3 a_Position;
			layout(location=1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
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

		shader.reset(new Frost::Shader(vertexSrc, fragmentSrc));
	}

	void onUpdate(Frost::TimeStep dt) override
	{
		FS_TRACE("{0}", dt.getSeconds());

		if(Frost::Input::isKeyPressed(FS_KEY_A))
			cameraPosition.x -= cameraSpeed;

		if(Frost::Input::isKeyPressed(FS_KEY_D))
			cameraPosition.x += cameraSpeed;

		if(Frost::Input::isKeyPressed(FS_KEY_W))
			cameraPosition.y += cameraSpeed;

		if(Frost::Input::isKeyPressed(FS_KEY_S))
			cameraPosition.y -= cameraSpeed;

		if(Frost::Input::isKeyPressed(FS_KEY_LEFT))
			cameraRotation += cameraSpeed * 50;
		
		if(Frost::Input::isKeyPressed(FS_KEY_RIGHT))
			cameraRotation -= cameraSpeed * 50;

		// Clear the screen
		Frost::RenderCommand::setClearColor({1.0, 1.0, 0.5, 1.0});
		Frost::RenderCommand::clear();

		camera.setPosition(cameraPosition);
		camera.setRotation(cameraRotation);

		// Render the scene
		Frost::Renderer::beginScene(camera);
		Frost::Renderer::submit(shader, vertexArray);

		Frost::Renderer::endScene();
	}

	void onImGuiRender() override
	{
	}

	void onEvent(Frost::Event &event) override
	{
		Frost::EventDispatcher dispatcher(event);
		dispatcher.dispatch<Frost::KeyPressedEvent>(FS_BIND_EVENT_FN(ExampleLayer::onKeyPressedEvent));
	}

	bool onKeyPressedEvent(Frost::KeyPressedEvent& event)
	{
		return false;
	}

private:
	std::shared_ptr<Frost::Shader> shader;
	std::shared_ptr<Frost::VertexArray> vertexArray;
	Frost::OrthographicCamera camera;
	glm::vec3 cameraPosition = {0.0f, 0.0f, 0.0f};
	float cameraRotation = 0.0f;
	float cameraSpeed = 0.03f;
};

class Sandbox : public Frost::Application
{
public:
	Sandbox()
	{
		pushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	}
};

Frost::Application *Frost::CreateApplication()
{
	return new Sandbox();
}