#pragma once

#include <iostream>

#include "glut.h"
#include "GungineRenderer.h"

namespace gungine {
	class OpenGLRenderer : public GungineRenderer {
	public:
		OpenGLRenderer() { }

		virtual void init();
		virtual void setWindowSize(int width, int height);
		virtual void renderPrimitive(GraphicPrimitiveType type);
	};
}