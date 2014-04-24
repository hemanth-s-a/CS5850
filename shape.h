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
	
	void draw ();
	void grab_object (const double xpos, const double ypos);
	void get_max_min_vertex (vertex *max, vertex *min);
	void release_object ();
	void move_shape (const double xpos, const double ypos);
};

#endif
