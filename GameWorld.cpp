#include <GLFW\glfw3.h>

#include <stdio.h>

#include "GameWorld.h"

game_world::game_world () {
	bounds = new BoundingBox(0,0,0,800,800,800);
	oct = new OctTree(bounds);
}

void game_world::add_object (Shape* s) {
	world_objects.push_back (s);
}

void game_world::draw (vector< vector<Shape*>* >* colliding_objects) {
	glColor3f (1, 1, 1);
	for (int i = 0; i < world_objects.size(); ++i) {
		//printf ("Drawing 1st\n");
		world_objects.at(i)->draw();
	}
	glColor3f (1, 0, 0);
	for (int i = 0; i < colliding_objects->size(); ++i) {
		for (int j = 0; j < colliding_objects->at(i)->size(); ++j) {
			colliding_objects->at(i)->at(j)->draw();
		}
	}
}