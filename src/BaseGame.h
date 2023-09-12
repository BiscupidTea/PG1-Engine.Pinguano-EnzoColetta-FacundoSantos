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

		/// <summary>
		/// Initialize the engine.
		/// </summary>
		/// <returns>If the engine is on or off</returns>
		void initEngine(int width, int height, const char* windowName);
		/// <summary>
		/// Core loop of the engine.
		/// </summary>
		void updateEngine();
		/// <summary>
		/// Close engine.
		/// </summary>
		void closeEngine();
	};
}