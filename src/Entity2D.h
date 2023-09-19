#pragma once
#include "Entity.h"

using namespace Entity;

namespace Entity2D
{
	class Entity2D : public Entity
	{
	private:
		Vector4 color;
	public:
		void setColor(Vector4 rgba);
		Vector4 getColor();
	};
}

