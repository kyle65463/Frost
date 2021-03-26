#pragma once

#ifdef FS_PLATFORM_WINDOWS

extern Frost::Application* Frost::CreateApplication();

int main(int argc, char** argv) {
	printf("hio");
	auto app = Frost::CreateApplication();
	app->Run();
	delete app;
}

#endif