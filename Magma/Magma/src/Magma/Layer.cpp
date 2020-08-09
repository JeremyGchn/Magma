#include "mgpch.h"
#include "Layer.h"

namespace Magma {
	
	Layer::Layer() {
	
	}


	Layer::~Layer() {

	}


	void Layer::Update() {
		if (IsEnabled()) {
			OnUpdate();
		}
	}


	void Layer::Enable() {
		if (!IsEnabled()) {
			enabled = true;
			OnEnable();
		}
	}
	
	
	void Layer::Disable() {
		if (IsEnabled()) {
			enabled = false;
			OnDisable();
		}
	}


	void Layer::Attach() {
		OnAttach();
	}


	void Layer::Detach() {
		OnDetach();
	}


	void Layer::ReceiveEvent(EventSystem::Event& event) {
		if (IsEnabled()) {
			OnEventReceived(event);
		}
	}
}