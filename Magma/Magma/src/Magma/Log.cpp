#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Magma {

	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;

	void Log::Init() {
		//set the patter of display a message as [time] name of the caller then log
		spdlog::set_pattern("%^[%T] %n: %v%$");

		//create the core logger
		coreLogger = spdlog::stdout_color_mt("MAGMA");
		coreLogger->set_level(spdlog::level::trace);

		//create the client logger, the one use by the application
		clientLogger = spdlog::stdout_color_mt("APP");
		clientLogger->set_level(spdlog::level::trace);
	}
}