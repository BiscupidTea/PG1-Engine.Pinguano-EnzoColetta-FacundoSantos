#pragma once
#include "Tools/dll-Exp-Inp.h"
#include "Tools/Vectors.h"
#include "CoreEngine/Renderer.h"

using namespace vectors;
using namespace renderer;

namespace Entity
{
	class EXPORT Entity
	{
	protected:
		Renderer* render;
		glm::mat4x4 model;
		glm::mat4 position;
		glm::mat4 scale;
		glm::mat4 rotation;

		Vector3 newPosition;
		Vector3 newScale;
		Vector3 newRotation;

	public:

		Entity(Renderer* render, Vector3 newPosition, Vector3 newScale, Vector3 newRotation);
		~Entity();

		void setPosition(Vector3 newPosition);
		Vector3 getPosition();

		Vector3 getScale();
		void setScale(Vector3 newScale);

		void setRotationX(float newRotationX);
		void setRotationY(float newRotationY);
		void setRotationZ(float newRotationZ);

		void UpdateTMatrix();
	};
}