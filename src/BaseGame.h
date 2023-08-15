#pragma once

#include "Window.h"
#include "Renderer.h"

using namespace window;
using namespace renderer;

namespace baseEngine
{
	class BaseGame
	{
		private:

		Window window;
		Renderer renderer;

		public:

		int initEngine();
		void updateEngine();
		void closeEngine();
	};
}