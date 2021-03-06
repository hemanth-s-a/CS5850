#ifndef SHAPE_H
#define SHAPE_H

#include "vertex.h"
#include "BoundingBox.h"
#include <vector>

using namespace std;

class Shape {

public:
	vector<vertex*> vertices;
	int size;
	vector<int> indices;
	BoundingBox *bbox;
	bool grabbed;
	
	BoundingBox* getBoundingBox(){
	    if(!bbox){
            bbox = new BoundingBox();
	    }
	    if(vertices.size() ==0){
            bbox->reset();
	    }else{
            bbox->reset(vertices.at(0));
	    }
        for(size_t i=1; i < vertices.size() ;i++ ){
            bbox->add_vertex(vertices.at(i));
        }

	    return bbox;
	}
	
	// draws this shape on to the screen
	void draw ();
	
	// if the mouse button was pressed inside this shape, the shape is grabbed for movement.
	void grab_object (const double xpos, const double ypos);
	
	// this function calculates the minimum and maximum values of x, y and z coordinates
	// of the shape
	void get_max_min_vertex (vertex *max, vertex *min);
	
	// releases the shape when the mouse button is released
	void release_object ();
	
	// this function is responsible for moving the shape around the screen
	// dragging the object
	void move_shape (const double xpos, const double ypos);
};

#endif
