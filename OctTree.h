#ifndef OCTTREE_H
#define OCTTREE_H

#include <vector>
#include <stdio.h>
#include <iostream>
#include "BoundingBox.h"
#include "shape.h"

#define MAX_LEVELS 3
using namespace std;

class OctTree{

public:
   OctTree(BoundingBox *bound):OctTree(bound,0){}
   OctTree(BoundingBox *bound,int levels);
   void insert_object(Shape *p);
   void get_colliding_objects_bb(vector< vector<Shape*>* >* colliding_objects);

private:

    BoundingBox *bound;
    int level;
    vector<OctTree*> *child;
    vector<Shape*> *objects;
    
    void colliding_objects_in_node(vector< vector<Shape*>* >* colliding_objects);
    void get_colliding_objects_bb(vector< vector<Shape*>* >* colliding_objects,vector<Shape*> * parent);
    void colliding_objects_parent(vector< vector<Shape*>* >* colliding_objects,vector<Shape*> * parent_objects);
};


#endif
