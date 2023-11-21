#include <iostream>
#include "CoreEngine/BaseGame.h"

using namespace std;

namespace baseEngine
{
	BaseGame::BaseGame(int width, int height, const char* windowName)
	{
		errorLog.CheckGlfwInit();

		window = new Window(width, height, windowName, NULL, NULL);

		errorLog.CheckGlewInit();

		renderer = new Renderer(window);

		inputSystem = new InputSystem(window->getWindow());
	}

	BaseGame::~BaseGame()
	{
		delete window;
		delete renderer;
	}

	void BaseGame::gameLoop()
	{
		while (!glfwWindowShouldClose(window->getWindow()))
		{
			Time::Update(glfwGetTime());
			renderer->StartDraw();
			update();
			renderer->EndDraw();
		}
	}

	Renderer* BaseGame::GetRenderer()
	{
		return renderer;
	}
}