#include <iostream>
#include "BaseGame.h"

using namespace std;

namespace baseEngine
{
	BaseGame::BaseGame(int width, int height, const char* windowName)
	{
		GLFWmonitor* monitor = NULL;
		GLFWwindow* share = NULL;

		errorLog.CheckGlfwInit();

		window.initWindow(width, height, windowName, monitor, share);

		errorLog.CheckGlewInit();

		shader.initShader("res/Shader/Basic.Shader");
	}

	BaseGame::~BaseGame()
	{
		shader.deleteShader();
		window.closeWindow();
	}

	void BaseGame::updateEngine()
	{

		//Shape
		//***********************************************************************
		shape.initShape();
		//***********************************************************************

		//Choose the color of the figure
		//***********************************************************************
		shader.color(0.7f, 0.1f, 0.8f, 1.0f);
		//***********************************************************************

		/* Loop until the user closes the window */
		while (!window.windowShouldClose(window.getWindow()))
		{
			renderer.RenderScreen(window, shape, shader.IDshader);
		}

		shape.deleteVertexAndBuffer();
	}
}