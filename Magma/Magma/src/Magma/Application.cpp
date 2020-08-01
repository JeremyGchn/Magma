#include "mgpch.h"
#include "Application.h"

namespace Magma {
	
	Application::Application() {
		window = std::unique_ptr<Window>(Window::Create());
	}


	Application::~Application() {
	
	}
	

	void Application::Run() {
		
		while (running) {
			window->OnUpdate();
		}
	}
}