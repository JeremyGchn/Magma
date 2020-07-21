#pragma once

#ifdef MG_PLATFORM_WINDOWS

extern Magma::Application* Magma::CreateApplication();

int main(int argc, char** argv) {
	
	Magma::Log::Init();
	MG_CORE_WARNING("Initialized log !");
	int test = 4;
	MG_INFO("Hello! int = {0}", test);

	auto app = Magma::CreateApplication();;
	app->Run();
	delete app;
}

#endif // MG_PLATFORM_WINDOWS
