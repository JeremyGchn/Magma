#include "mgpch.h"
#include "Application.h"

#include "Magma/EventSystem/EventDispatcher.h"

namespace Magma {

#define BIND_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	
	Application::Application() {
		window = std::unique_ptr<Window>(Window::Create());
		window->SetEventCallback(BIND_FN(OnEvent));
	}


	Application::~Application() {
	
	}
	

	void Application::Run() {
		
		while (running) {
			window->OnUpdate();
		}
	}


	void Application::OnEvent(EventSystem::Event& e) {
		MG_CORE_INFO("Event {0}", e);

		EventSystem::EventDispatcher dispatcher(e);
		dispatcher.DispatchEvent<EventSystem::WindowClosedEvent>(BIND_FN(OnWindowClosed));
	}


	bool Application::OnWindowClosed(EventSystem::WindowClosedEvent& e) {
		running = false;
		return true;
	}
}