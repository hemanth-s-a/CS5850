#include <vector>

#include "OctTree.h"
#include "GeometryCreator.h"

class game_world {
	vector<Shape*> world_objects;

	OctTree *oct;

	BoundingBox *bounds;

	public:

	game_world ();
	
	// adds a new shape/object to the displayed world. This object can be used as needed
	void add_object (Shape* s);
	
	// this function is responsible for drawing the shape. Displays all shapes
	// created on to the screen
	void draw (vector< vector<Shape*>* >* colliding_objects);
	
	// this function is called everytime we check for collision
	vector< vector<Shape*>* >* detect_collisions();
	
	// this function is called only when the mouse button is pressed.
	// this function checks if the button was pressed inside the boundaries or a particular object.
	// if the condition is true, the object is grabbed for movement
	void grab_object (const double xpos, const double ypos);
	
	// once the object has been grabbed any movement of the mouse when the button held down
	// causes the grabbed object to move along with the cursor
	void move_objects (const double xpos, const double ypos);
	
	// this is called everytime there occurs a button release
	void release_object ();
};
