#include "mgpch.h"
#include "EventDispatcher.h"

namespace  Magma::EventSystem {

	EventDispatcher::EventDispatcher() {}

	EventDispatcher::~EventDispatcher() {

	}

	void EventDispatcher::DispatchEvent(Event& event) {
		if (!event.IsHandled()) {
			event.Use();
		}
	}

	const std::string EventDispatcher::ToString() const {
		return "dispatcher";
	}
}
