#include "mgpch.h"
#include "Event.h"

namespace Magma::EventSystem {

	Event::Event(const EventType type) : eventType(type), handled(false) {

	}


	Event::~Event() {}


	const std::string Event::ToString() const {
		std::stringstream ss;
		ss << eventType;
		return ss.str();
	}


	bool Event::Use() { 
		if (!handled) {
			handled = true;
			return true;
		}
		return false;
	}
}
