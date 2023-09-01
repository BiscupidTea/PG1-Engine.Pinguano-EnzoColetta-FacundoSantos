#include "Shape.h"
#include <GLFW/glfw3.h>
#pragma once

#include "Window.h"

using namespace window;
using namespace shape;

namespace renderer
{
	/// <summary>
	/// Class Renderer
	/// </summary>
	class Renderer
	{
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