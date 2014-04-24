#include <vector>

#include "OctTree.h"
#include "GeometryCreator.h"

class game_world {
	vector<Shape*> world_objects;

	OctTree *oct;

	BoundingBox *bounds;

	public:

	game_world ();
	void add_object (Shape* s);
	void draw (vector< vector<Shape*>* >* colliding_objects);
	vector< vector<Shape*>* >* detect_collisions();
	void grab_object (const double xpos, const double ypos);
	void move_objects (const double xpos, const double ypos);
	void release_object ();
};
