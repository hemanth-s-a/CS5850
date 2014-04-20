#include <GLFW\glfw3.h>

#include "shape.h"

void Shape::draw () {
	
	glBegin (GL_TRIANGLES);
	{
		for (int i = 0; i < indices.size(); ++i) {
			glVertex2d (vertices.at(indices.at(i))->x, vertices.at(indices.at(i))->y);
		}
	}
	glEnd();
}