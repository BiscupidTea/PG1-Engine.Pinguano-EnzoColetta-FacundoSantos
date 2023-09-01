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

	void Renderer::RenderScreen(Window window, Shape shape, int shaderProgram)
	{
		/* Render here */
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		clear();

		//Separate in functions
		//***********************************************************************
		glUseProgram(shaderProgram);
		shape.bindVertexAndBuffer();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		//***********************************************************************

		/* Swap front and back buffers */
		swapBuffers(window.getWindow());

		/* Poll for and process events */
		pollEvents();
	}
}