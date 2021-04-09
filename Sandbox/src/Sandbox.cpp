#include <frost.h>
#include <iostream>

class ExampleLayer : public Frost::Layer
{
public:
	ExampleLayer() : Layer("Example") {}
};

class Sandbox : public Frost::Application
{
public:
	Sandbox()
	{
		pushLayer(new ExampleLayer());
		pushOverlay(new Frost::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

Frost::Application *Frost::CreateApplication()
{
	return new Sandbox();
}