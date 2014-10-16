#pragma once

#include <Windows.h>

namespace gungine {
	class Clock {
	private:
		static LARGE_INTEGER startTime;
		static LARGE_INTEGER ticksPerSecond;

		Clock() { }
	public:
		static void init();
		static double getCurrentTimeSeconds();
		static double getCurrentTimeMillis();
	};
}