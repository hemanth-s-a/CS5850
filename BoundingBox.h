#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H
#include "vertex.h"


class BoundingBox{

	public:
    vertex min;
	vertex max;
    BoundingBox();
    BoundingBox(double xmin,double ymin, double zmin, double xmax , double ymax, double zmax);
	void add_vertex(vertex *v);
	bool collide(BoundingBox *b1);
	bool inside(BoundingBox *b1);
	bool contains(BoundingBox *b1);
	void reset(vertex *v);
	void reset();

};

#endif
