#include <iostream>
#include "Window.h"

using namespace std;

namespace window
{
	void Window::initWindow(int width, int height, const char* windowName, GLFWmonitor* monitor, GLFWwindow* share)
	{
		window = glfwCreateWindow(width, height, windowName, monitor, share);

		if (!window)
		{
			cout << "Failed to create window" << endl;
			closeWindow();
		}

		glfwMakeContextCurrent(window);
	}

	void Window::closeWindow()
	{
		glfwTerminate();
	}

	bool Window::windowShouldClose(GLFWwindow* window)
	{
		return glfwWindowShouldClose(window);
	}

	GLFWwindow* Window::getWindow()
	{
		return window;
	}
}
