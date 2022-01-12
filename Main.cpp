#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {

	// initialize glfw
	glfwInit();

	// tell glfw what version of opengl we are using
	// in this case we are using opengl 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// tell glfw we are using the core profile
	// so that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// create a GLFWwindow object of 1519 by 714 pixels, naming it "OpenGLCourse"
	GLFWwindow* window = glfwCreateWindow(1519, 714, "OpenGLCourse", NULL, NULL);

	// error check if the window fails to create
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	// Load glad so it configures opengl
	gladLoadGL();

	// specify the viewport of opengl in the window
	// in this case the viewport goes from x = 0, y = 0 to x = 1519, y = 714
	glViewport(0, 0, 1519, 714);

	// specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// swap the back buffer with the front buffer
	glfwSwapBuffers(window);

	// main while loop
	while (!glfwWindowShouldClose(window)) {
		// take care of all glfw events
		glfwPollEvents();
	}
	// delete window before ending the program
	glfwDestroyWindow(window);
	// terminate glfw before ending the program
	glfwTerminate();
	return 0;
}