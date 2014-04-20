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
	
	//void check_collision () {
		
	//}
};