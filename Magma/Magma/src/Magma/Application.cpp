#include "mgpch.h"
#include "Application.h"

#include "Magma/EventSystem/EventDispatcher.h"
#include "Magma/Layer.h"

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

			for (Layer* layer : layerStack) {
				layer->Update();
			}
		}
	}


	void Application::OnEvent(EventSystem::Event& e) {
		MG_CORE_TRACE("Event {0}", e);

		EventSystem::EventDispatcher dispatcher(e);
		dispatcher.DispatchEvent<EventSystem::WindowClosedEvent>(BIND_FN(OnWindowClosed));

		for (auto it = layerStack.r_begin(); it != layerStack.r_end(); it++) {
			(*it)->ReceiveEvent(e);
			
			if (e.IsHandled()) {
				break;
			}
		}
	}


	void Application::PushLayer(Layer* layer) {
		layerStack.PushLayer(layer);
	}


	void Application::PushOverlay(Layer* overlay) {
		layerStack.PushOverlay(overlay);
	}


	bool Application::OnWindowClosed(EventSystem::WindowClosedEvent& e) {
		running = false;
		return true;
	}
}