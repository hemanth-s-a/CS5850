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

vector< vector<Shape*>* >* game_world::detect_collisions(){

    oct->clear_objects();

    for(size_t i = 0; i < world_objects.size(); i++)
    {
        oct->insert_object(world_objects.at(i));
    }

    vector< vector<Shape*>* >* colliding_objects = new vector< vector<Shape*>* >();
    oct->get_colliding_objects_bb(colliding_objects);
    return colliding_objects;
}

void game_world::move_objects (const double xpos, const double ypos) {
	for (int i = 0; i < world_objects.size(); ++i) {
		if (world_objects.at(i)->grabbed) {
			world_objects.at(i)->move_shape(xpos, ypos);
		}
	}
}

void game_world::draw (vector< vector<Shape*>* >* colliding_objects) {

	glColor4f (1, 1, 1,.4);
	for (int i = 0; i < world_objects.size(); ++i) {
		world_objects.at(i)->draw();
	}

	glColor4f(1,0,0,.4);
	for (int i = 0; i < colliding_objects->size(); ++i) {
		for (int j = 0; j < colliding_objects->at(i)->size(); ++j) {
			colliding_objects->at(i)->at(j)->draw();
		}
	}
}

void game_world::grab_object (const double xpos, const double ypos) {
	for (int i = 0; i < world_objects.size(); ++i) {
		world_objects.at(i)->grab_object(xpos, ypos);
	}
}

void game_world::release_object () {
	for (int i = 0; i < world_objects.size(); ++i) {
		world_objects.at(i)->release_object();
	}
}
