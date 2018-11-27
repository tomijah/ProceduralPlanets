#include "pch.h"
#include "Display.h"

Display::Display(const char* title, int width, int height)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	glewExperimental = true;
	glewInit();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_STENCIL_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//antialiasing
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0, 0, 800, 600);
	glfwSwapInterval(1);
}


Display::~Display()
{
	glfwDestroyWindow(window);
}

bool Display::ShouldClose()
{
	return !!glfwWindowShouldClose(window);
}

void Display::SwapBuffers()
{
	glfwSwapBuffers(window);
}

void Display::PollEvents()
{
	glfwPollEvents();
}
