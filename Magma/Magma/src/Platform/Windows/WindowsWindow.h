#pragma once
#include "Magma/Window.h"

#include <GLFW/glfw3.h>

namespace Magma {

	class MAGMA_API WindowsWindow : public Window {

	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		// Inherited via Window
		virtual void OnUpdate() override;

		virtual unsigned int GetWidth() const override { return data.width; }
		virtual unsigned int GetHeight() const override { return data.height; }

		virtual void SetEventCallback(const EventCallback& callback) override;
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSyncEnabled() const override { return data.VSyncEnabled; }

	public: 
		struct WindowData {
			std::string title;
			unsigned int width;
			unsigned int height;
			bool VSyncEnabled;

			EventCallback eventCallback;
		};

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();		

	private:
		GLFWwindow* window;
		WindowData data;
	};
}
