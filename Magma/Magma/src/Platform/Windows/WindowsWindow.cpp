#include "mgpch.h"
#include "WindowsWindow.h"

namespace Magma {
	static bool GLFWInitialized = false;

	
	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}


	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}


	WindowsWindow::~WindowsWindow() {
		
	}


	void WindowsWindow::Init(const WindowProps& props) {
		data.title = props.title;
		data.height = props.height;
		data.width = props.width;

		MG_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

		if (!GLFWInitialized) {
			int success = glfwInit();
			MG_CORE_ASSERT(success, "GLFW initialization failed");

			GLFWInitialized = true;
		}

		window = glfwCreateWindow(int(data.width), int(data.height), data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, &data);
		SetVSync(true);
	}


	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(window);
	}


	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(window);

		MG_CORE_INFO("The window get just shutdown : {0}", data.title);
	}


	void WindowsWindow::SetEventCallback(const EventCallback& callback) {}


	void WindowsWindow::SetVSync(bool enabled) {
		if (enabled) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}

		data.VSyncEnabled = enabled;
	}
}