#include "Entity2D.h"

namespace Entity2D
{
	void Entity2D::setColor(Vector4 rgba)
	{
		color = rgba;
	}

	Vector4 Entity2D::getColor()
	{
		return color;
	}
}
