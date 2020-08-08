#pragma once
#include "Magma/Core.h"
#include "Event.h"

namespace Magma::EventSystem {

	class MAGMA_API MouseButtonPressedEvent : public Event {

	public:
		MouseButtonPressedEvent(int button) : Event(), button(button) { }
		~MouseButtonPressedEvent() { }

		EVENT_TYPE(MouseButtonPressed)
		EVENT_TO_STRING("Button : " << button);
		int button;
	};

	class MAGMA_API MouseButtonReleasedEvent : public Event {

	public:
		MouseButtonReleasedEvent(int button) : Event(), button(button) {}
		~MouseButtonReleasedEvent() {}
		
		EVENT_TYPE(MouseButtonReleased)
		EVENT_TO_STRING("Button :" << button);
	private:
		int button;
	};

	class MAGMA_API MouseCursorEvent : public Event {

	public:
		MouseCursorEvent(float xPos, float yPos) : Event() ,xPos(xPos), yPos(yPos) {}
		~MouseCursorEvent() {}

		EVENT_TYPE(MouseCursor)
		EVENT_TO_STRING("xPos : " << xPos << " yPos : " << yPos);
	private:
		float xPos; 
		float yPos;
	};

	class MAGMA_API MouseScrollEvent : public Event {

	public:
		MouseScrollEvent(float xDelta, float yDelta) : Event(), xDelta(xDelta), yDelta(yDelta) {}
		~MouseScrollEvent() {}

		EVENT_TYPE(MouseScrolled)
		EVENT_TO_STRING("xDelta : " << xDelta << " yDelta : " << yDelta);
	private:
		float xDelta;
		float yDelta;
	};
}
