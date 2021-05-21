#pragma once

#include "frost/window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Frost
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps &props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		// Getters
		inline unsigned int getWidth() const override { return data.width; };
		inline unsigned int getHeight() const override { return data.height; };
		bool isVSync() const override { return data.vSync; }

		inline void* getNativeWindow() const { return window; }

		// Setters
		inline void setEventCallback(const EventCallbackFn &callback) override { data.eventCallback = callback; };
		void setVSync(bool enabled) override;

	private:
		virtual void init(const WindowProps &props);
		virtual void shutdown();

		GLFWwindow *window;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData data;
	};
}