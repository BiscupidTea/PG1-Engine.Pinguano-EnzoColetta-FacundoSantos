#include "Entity.h"

namespace Entity
{
	Entity::Entity(Renderer* render, Vector3 newPosition, Vector3 newScale, Vector3 newRotation)
	{
		this->render = render;

		model = glm::mat4(1);
		position = glm::mat4(1);
		scale = glm::mat4(1);
		rotation = glm::mat4(1);

		setPosition(newPosition);

		setRotationX(0);
		setRotationY(0);
		setRotationZ(0);
		setScale({1,1,1});

		setRotationX(newRotation.x);
		setRotationY(newRotation.y);
		setRotationZ(newRotation.z);
		setScale(newScale);

		UpdateTMatrix();
	}

	Entity::~Entity()
	{

	}

	void Entity::setPosition(Vector3 newPosition)
	{
		vec3 newPositionSet = { newPosition.x, newPosition.y, newPosition.z };
		position = translate(position, newPositionSet);
		UpdateTMatrix();
	}

	Vector3 Entity::getPosition()
	{
		return { position[0][3], position[1][3], position[2][3] };
	}

	void Entity::setScale(Vector3 newScale)
	{
		scale = glm::scale(scale, glm::vec3(newScale.x, newScale.y, scale[2][2]));
		UpdateTMatrix();
	}

	Vector3 Entity::getScale()
	{
		return { scale[0][0], scale[1][1], scale[2][2] };
	}

	void Entity::setRotationX(float newRotationX)
	{
		rotation = glm::rotate(rotation, glm::radians(newRotationX), glm::vec3(1, 0, 0));
		UpdateTMatrix();
	}

	void Entity::setRotationY(float newRotationY)
	{
		rotation = glm::rotate(rotation, glm::radians(newRotationY), glm::vec3(0, 1, 0));
		UpdateTMatrix();
	}

	void Entity::setRotationZ(float newRotationZ)
	{
		rotation = glm::rotate(rotation, glm::radians(newRotationZ), glm::vec3(0, 0, 1));
		UpdateTMatrix();
	}

	void Entity::UpdateTMatrix()
	{
		model = position * rotation * scale;
	}
}