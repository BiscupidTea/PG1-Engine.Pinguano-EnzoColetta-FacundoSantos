#include "Renderer.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) errorLog.GLClearError();\
				x;\
				ASSERT(errorLog.GLLogCall(#x, __FILE__, __LINE__))

namespace renderer
{
	void Renderer::clearScreen()
	{
		GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	void Renderer::swapBuffers(GLFWwindow* window)
	{
		GLCall(glfwSwapBuffers(window));
	}

	void Renderer::pollEvents()
	{
		GLCall(glfwPollEvents());
	}

	void Renderer::RenderScreen(Window window, Shape shape, int shaderProgram)
	{
		clearScreen();

		//Separate in functions
		//***********************************************************************
		GLCall(glUseProgram(shaderProgram));
		shape.bindVertexAndBuffer();
		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
		//***********************************************************************

		/* Swap front and back buffers */
		swapBuffers(window.getWindow());

		/* Poll for and process events */
		pollEvents();
	}
}