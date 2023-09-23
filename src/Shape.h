#pragma once
#include "dll-Exp-Inp.h"
#include <GL/glew.h>
#include "Entity2D.h"

using namespace Entity2D;

namespace shape
{
	class EXPORT Shape final : public Entity2D
	{
	private:

	public:

		enum typeShapes
		{
			Triangle,
			Square,
		};

		Shape(typeShapes typeShapes, Vector4 color, Renderer* render);
		~Shape();
		void createTriangle();
		void createRectangle();
	};
}