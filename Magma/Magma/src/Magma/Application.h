#pragma once

#include "Core.h"
#include <Magma\Window.h>

namespace Magma {

	class MAGMA_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> window;
		bool running = true;
	};

	//to be defined in client
	Application* CreateApplication();
}