#include "OpenGLRenderer.h"


using namespace gungine;

void OpenGLRenderer::renderPrimitive(GraphicPrimitiveType type) {
	std::cout << "Render";

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluPerspective(45.0f, 100.0f / 40.0f, 0.1f, 100.0f);

	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	//glClear(GL_COLOR_BUFFER_BIT);

	switch (type) {
	case GraphicPrimitiveType::TRIANGLES:
		std::cout << "Triis";
		//glBegin(GL_TRIANGLES);
		//glColor3f(1.0f, 0.0f, 0.0f);
		//glVertex3f(0.0f, 0.0f, 0.0f);
		//glVertex3f(0.5f, 0.0f, 0.0f);
		//glVertex3f(0.0f, 0.5f, 0.0f);
		//glEnd();

		glEnable(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glViewport(0, 0, 20, 20);
		
		glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glPushMatrix();
		glBegin(GL_QUADS);
		glVertex3i(1, 1, 0);
		glVertex3i(1, -1, 0);
		glVertex3i(-1, -1, 0);
		glVertex3i(-1, 1, 0);
		glPopMatrix();

		break;

	case GraphicPrimitiveType::TRIANGLE_STRIP:
		//strip
		break;
	}

	glFlush();
}