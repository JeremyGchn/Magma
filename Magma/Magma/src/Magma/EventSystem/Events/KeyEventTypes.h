#pragma once
#include "Magma/Core.h"
#include "Event.h"

namespace Magma::EventSystem {

	class MAGMA_API KeyPressedEvent : public Event {
	
	public:
		KeyPressedEvent(int keyCode, int repeat = 0) : Event(), keyCode(keyCode), repeat(repeat) {

		}

		~KeyPressedEvent() { }

		EVENT_TYPE(KeyPressed)
		EVENT_TO_STRING("KeyCode : " << keyCode << "RepeatCounter : " << repeat);
	private:
		int keyCode;
		int repeat;
	};

	class MAGMA_API KeyReleasedEvent : public Event {

	public:
		KeyReleasedEvent(int keyCode) : Event(), keyCode(keyCode) {

		}

		~KeyReleasedEvent() {}
		
		EVENT_TYPE(KeyReleased)
		EVENT_TO_STRING("KeyCode : " << keyCode);
	private:
		int keyCode;
	};
}
