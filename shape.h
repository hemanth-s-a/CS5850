#ifndef SHAPE_H
#define SHAPE_H

#include "vertex.h"
#include "BoundingBox.h"
#include <vector>

using namespace std;

class Shape {

public:
	vector<vertex*> vertices;
	vector<int> indices;
	BoundingBox *bbox;
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
};

#endif
