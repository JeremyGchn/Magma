#pragma once

#include "Core.h"
#include <Magma\Window.h>

#include "Magma/EventSystem/Events/EventTypes.h"

namespace Magma {

	class MAGMA_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(EventSystem::Event& e);

	private:
		bool OnWindowClosed(EventSystem::WindowClosedEvent& e);

	private:
		std::unique_ptr<Window> window;
		bool running = true;
	};

	//to be defined in client
	Application* CreateApplication();
}