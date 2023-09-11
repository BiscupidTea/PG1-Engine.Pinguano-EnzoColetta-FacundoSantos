#include "Shape.h"
#include "Window.h"
#include "ErrorLog/ErrorLog.h"
#include <GLFW/glfw3.h>
#pragma once

using namespace window;
using namespace shape;
using namespace errorLog;

namespace renderer
{
	/// <summary>
	/// Class Renderer
	/// </summary>
	class Renderer
	{
		private:

			ErrorLog errorLog;

		public:

		/// <summary>
		/// Clear screen
		/// </summary>
		void clear();
		/// <summary>
		/// Swap the front and back buffer of the specified window.
		/// </summary>
		/// <param name="window">Screen reference</param>
		void swapBuffers(GLFWwindow* window);
		/// <summary>
		/// Processes all pending events.
		/// </summary>
		void pollEvents();
		/// <summary>
		/// render screen
		/// </summary>
		/// <param name="window"></param>
		/// <param name="shape"></param>
		/// <param name="haderProgram"></param>
		void RenderScreen(Window window, Shape shape, int shaderProgram);
	};
}