#include <vector>

#include "OctTree.h"
#include "GeometryCreator.h"

class game_world {
	vector<Shape*> world_objects;
	
	OctTree *oct;
	
	BoundingBox *bounds;
	
	public:
	
	game_world () {
		bounds = new BoundingBox(0,0,0,800,800,800);
		oct = new OctTree(bounds);
	}
	
	void add_object (Shape* s) {
		world_objects.push_back (s);
	}
	
	void draw (GLFWwindow* window) {
		for (int i = 0; i < world_objects.size(); ++i) {
			world_objects.at(i)->draw (window);
		}
	}
	
	void check_collision () {
		
	}
};