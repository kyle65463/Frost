#pragma once

#include "Core.h"

namespace Frost {
	class FROST_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
