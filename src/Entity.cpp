#include "Entity.h"

namespace Entity
{
	Entity::Entity(Renderer* render)
	{
		this->render = render;
	}

	Entity::~Entity()
	{

	}

	Vector3 Entity::getPosition()
	{
		return position;
	}

	void Entity::setPosition(Vector3 position)
	{
		this->position.x = position.x;
		this->position.y = position.y;
		this->position.z = position.z;
	}

	Vector3 Entity::getScale()
	{
		return scale;
	}

	void Entity::setScale(Vector3 scale)
	{
		this->scale.x = scale.x;
		this->scale.y = scale.y;
		this->scale.z = scale.z;
	}

	Vector4 Entity::getRotation()
	{
		return rotation;
	}

	void Entity::setRotation(Vector4 rotarion)
	{
		this->rotation.x = rotarion.x;
		this->rotation.y = rotarion.y;
		this->rotation.z = rotarion.z;
		this->rotation.w = rotarion.w;
	}
}