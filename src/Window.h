#pragma once
#include <GLFW/glfw3.h>

namespace window
{
	class Window
	{
	private:

		GLFWwindow* window;

	public:

		void initWindow(int width, int height, const char* windowName, GLFWmonitor* monitor, GLFWwindow* share);
		void closeWindow();
		bool windowShouldClose(GLFWwindow* window);
		GLFWwindow* getWindow();

	};
}

