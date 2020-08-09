#pragma once

#include "Core.h"
#include <Magma\Window.h>

#include "Magma/EventSystem/Events/EventTypes.h"
#include "Magma/LayerStack.h"

namespace Magma {

	class MAGMA_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(EventSystem::Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClosed(EventSystem::WindowClosedEvent& e);

	private:
		std::unique_ptr<Window> window;
		LayerStack layerStack;
		bool running = true;
	};

	//to be defined in client
	Application* CreateApplication();
}