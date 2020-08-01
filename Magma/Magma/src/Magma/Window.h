#pragma once
#include "mgpch.h"

#include "Magma/Core.h"
#include "Magma/EventSystem/Event.h"

namespace Magma {
	
	struct WindowProps {
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const std::string& title = "Magma Engine", unsigned int width = 1280, unsigned int height = 720) 
			:title(title), width(width), height(height) {

		}
	};

	//desktop system based on a window interface base class
	class MAGMA_API Window {
	
	public:
		using EventCallback = std::function<void(EventSystem::Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallback& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSyncEnabled() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}
