#include "mgpch.h"
#include "WindowsWindow.h"

#include "Magma/EventSystem/Events/EventTypes.h"

#include <glad/glad.h>

namespace Magma {
	static bool GLFWInitialized = false;


	static Magma::WindowsWindow::WindowData& GetData(GLFWwindow* window) {
		return *static_cast<Magma::WindowsWindow::WindowData*>(glfwGetWindowUserPointer(window));
	}


	static void GLFWErrorCallback(int error, const char* description) {
		MG_CORE_ERROR("GLFW Error ({0}) : {1}", error, description);
	}

	
	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}


	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}


	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}


	void WindowsWindow::Init(const WindowProps& props) {
		data.title = props.title;
		data.height = props.height;
		data.width = props.width;

		MG_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

		if (!GLFWInitialized) {
			int success = glfwInit();
			MG_CORE_ASSERT(success, "GLFW initialization failed");
			glfwSetErrorCallback(GLFWErrorCallback);
			GLFWInitialized = true;
		}

		window = glfwCreateWindow(int(data.width), int(data.height), data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
		
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MG_CORE_ASSERT(status, "Failed to initialize Glad !");

		glfwSetWindowUserPointer(window, &data);
		SetVSync(true);

		//set GLFW callbacks
		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = GetData(window);
			data.width = unsigned int(width);
			data.height = unsigned int(height);
			
			EventSystem::WindowResizedEvent event(data.width, data.height);
			data.eventCallback(event);
		});

		glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {
			WindowData& data = GetData(window);
			EventSystem::WindowClosedEvent event;
			data.eventCallback(event);
		});

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = GetData(window);
			switch (action) {
				case GLFW_PRESS: {
					EventSystem::KeyPressedEvent event(key);
					data.eventCallback(event);
				}
				case GLFW_RELEASE: {
					EventSystem::KeyReleasedEvent event(key);
					data.eventCallback(event);
				}
				case GLFW_REPEAT: {
					EventSystem::KeyPressedEvent event(key, 1);
					data.eventCallback(event);
				}
			}
		});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = GetData(window);
			switch (action) {
				case GLFW_PRESS: {
						EventSystem::MouseButtonPressedEvent event(button);
						data.eventCallback(event);
				}
				case GLFW_RELEASE: {
						EventSystem::MouseButtonReleasedEvent event(button);
						data.eventCallback(event);
				}
			}
		});

		glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset) {
			WindowData& data = GetData(window);
			EventSystem::MouseScrollEvent event((float)xOffset, (float)yOffset);
			data.eventCallback(event);
		});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPos, double yPos) {
			WindowData& data = GetData(window);
			EventSystem::MouseCursorEvent event((float)xPos, (float)yPos);
			data.eventCallback(event);
		});
	}


	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(window);
	}


	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(window);

		MG_CORE_INFO("The window just get shutdown : {0}", data.title);
	}


	void WindowsWindow::SetEventCallback(const EventCallback& callback) {
		data.eventCallback = callback;
	}


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