#ifndef GEOMETRY_CREATOR_H
#define GEOMETRY_CREATOR_H

#include "Shape.h"
#include "vertex.h"
class GeometryCreator{

public:
/*
 Creates cube with x,y,z co ordinate as the closest to the center, x,y,z is not the center
*/
 static Shape* create_cube(double x, double y, double z,int size){
    Shape *cube = new Shape();
    cube->vertices.push_back(new vertex(x,y,z));
    cube->vertices.push_back(new vertex(x+size,y,z));
    cube->vertices.push_back(new vertex(x+size,y+size,z));
    cube->vertices.push_back(new vertex(x,y+size,z));
    cube->vertices.push_back(new vertex(x+size,y,z+size));
    cube->vertices.push_back(new vertex(x+size,y+size,z+size));
    cube->vertices.push_back(new vertex(x,y+size,z+size));
    cube->vertices.push_back(new vertex(x,y,z+size));
    return cube;
//0,0,0
//1,0,0
//1,1,0
//0,1,0
//1,0,1
//1,1,1
//0,1,1
//0,0,1

 }


};


#endif
