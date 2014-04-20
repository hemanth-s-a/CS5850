#include <stdio.h>

#include "GameWorld.h"

game_world::game_world () {
	bounds = new BoundingBox(0,0,0,800,800,800);
	oct = new OctTree(bounds);
}

void game_world::add_object (Shape* s) {
	world_objects.push_back (s);
}

void game_world::draw () {
	for (int i = 0; i < world_objects.size(); ++i) {
		printf ("Drawing 1st\n");
		world_objects.at(i)->draw();
	}
}