#pragma once

#include <iostream>

#include "GungineWindow.h"
#include "Win32Window.h"
#include "GungineRenderer.h"
#include "OpenGLRenderer.h"

namespace gungine {
	class GungineApp {
	private:
		static GungineApp* instance;

		GungineApp();
		GungineApp(const GungineApp& lm) { }
		void operator=(const GungineApp& lm) { }

		typedef void(*callback_func)();
		callback_func startFunc, preRenderFunc, renderFunc, postRenderFunc, endFunc;

		GungineWindow* window;
		GungineRenderer* renderer;

	public:
		static GungineApp* get() {
			if (instance == NULL) {
				instance = new GungineApp();
			}
			return instance;
		}

		void createWindow();

		/// Base function calls to pointers
		void onStart();
		void preRender();
		void render();
		void postRender();
		void onEnd();


		/// Register callback function pointers
		void registerStartFunc(callback_func func);
		void registerPreRenderFunc(callback_func func);
		void registerRenderFunc(callback_func func);
		void registerPostRenderFunc(callback_func func);
		void registerEndFunc(callback_func func);
	};
}