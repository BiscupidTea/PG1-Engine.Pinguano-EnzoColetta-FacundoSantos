#include "Entity2D.h"

namespace Entity2D
{
	Entity2D::Entity2D(Vector4 rgba, Renderer* render, Vector3 newPosition, Vector3 newScale, Vector3 newRotation) : Entity(render, newPosition, newScale, newRotation)
	{
		this->color = rgba;
	}

	Entity2D::~Entity2D()
	{
		render->deleteVertexAndBuffer(VAO, VBO, EBO);
	}

	void Entity2D::setColor(Vector4 rgba)
	{
		color = rgba;
	}

	Vector4 Entity2D::getColor()
	{
		return color;
	}

	void Entity2D::Draw()
	{
		render->Draw2DEntity(VAO, indexSize, color, model);
	}
}
