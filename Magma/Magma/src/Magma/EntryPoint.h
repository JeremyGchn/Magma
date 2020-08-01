#pragma once

#ifdef MG_PLATFORM_WINDOWS

extern Magma::Application* Magma::CreateApplication();

int main(int argc, char** argv) {
	
	Magma::Log::Init();
	MG_CORE_INFO("Log system initialized !");

	auto app = Magma::CreateApplication();;
	app->Run();
	delete app;
}

#endif // MG_PLATFORM_WINDOWS
