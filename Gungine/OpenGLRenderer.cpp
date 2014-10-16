#include "OpenGLRenderer.h"


using namespace gungine;

void OpenGLRenderer::init() {
	glEnable(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLRenderer::setWindowSize(int width, int height) {
	winWidth = width;
	winHeight = height;

	glViewport(0, 0, winWidth, winHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0f, winWidth / winHeight, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void OpenGLRenderer::renderPrimitive(GraphicPrimitiveType type) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	switch (type) {
	case GraphicPrimitiveType::TRIANGLES:
		glPushMatrix();

		glTranslatef(0.0f, 0.0f, -5.0f);	// temp

		std::cout << "triangles!\n";

		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.5f, 0.0f);
		glVertex2f(0.0f, 0.5f);
		glEnd();

		glPopMatrix();

		break;

	case GraphicPrimitiveType::TRIANGLE_STRIP:
		//strip
		break;
	}

	glFlush();
}