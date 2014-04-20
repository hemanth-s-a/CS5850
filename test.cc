#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include <GLFW\glfw3.h>

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

void game_loop(GLFWwindow* window) {
	double new_time;
	int width, height;
	int frame = 1;
	double game_time = glfwGetTime();
	//eggs_caught = eggs_missed = 0;
	//basket = ratio/(float)2;
	
	while (true) {
		new_time = glfwGetTime();
		if((new_time - game_time) >= 0.02) {
			game_time = new_time;
			
			glClear(GL_COLOR_BUFFER_BIT);
			glLoadIdentity();
			//cout<<"Drawing";
			//printf ("Drawing\n");
			//world->draw();
			//cout<<"Drawn";
			//printf ("Drawn\n");
			//render_everything(frame++);
			
			glBegin (GL_LINES);
			glVertex2i (10, 20);
			glVertex2i (30, 30);
			glEnd ();
			//draw_basket(window);
			//handle_eggs();
			
			//win_lose(window);
			
			//getch ();

			glfwSwapBuffers(window);
			//glfwPollEvents();
		}
	}
}

int main()
{
	
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
	glfwSetWindowSizeCallback(window, resize_callback);
	glfwSetWindowCloseCallback(window, close_callback);
	glfwSetKeyCallback(window, key_callback);
	
	while(true) {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.f, 800, 0.f, 600, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		//glfwSetMouseButtonCallback(window, mouse_callback);
		
		//draw_first_screen(window);
		
		//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		srand(time(NULL));
		
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		resize_callback(window, width, height);
		
		//egg_drop_time = game_time = glfwGetTime();
		game_loop(window);
		
		/*glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.f, 800, 0.f, 600, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		
		draw_win_lose(window);*/
	}
	
    return 0;

}
