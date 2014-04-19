#include "BoundingBox.h"
#include <stdio.h>
 BoundingBox::BoundingBox(){
 }

 BoundingBox::BoundingBox(double xmin,double ymin, double zmin, double xmax , double ymax, double zmax){
     min.x=xmin;
     min.y=ymin;
     min.z=zmin;

     max.x=xmax;
     max.y=ymax;
     max.z=zmax;
 }

void BoundingBox::reset(){
    min.x = 0;
    min.y = 0;
    min.z = 0;

    max.x = 0;
    max.y = 0;
    max.z = 0;

}

void BoundingBox::reset(vertex *v){
    min.x = v->x;
    min.y = v->y;
    min.z = v->z;

    max.x = v->x;
    max.y = v->y;
    max.z = v->z;

}

void BoundingBox::add_vertex(vertex *v)
{
    if(min.x > v->x)
        min.x = v->x;
    if(max.x < v->x)
        max.x = v->x;

    if(min.y > v->y)
        min.y = v->y;
    if(max.y < v->y)
        max.y = v->y;

    if(min.z > v->z)
        min.z = v->z;
    if(max.z < v->z)
        max.z = v->z;
}

bool BoundingBox::collide(BoundingBox *b1)
{
    if(min.x <= b1->max.x  && max.x >= b1->min.x )
        if(min.y <= b1->max.y  && max.y >= b1->min.y )
            if(min.z <= b1->max.z  && max.z >= b1->min.z )
                return true;

    return false;
}


bool BoundingBox::inside(BoundingBox *b1)
{
    if(min.x >= b1->min.x  && max.x <= b1->max.x )
        if(min.y >= b1->min.y  && max.y <= b1->max.y )
            if(min.z >= b1->min.z  && max.z <= b1->max.z )
                return true;

    return false;
}


bool BoundingBox::contains(BoundingBox *b1)
{
    if(min.x <= b1->min.x  && max.x >= b1->max.x )
        if(min.y <= b1->min.y  && max.y >= b1->max.y )
            if(min.z <= b1->min.z  && max.z >= b1->max.z )
                return true;

    return false;
}





