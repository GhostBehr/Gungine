#pragma once

namespace gungine {
	class GungineWindow {

		/// So this should really be a factory
		/// and create a Win32OpenGLWindow, etc
		/// but for now Win32 will just have some openGL stuff
		/// because I'm just realizing they can't be as decoupled as I wanted

	public:
		GungineWindow() { }

		virtual int create() = 0;
	};
}