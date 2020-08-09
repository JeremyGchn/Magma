#pragma once
#include "Magma/Core.h"

#include "EventSystem/Events/Event.h"

namespace Magma {

	class MAGMA_API Layer {

	public:
		Layer();
		virtual ~Layer();

		void Update();
		void Enable();
		void Disable();
		void Attach();
		void Detach();
		void ReceiveEvent(EventSystem::Event& event);

		inline bool IsEnabled() const { return enabled; }
	
	protected:
		virtual void OnUpdate() { }
		virtual void OnEnable() { }
		virtual void OnDisable(){ }
		virtual void OnAttach() { }
		virtual void OnDetach() { }
		virtual void OnEventReceived(EventSystem::Event& event) { }

	private:
		bool enabled;
	};

}
