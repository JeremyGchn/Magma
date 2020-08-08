#pragma once
#include "Magma/Core.h"
#include "Magma/IDisplayabe/IDisplayable.h"
#include "Magma/EnumClass.h"

namespace Magma::EventSystem {

	MAGMA_ENUM(
		EventType, 
		
		None, 
		KeyPressed, 
		KeyReleased, 
		MouseButtonPressed, 
		MouseButtonReleased, 
		MouseScrolled, 
		MouseCursor, 
		WindowResized, 
		WindowLostFocus, 
		WindowGainFocus, 
		WindowClosed
	)

	#define EVENT_TYPE(x)	static EventType GetStaticType() { return EventType::##x; }					\
							virtual EventType GetEventType() const override { return GetStaticType(); }	\

	#define EVENT_TO_STRING(...) 	virtual const std::string ToString() const override {	\
		std::stringstream ss;																\
		ss << Event::ToString() << __VA_ARGS__;												\
		return ss.str();																	\
	}																						\

	class MAGMA_API Event : public IDisplayable {
		friend class EventDispatcher;

	public:
		Event();
		~Event();

		// Inherited via IDisplayable
		virtual const std::string ToString() const override;

		virtual EventType GetEventType() const = 0;
		inline bool IsHandled() const { return handled; }
		
		bool Use();
	private: 
		bool handled;
	};

}
