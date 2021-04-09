#include <frost.h>
#include <iostream>

class Sandbox : public Frost::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Frost::Application* Frost::CreateApplication()
{
	return new Sandbox();
}