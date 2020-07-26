#pragma once
#include "Magma/Core.h"
#include "Magma/IDisplayabe/IDisplayable.h"
#include "Magma/EnumClass.h"

namespace Magma::EventSystem {

	MAGMA_ENUM(EventType, None, KeyPressed, KeyReleased, WindowResized, WindowLostFocus, WindowGainFocus)

	class MAGMA_API Event : public IDisplayable {
	
	public:
		Event(const EventType type);
		~Event();

		// Inherited via IDisplayable
		virtual const std::string ToString() const override;

		bool Use();

		inline bool IsHandled() const { return handled; }

	private: 
 		const EventType eventType;
		bool handled;
	};

}
