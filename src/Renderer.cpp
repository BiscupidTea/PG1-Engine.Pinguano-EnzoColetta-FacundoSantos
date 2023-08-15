#include "Renderer.h"

namespace renderer
{
	void Renderer::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Renderer::swapBuffers(GLFWwindow* window)
	{
		glfwSwapBuffers(window);
	}

	void Renderer::pollEvents()
	{
		glfwPollEvents();
	}
}