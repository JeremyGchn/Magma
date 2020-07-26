#pragma once
#include "Magma/Core.h"
#include "Magma/IDisplayabe/IDisplayable.h"
#include "Magma/EventSystem/Event.h"

namespace Magma::EventSystem {

	class MAGMA_API EventDispatcher : public IDisplayable{
	
	public:
		EventDispatcher();
		~EventDispatcher();

		void DispatchEvent(Event& event);

		// Inherited via IDisplayable
		virtual const std::string ToString() const override;
	};

}
