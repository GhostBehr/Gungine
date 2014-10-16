#pragma once

#include <iostream>

#include "glut.h"
#include "GungineRenderer.h"

namespace gungine {
	class OpenGLRenderer : public GungineRenderer {
	public:
		OpenGLRenderer() { }

		virtual void renderPrimitive(GraphicPrimitiveType type);
	};
}