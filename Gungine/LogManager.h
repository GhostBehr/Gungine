#pragma once

#include <fstream>
#include <string>

namespace gungine {
	class LogManager {
	public:
		enum LogSeverity {	// LOG_ prefix to prevent redefinition errors
			LOG_INFO,
			LOG_TRACE,
			LOG_WARNING,
			LOG_ERROR
		};

		~LogManager();

		static LogManager* get() {
			if (instance == NULL) {
				instance = new LogManager();
			}
			return instance;
		}

		void setLogFile(std::string fileName);

		void setMinSeverity(LogSeverity severity);
		LogSeverity getMinSeverity();

		void log(LogSeverity severity, std::string msg);

	private:
		static LogManager* instance;
		LogSeverity minSeverity;

		std::ofstream* oStream;

		LogManager();
		LogManager(const LogManager& lm) { }

		void operator=(const LogManager& lm) { }

		void closeFile();


	};
}