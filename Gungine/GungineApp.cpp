#include "GungineApp.h"
using namespace gungine;

GungineApp* GungineApp::instance = NULL;

GungineApp::GungineApp() {
	startFunc = NULL;
	preRenderFunc = NULL;
	renderFunc = NULL;
	postRenderFunc = NULL;
	endFunc = NULL;

	window = NULL;
	renderer = new OpenGLRenderer();
}

void GungineApp::createWindow() {
	window = new Win32Window();
	window->create();
}

/// Base function calls to pointers
void GungineApp::onStart() {
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