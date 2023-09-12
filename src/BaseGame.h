#pragma once

#include "Shape.h"
#include "Window.h"
#include "Renderer.h"
#include "Shader.h"
#include "ErrorLog.h"

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
	class BaseGame
	{
	private:

		Window window;
		Renderer renderer;
		Shape shape;
		Shader shader;
		ErrorLog errorLog;

	public:

		BaseGame(int width, int height, const char* windowName);
		~BaseGame();
		/// <summary>
		/// Core loop of the engine.
		/// </summary>
		void updateEngine();
	};
}