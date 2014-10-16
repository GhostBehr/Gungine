#include "GungineApp.h"
using namespace gungine;

GungineApp* GungineApp::instance = NULL;
int GungineApp::winWidth = 0;
int GungineApp::winHeight = 0;

GungineApp::GungineApp(int width, int height) {
	startFunc = NULL;
	preRenderFunc = NULL;
	renderFunc = NULL;
	postRenderFunc = NULL;
	endFunc = NULL;

	winWidth = width;
	winHeight = height;
	running = true;

	window = NULL;
	renderer = new OpenGLRenderer();
}

void GungineApp::setWindowSize(int width, int height) {
	if (winWidth == 0 || winHeight == 0) {
		winWidth = width;
		winHeight = height;
	}
}

void GungineApp::mainLoop() {
	window = new Win32Window();
	window->create(winWidth, winHeight);
}


/// Base function calls to pointers
void GungineApp::onStart() {
	renderer->init();
	renderer->setWindowSize(winWidth, winHeight);
	
	if (startFunc) {
		startFunc();
	}
}

void GungineApp::preRender() {
	if (preRenderFunc) {
		preRenderFunc();
	}
}

void GungineApp::render() {
	if (renderFunc) {
		renderFunc();
	}

	renderer->renderPrimitive(GraphicPrimitiveType::TRIANGLES);
}

void GungineApp::postRender() {
	if (postRenderFunc) {
		postRenderFunc();
	}
}

void GungineApp::onEnd() {
	if (endFunc) {
		endFunc();
	}

	running = false;
}


/// Register callback function pointers
void GungineApp::registerStartFunc(callback_func func) {
	startFunc = func;
}

void GungineApp::registerPreRenderFunc(callback_func func) {
	preRenderFunc = func;
}

void GungineApp::registerRenderFunc(callback_func func) {
	renderFunc = func;
}

void GungineApp::registerPostRenderFunc(callback_func func) {
	postRenderFunc = func;
}

void GungineApp::registerEndFunc(callback_func func) {
	endFunc = func;
}