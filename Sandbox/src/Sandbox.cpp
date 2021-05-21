#include <frost.h>
#include <iostream>

class ExampleLayer : public Frost::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void onUpdate() override
	{
		if (Frost::Input::isKeyPressed(FS_KEY_TAB))
			FS_INFO("TAB is pressed!");
	}

	void onEvent(Frost::Event& event) override
	{
		if (event.getEventType() == Frost::EventType::KeyPressed)
		{
			Frost::KeyPressedEvent& e = (Frost::KeyPressedEvent&)event;
			FS_TRACE("{0}",(char)(e.getKeyCode()));
		}
	}
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