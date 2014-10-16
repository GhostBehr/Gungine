#include <iostream>
#include "GungineApp.h"
#include "Win32Window.h"

using namespace std;
using namespace gungine;

GungineApp* app;

void onStart() {
	std::cout << "Starting...\n";
}

int main() {
	GungineApp::setWindowSize(500, 400);
	app = GungineApp::get();

	app->registerStartFunc(onStart);

	app->mainLoop();

	//cin.get();
	return 0;
}