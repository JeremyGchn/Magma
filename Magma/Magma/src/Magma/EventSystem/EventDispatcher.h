#pragma once
#include "Magma/Core.h"
#include "Magma/IDisplayabe/IDisplayable.h"
#include "Magma/EventSystem/Events/Event.h"

namespace Magma::EventSystem {

	class MAGMA_API EventDispatcher : public IDisplayable{
		
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : event(event){ }
		~EventDispatcher() { }

		template<typename T>
		bool DispatchEvent(EventFn<T> func) {
			if (!event.handled && event.GetEventType() == T::GetStaticType()) {
				if (func(*(T*) &event)) {
					return event.Use();
				}
			}
			return false;
		}

		// Inherited via IDisplayable
		virtual const std::string ToString() const override { return "dispatcher"; }

	private: 
		Event& event;
	};

}
