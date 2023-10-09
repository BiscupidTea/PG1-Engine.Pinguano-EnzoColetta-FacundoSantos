#include <iostream>
#include "BaseGame.h"

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
}