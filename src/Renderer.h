#include <GLFW/glfw3.h>
#pragma once

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
	};
}