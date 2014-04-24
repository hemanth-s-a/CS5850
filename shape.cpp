#include <GLFW\glfw3.h>
#include <stdio.h>

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

/*Shape::Shape () {
	this->grabbed = false;
}*/

void Shape::grab_object (const double xpos, const double ypos) {
	vertex max, min;
	this->get_max_min_vertex (&max, &min);
	if (xpos <= max.x && xpos >= min.x && ypos <= max.y && ypos >= min.y) {
		//printf ("Entered\n");
		this->grabbed = true;
	}
}

void Shape::move_shape (const double xpos, const double ypos) {
	double xmin, xmax, ymin, ymax;
	xmin = xpos - (this->size/2);
	xmax = xpos + (this->size/2);
	ymin = ypos - (this->size/2);
	ymax = ypos + (this->size/2);
	vertices.at(0)->x = xmin;
	vertices.at(0)->y = ymin;
	
	vertices.at(1)->x = xmax;
	vertices.at(1)->y = ymin;
	
	vertices.at(2)->x = xmax;
	vertices.at(2)->y = ymax;
	
	vertices.at(3)->x = xmin;
	vertices.at(3)->y = ymax;
	
	vertices.at(4)->x = xmax;
	vertices.at(4)->y = ymin;
	
	vertices.at(5)->x = xmax;
	vertices.at(5)->y = ymax;
	
	vertices.at(6)->x = xmin;
	vertices.at(6)->y = ymax;
	
	vertices.at(7)->x = xmin;
	vertices.at(7)->y = ymin;
}

void Shape::get_max_min_vertex (vertex *max, vertex *min) {
	max->x = vertices.at(0)->x;
	max->y = vertices.at(0)->y;
	min->x = vertices.at(0)->x;
	min->y = vertices.at(0)->y;
	
	for (int i = 0; i < vertices.size(); ++i) {
		if (max->x < vertices.at(i)->x) {
			max->x = vertices.at(i)->x;
		}
		if (max->y < vertices.at(i)->y) {
			max->y = vertices.at(i)->y;
		}
		if (min->x > vertices.at(i)->x) {
			min->x = vertices.at(i)->x;
		}
		if (min->y > vertices.at(i)->y) {
			min->y = vertices.at(i)->y;
		}
	}
}

void Shape::release_object () {
	this->grabbed = false;
}