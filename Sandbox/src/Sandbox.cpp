#include <frost.h>
#include <iostream>

class ExampleLayer : public Frost::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void onUpdate() override
	{
		FS_INFO("Update example layer");
	}

	void onEvent(Frost::Event &e) override
	{
		FS_TRACE("{0}", e);
	}
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