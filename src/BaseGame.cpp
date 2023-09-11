#include <iostream>
#include "BaseGame.h"

using namespace std;

namespace baseEngine
{
	void BaseGame::initEngine()
	{
		int width = 640;
		int height = 480;

		const char* windowName = "Pinguano-Engine";

		GLFWmonitor* monitor = NULL;
		GLFWwindow* share = NULL;

		errorLog.CheckGlfwInit();

		window.initWindow(width, height, windowName, monitor, share);

		errorLog.CheckGlewInit();

		shader.initShader("res/Shader/Basic.Shader");
	}

	void BaseGame::updateEngine()
	{

		//Shape
		//***********************************************************************
		shape.initShape();
		//***********************************************************************

		/* Loop until the user closes the window */
		while (!window.windowShouldClose(window.getWindow()))
		{
			renderer.RenderScreen(window, shape, shader.IDshader);
		}

		shape.deleteVertexAndBuffer();
	}

	void BaseGame::closeEngine()
	{
		shader.deleteShader();
		window.closeWindow();
	}
}