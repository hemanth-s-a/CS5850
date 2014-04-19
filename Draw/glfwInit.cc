void resize_callback(GLFWwindow* window, int width, int height) {
	float ratio = width / (float) height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.f, ratio, 0.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
}

void error_callback(int error, const char* description) {
    fputs(description, stderr);
}

void close_callback(GLFWwindow* window) {
	//game_status = NO_STATE;
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(0);
}

void glfwMyInit (GLFWwindow* window) {
	
	if(!glfwInit()) {
		return;
	}
	glfwSetErrorCallback(error_callback);
	window = glfwCreateWindow(800, 600, "Game Loop", NULL, NULL);
	if(!window) {
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);
	glfwSetWindowSizeCallback(window, resize_callback);
	glfwSetWindowCloseCallback(window, close_callback);
	//glfwSetKeyCallback(window, key_callback);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.f, 800.0f, 0.0f, 600, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//glfwSetMouseButtonCallback(window, mouse_callback);
	
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	srand(time(NULL));
	
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	resize_callback(window, width, height);
	
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.f, 800, 0.f, 600, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

}