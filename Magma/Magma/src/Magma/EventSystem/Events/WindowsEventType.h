#pragma once
#include "Magma/Core.h"
#include "Magma/EventSystem/Events/Event.h"

namespace Magma::EventSystem {

	class MAGMA_API WindowResizedEvent : public Event {

	public:
		WindowResizedEvent(unsigned int width, unsigned int height) : Event(), width(width), height(height) {

		}
		~WindowResizedEvent() {}


		EVENT_TYPE(WindowResized)
		EVENT_TO_STRING("Width: " << width << " Height: " << height);
	private:
		unsigned int width;
		unsigned int height;
	};


	class MAGMA_API WindowClosedEvent : public Event {

	public:
		WindowClosedEvent() : Event() { }
		~WindowClosedEvent(){ }
		
		EVENT_TYPE(WindowClosed)
	};



}
