#pragma once

#ifdef FS_PLATFORM_WINDOWS

extern Frost::Application* Frost::CreateApplication();

int main(int argc, char** argv) {

	Frost::Log::Init();
	FS_CORE_WARN("WARNING");
	FS_INFO("INFOO");

	auto app = Frost::CreateApplication();
	app->Run();
	delete app;
}

#endif