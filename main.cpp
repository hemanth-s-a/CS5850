#include <iostream>
#include <vector>

#include "OctTree.h"
#include "GeometryCreator.h"
using namespace std;

int main()
{
    BoundingBox *bounds = new BoundingBox(0,0,0,800,800,800);

 //printf("%f %f %f %f %f %f \n", bounds->min.x,bounds->min.y,bounds->min.z,bounds->max.x,bounds->max.y,bounds->max.z);


    OctTree *oct = new OctTree(bounds);
   // printf("level %d \n", oct->level);
   //  printf("%f %f %f %f %f %f \n", oct->bound->min.x,oct->bound->min.y,oct->bound->min.z,oct->bound->max.x,oct->bound->max.y,oct->bound->max.z);


    Shape *p = GeometryCreator::create_cube(0,0,0,300);
    Shape *p2 = GeometryCreator::create_cube(0,0,0,1);
    Shape *p3 = GeometryCreator::create_cube(450,0,0,300);


    oct->insert_object(p);
    oct->insert_object(p2);
    oct->insert_object(p3);

    vector< vector<Shape*>* >* colliding_objects = new vector< vector<Shape*>* >();
    printf("size before %d \n" , colliding_objects->size());
    oct->get_colliding_objects_bb(colliding_objects);
    printf("size after %d \n" , colliding_objects->size());
    //printf("%f %f %f %f %f %f \n", p->bbox->min.x,p->bbox->min.y,p->bbox->min.z,p->bbox->max.x,p->bbox->max.y,p->bbox->max.z);
    oct->clear_objects();

    delete(oct);
    return 0;

}
