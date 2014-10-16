#include "LogManager.h"
using namespace gungine;

LogManager* LogManager::instance = NULL;

LogManager::LogManager() {
	oStream = NULL;
	minSeverity = LogSeverity::LOG_ERROR;
}

LogManager::~LogManager() {
	closeFile();
	delete instance;
	instance = NULL;
}

void LogManager::setLogFile(std::string fileName) {
	closeFile();
	oStream = new std::ofstream(fileName);
}

void LogManager::setMinSeverity(LogManager::LogSeverity severity) {
	minSeverity = severity;
}

LogManager::LogSeverity LogManager::getMinSeverity() {
	return minSeverity;
}

void LogManager::closeFile() {
	if (oStream != NULL) {
		oStream->flush();
		delete oStream;
		oStream = NULL;
	}
}

void LogManager::log(LogSeverity severity, std::string msg) {
	if (severity >= minSeverity) {
		if (oStream == NULL) {
			setLogFile("Gungine.log");
		}

		*oStream << msg << "\n";
		oStream->flush();
	}
}