#include "OctTree.h"

/**
    Creating a oct tree with for the specified bounds in x, y, x bounds. The boundary is sub divided in to 8 parts
    for the specified recursively. The number of sub division is controlled by MAX_LEVELS.

    A Octree with below bounds will be sub divided into below 8 smaller boundaries

     min range  ||   max range
    x   y    z     x    y    z
    0   0    0    800  800  800

     BOUNDS OF CHILD OCT TRESS

    0   0    0    400  400  400
    400 0    0    800  400  400
    0   400  0    400  800  400
    400 400  0    800  800  400
    0   0    400  400  400  800
    400 0    400  800  400  800
    0   400  400  400  800  800
    400 400  400  800  800  800

*/

OctTree::OctTree(BoundingBox *bound,int level){
    this->bound = bound;
    this->level = level;
    this->objects = new vector<Shape*>();

    if(level < MAX_LEVELS){
        int hlength = (bound->max.x - bound->min.x)/2;
        int hwidth = (bound->max.x - bound->min.x)/2;
        int hheight = (bound->max.x - bound->min.x)/2;

        BoundingBox *b1 = new BoundingBox(bound->min.x,bound->min.y,bound->min.z,
                                         bound->min.x + hlength,bound->min.y +hwidth,bound->min.z + hheight);
        BoundingBox *b2 = new BoundingBox(bound->min.x+hlength,bound->min.y,bound->min.z,
                                         bound->max.x,bound->min.y +hwidth,bound->min.z + hheight);
        BoundingBox *b3 = new BoundingBox(bound->min.x,bound->min.y+hwidth,bound->min.z,
                                         bound->min.x + hlength,bound->max.y,bound->min.z + hheight);
        BoundingBox *b4 = new BoundingBox(bound->min.x + hlength,bound->min.y+hwidth,bound->min.z,
                                         bound->max.x ,bound->max.y,bound->min.z + hheight);

        BoundingBox *b5 = new BoundingBox(bound->min.x,bound->min.y,bound->min.z + hheight,
                                         bound->min.x + hlength,bound->min.y +hwidth,bound->max.z);
        BoundingBox *b6 = new BoundingBox(bound->min.x+hlength,bound->min.y,bound->min.z + hheight,
                                         bound->max.x,bound->min.y +hwidth,bound->max.z);
        BoundingBox *b7 = new BoundingBox(bound->min.x,bound->min.y+hwidth,bound->min.z + hheight,
                                         bound->min.x + hlength,bound->max.y,bound->max.z);
        BoundingBox *b8 = new BoundingBox(bound->min.x + hlength,bound->min.y+hwidth,bound->min.z + hheight,
                                         bound->max.x ,bound->max.y,bound->max.z);

        this->child = new vector<OctTree*>();

        this->child->push_back(new OctTree(b1,level+1));
        this->child->push_back(new OctTree(b2,level+1));
        this->child->push_back(new OctTree(b3,level+1));
        this->child->push_back(new OctTree(b4,level+1));
        this->child->push_back(new OctTree(b5,level+1));
        this->child->push_back(new OctTree(b6,level+1));
        this->child->push_back(new OctTree(b7,level+1));
        this->child->push_back(new OctTree(b8,level+1));
    }else{
        this->child = NULL;
    }

}

/**
    Adds the object to the oct tree. If the objects bounding box cannot be contained withing the
    bounds of this oct tree, the object cannot be added. If the object lies within one of the child nodes
    then insert_object is called recursively for that oct tree. If the object cannot be placed in
    any of the child oct trees but lies inside the current oct tree, it is added to the current oct tree

*/

void OctTree::insert_object(Shape *p){
    BoundingBox *obj_box = p->getBoundingBox();
    if(bound->contains(obj_box))
    {
        bool is_inserted = false;
        if(child != NULL)
        {
            for(size_t i=0; i < child->size() ; i++ )
            {
                if(child->at(i)->bound->contains(obj_box))
                {
                    child->at(i)->insert_object(p);
                    is_inserted = true;
                }
            }
        }
        if(!is_inserted){
            objects->push_back(p);
        }

    }else{
        printf("not insert %d \n",level);
    }

}

/**

 This method returns list of object pairs whose bounding box's collides.
 Collision between two objects can occur in two scenario's
   1. both objects lie inside the same bounds ( same oct tree)
   2. first object is in bound b, second object is not completely inside bound b
      there fore it will be added to the parent octtree

*/

void OctTree::get_colliding_objects_bb(vector< vector<Shape*>* >* colliding_objects){

    // first call will have no parent objects
    vector<Shape*> * parent_objects = new vector<Shape*>();
    // calling function with empty parent objects, this function is called recursively
    get_colliding_objects_bb(colliding_objects,parent_objects);
    delete parent_objects;

}


void OctTree::get_colliding_objects_bb(vector< vector<Shape*>* >* colliding_objects,vector<Shape*> * parent_objects){

    // checking for collision within the same oct tree objects
    colliding_objects_in_node(colliding_objects);
    // checking for collision with objects in parent octree's
    colliding_objects_parent(colliding_objects,parent_objects);

    int size_parent_list = parent_objects->size();
    parent_objects->insert(parent_objects->end(),objects->begin(),objects->end());
    if(child != NULL)
    {
        // recursively calling get_colliding_objects to check collisions in child oct trees
        for(size_t i=0; i< child->size() ; i++)
        {
            child->at(i)->get_colliding_objects_bb(colliding_objects,parent_objects);
        }
    }
    parent_objects->erase(parent_objects->begin()+size_parent_list, parent_objects->end());

}

// checking for collision among the objects in the octree
void OctTree::colliding_objects_in_node(vector< vector<Shape*>* >* colliding_objects)
{
    for(size_t i=0; i< objects->size() ; i++)
    {
        for(size_t j=i; j < objects->size() ; j++)
        {
            if(i==j)
                continue;

            if(objects->at(i)->getBoundingBox()->collide(objects->at(j)->getBoundingBox()))
            {
                vector<Shape*> *colliding_pair = new  vector<Shape*>();
                colliding_pair->push_back(objects->at(i));
                colliding_pair->push_back(objects->at(j));
                colliding_objects->push_back(colliding_pair);
            }
        }
    }

}

// checking for collision among the objects within the octree with the objects in the parent octree
void OctTree::colliding_objects_parent(vector< vector<Shape*>* >* colliding_objects,vector<Shape*> * parent_objects)
{
    for(size_t i=0; i< parent_objects->size() ; i++)
    {
        for(size_t j=0; j < objects->size() ; j++)
        {
            if(parent_objects->at(i)->getBoundingBox()->collide(objects->at(j)->getBoundingBox()))
            {
                vector<Shape*> *colliding_pair = new  vector<Shape*>();
                colliding_pair->push_back(parent_objects->at(i));
                colliding_pair->push_back(objects->at(j));
                colliding_objects->push_back(colliding_pair);

            }
        }
    }

}


void OctTree::clear_objects(){

    objects->clear();

    if(child){
        for(size_t i=0; i < child->size() ; i++ ){
                child->at(i)->clear_objects();
        }
    }

}

