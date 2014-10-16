#pragma once

namespace gungine {

	/// Right now this isn't really gonna do anything?
	/// It should all be in OpenGLRenderer
	/// Unless I figure out how to do it hold on
	/// Oh wait yeah, stuff calls my renderPrimitive(), this makes sense

	enum GraphicPrimitiveType {
		TRIANGLES = 0,
		TRIANGLE_STRIP
	};

	class GungineRenderer {
	public:
		GungineRenderer() { }

		virtual void renderPrimitive(GraphicPrimitiveType type) = 0;
	};

}