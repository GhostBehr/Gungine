#include "Clock.h"
using namespace gungine;

LARGE_INTEGER Clock::startTime;
LARGE_INTEGER Clock::ticksPerSecond;

void Clock::init() {
	QueryPerformanceFrequency(&ticksPerSecond);
	QueryPerformanceCounter(&startTime);
}

double Clock::getCurrentTimeSeconds() {
	LARGE_INTEGER currentTicks;
	QueryPerformanceCounter(&currentTicks);
	return double(currentTicks.QuadPart - startTime.QuadPart) / double(ticksPerSecond.QuadPart);
}

double Clock::getCurrentTimeMillis() {
	return getCurrentTimeSeconds() * 60;
}