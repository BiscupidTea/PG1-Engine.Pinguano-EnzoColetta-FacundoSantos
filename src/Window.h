#pragma once
#include <GLFW/glfw3.h>

namespace window
{
	/// <summary>
	/// Class window.
	/// </summary>
	class Window
	{
		private:

		GLFWwindow* window;

		public:

		/// <summary>
		/// Initialize the window.
		/// </summary>
		/// <param name="width">Screen width</param>
		/// <param name="height">Screen height</param>
		/// <param name="windowName">Window name</param>
		/// <param name="monitor">to change the full screen mode</param>
		/// <param name="share">to share resources</param>
		void initWindow(int width, int height, const char* windowName, GLFWmonitor* monitor, GLFWwindow* share);
		
		/// <summary>
		/// Calls glfwTerminate() funtion to destroy all remaining windows and cursors, reset any modified resources.
		/// </summary>
		void closeWindow();

		/// <summary>
		/// Calls GLFWwindowShouldClose, to check if window close value is true or false. 
		/// </summary>
		/// <param name="window"></param>
		/// <returns></returns>
		bool windowShouldClose(GLFWwindow* window);

		/// <summary>
		/// Get window.
		/// </summary>
		/// <returns></returns>
		GLFWwindow* getWindow();
	};
}

