#include <GL/freeglut.h>
#include "actor.h"

actor::actor()
{

}

void actor::drawActor()
{
	
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glVertex2f(0.1f, 0.1f);
		glVertex2f(0.3f, 0.1f);
		glVertex2f(0.1f, 0.3f);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(0.1f, 0.3f);
		glVertex2f(0.3f, 0.1f);
		glVertex2f(0.3f, 0.3f);
	glEnd();

	
}