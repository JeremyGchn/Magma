#include "mgpch.h"
#include "Event.h"

namespace Magma::EventSystem {

	Event::Event() : handled(false) {

	}


	Event::~Event() {}


	const std::string Event::ToString() const {
		std::stringstream ss;
		ss << GetEventType();
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
