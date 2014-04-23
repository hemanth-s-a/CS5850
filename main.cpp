#include <stdio.h>
//#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <GLFW\glfw3.h>

#include <iostream>
#include <vector>

#include "OctTree.h"
#include "GeometryCreator.h"
#include "GameWorld.h"
using namespace std;

void error_callback(int error, const char* description) {
    fputs(description, stderr);
}

void close_callback(GLFWwindow* window) {
	//game_status = NO_STATE;
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(0);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        close_callback(window);
}

void resize_callback(GLFWwindow* window, int width, int height) {

	float ratio = width / (float) height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.f, ratio, 0.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
}

void game_loop(GLFWwindow* window, game_world* world) {
//	double new_time;
//	int width, height;
//	int frame = 1;
	//double game_time = glfwGetTime();



		//new_time = glfwGetTime();
		//if((new_time - game_time) >= 0.02) {
			//game_time = new_time;

			glClear(GL_COLOR_BUFFER_BIT);
			glLoadIdentity();
            vector< vector<Shape*>* >* colliding_objects = world->detect_collisions();
			world->draw(colliding_objects);

			//render_everything(frame++);


			glfwSwapBuffers(window);
			glfwPollEvents();


}

int main()
{
   	game_world* world = new game_world();

    Shape *p = GeometryCreator::create_cube(300,300,0,200);
       Shape *p1 = GeometryCreator::create_cube(400,400,300,150);

   Shape *p2 = GeometryCreator::create_cube(450,450,0,200);



	world->add_object (p);
	world->add_object (p1);
	world->add_object (p2);



	GLFWwindow* window;
	if(!glfwInit()) {
		return 1;
	}
	glfwSetErrorCallback(error_callback);
	window = glfwCreateWindow(800, 600, "Game Loop", NULL, NULL);
	if(!window) {
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);
	//glfwSetWindowSizeCallback(window, resize_callback);
	glfwSetWindowCloseCallback(window, close_callback);
	glfwSetKeyCallback(window, key_callback);

    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	while(true) {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.f, 800.0f, 0.f, 600, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//glfwSetMouseButtonCallback(window, mouse_callback);

		//draw_first_screen(window);

		//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		//srand(time(NULL));

		//int width, height;
		//glfwGetFramebufferSize(window, &width, &height);
		//resize_callback(window, width, height);


		game_loop(window, world);

		/*glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.f, 800, 0.f, 600, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

		*/
	}

    return 0;

}
