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
	int a[3];
    Shape *cube = new Shape();
    cube->vertices.push_back(new vertex(x,y,z));
    cube->vertices.push_back(new vertex(x+size,y,z));
    cube->vertices.push_back(new vertex(x+size,y+size,z));
    cube->vertices.push_back(new vertex(x,y+size,z));
    cube->vertices.push_back(new vertex(x+size,y,z+size));
    cube->vertices.push_back(new vertex(x+size,y+size,z+size));
    cube->vertices.push_back(new vertex(x,y+size,z+size));
    cube->vertices.push_back(new vertex(x,y,z+size));
	
	a[0] = 0; a[1] = 1; a[2] = 2;
	cube->indices.insert (cube->indices.end(), a, a+3);
	a[0] = 0; a[1] = 2; a[2] = 3;
	cube->indices.insert (cube->indices.end(), a, a+3);
	a[0] = 3; a[1] = 2; a[2] = 5;
	cube->indices.insert (cube->indices.end(), a, a+3);
	a[0] = 3; a[1] = 5; a[2] = 6;
	cube->indices.insert (cube->indices.end(), a, a+3);
	a[0] = 1; a[1] = 2; a[2] = 4;
	cube->indices.insert (cube->indices.end(), a, a+3);
	a[0] = 2; a[1] = 4; a[2] = 5;
	cube->indices.insert (cube->indices.end(), a, a+3);
	a[0] = 0; a[1] = 1; a[2] = 4;
	cube->indices.insert (cube->indices.end(), a, a+3);
	a[0] = 0; a[1] = 4; a[2] = 7;
	cube->indices.insert (cube->indices.end(), a, a+3);
	a[0] = 5; a[1] = 6; a[2] = 7;
	cube->indices.insert (cube->indices.end(), a, a+3);
	a[0] = 5; a[1] = 4; a[2] = 7;
	cube->indices.insert (cube->indices.end(), a, a+3);
	a[0] = 0; a[1] = 3; a[2] = 7;
	cube->indices.insert (cube->indices.end(), a, a+3);
	a[0] = 3; a[1] = 6; a[2] = 7;
	cube->indices.insert (cube->indices.end(), a, a+3);
	
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
