#pragma once

#include "Core.h"

namespace Magma {
	
	class MAGMA_API Application {
	
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//to be defined in client
	Application* CreateApplication();
}