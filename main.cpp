#include <time.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

#include <GLFW/glfw3.h>

#include "OctTree.h"
#include "GeometryCreator.h"
#include "GameWorld.h"
#include "Draw\glfwInit.cc"
using namespace std;

void main_loop (GLFWwindow* window) {
	game_world world_object;
	world_object.add_object (GeometryCreator::create_cube(0,0,0,300));
	while (true) {
		glClear(GL_COLOR_BUFFER_BIT);
		world_object.draw (window);
		glfwSwapBuffers(window);
	}
}

int main()
{
    
	
	GLFWwindow* window;

 //printf("%f %f %f %f %f %f \n", bounds->min.x,bounds->min.y,bounds->min.z,bounds->max.x,bounds->max.y,bounds->max.z);


    
   // printf("level %d \n", oct->level);
   //  printf("%f %f %f %f %f %f \n", oct->bound->min.x,oct->bound->min.y,oct->bound->min.z,oct->bound->max.x,oct->bound->max.y,oct->bound->max.z);

	/*
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

    //delete(oct);
	*/
	
	glfwMyInit (window);
	main_loop (window);
    return 0;

}
