#pragma once
#include "Includes.h"

class Display
{
public:
	Display(const char* title, int width, int height);
	~Display();
	bool ShouldClose();
	void SwapBuffers();
	void PollEvents();
private:
	GLFWwindow* window;
};