#include <iostream>
#include "GungineApp.h"
#include "Win32Window.h"

using namespace std;
using namespace gungine;

GungineApp* app;

void onStart() {
	std::cout << "stuurt";
	app->render();
}

int main() {
	app = GungineApp::get();

	app->registerStartFunc(onStart);

	app->createWindow();

	//GungineWindow* window = new Win32Window();
	//window->create();

	//cin.get();
	return 0;
}