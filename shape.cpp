#include <shape.h>

void Shape::draw (GLFWwindow* window) {
	
	glBegin (GL_TRIANGLES);
	{
		for (int i = 0; i < indices.size(); ++i) {
			glVertex3d (vertices.at(indices.at(i)).x, vertices.at(indices.at(i)).y, vertices.at(indices.at(i)).z);
		}
	}
	glEnd();
}