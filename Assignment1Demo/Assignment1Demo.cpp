#include <iostream>

#include "Clock.h"
#include "LogManager.h"

int main() {
	using namespace std;
	using namespace gungine;

	Clock::init();

	cout << Clock::getCurrentTimeSeconds() << endl;
	cout << Clock::getCurrentTimeMillis() << endl;
	cin.get();

	cout << Clock::getCurrentTimeSeconds() << endl;
	cout << Clock::getCurrentTimeMillis() << endl;
	cin.get();

	LogManager* lm = LogManager::get();
	lm->log(LogManager::LOG_ERROR, "Error");
	lm->log(LogManager::LOG_WARNING, "Warning");
	lm->log(LogManager::LOG_TRACE, "Trace");
	lm->log(LogManager::LOG_INFO, "Info");

	cout << lm->getMinSeverity() << endl;
	lm->setMinSeverity(LogManager::LOG_TRACE);
	cout << lm->getMinSeverity() << endl;

	lm->log(LogManager::LOG_ERROR, "Error");
	lm->log(LogManager::LOG_WARNING, "Warning");
	lm->log(LogManager::LOG_TRACE, "Trace");
	lm->log(LogManager::LOG_INFO, "Info");

	lm->setLogFile("Gungine2.log");

	lm->log(LogManager::LOG_ERROR, "Error");
	lm->log(LogManager::LOG_WARNING, "Warning");
	lm->log(LogManager::LOG_TRACE, "Trace");
	lm->log(LogManager::LOG_INFO, "Info");

	cin.get();
	return 0;
}