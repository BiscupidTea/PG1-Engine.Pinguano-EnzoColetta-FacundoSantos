#pragma once
#include "Tools/dll-Exp-Inp.h"
#include "Entity/Shape.h"
#include "CoreEngine/Window.h"
#include "InputSystem.h"
#include "Shader.h"
#include "CoreEngine/Renderer.h"
#include "Tools/ErrorLog.h"

using namespace shape;
using namespace window;
using namespace renderer;
using namespace shader;
using namespace errorLog;

namespace baseEngine
{
	/// <summary>
	/// Class BaseGame
	/// </summary>
	class EXPORT BaseGame
	{
	private:

		Renderer* renderer;
		Window* window;
		ErrorLog errorLog;

	public:

		InputSystem* inputSystem;
		BaseGame(int width, int height, const char* windowName);
		~BaseGame();
		void gameLoop();
		virtual void init() = 0;
		virtual void update() = 0;
		virtual void exit() = 0;
		Renderer* GetRenderer();
	};
}