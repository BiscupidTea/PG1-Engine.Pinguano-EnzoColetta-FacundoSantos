#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace errorLog
{
	class ErrorLog
	{
		public:

		int CheckGlfwInit();
		void CheckGlewInit();
		static void GLClearError();
		static bool GLLogCall(const char* function, const char* file, int line);
	};
}