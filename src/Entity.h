#pragma once
#include "dll-Exp-Inp.h"
#include "Vectors.h"
#include "Renderer.h"

using namespace vectors;
using namespace renderer;

namespace Entity
{
	class EXPORT Entity
	{
	protected:

		Renderer* render;
		Vector3 position;
		Vector3 scale;
		Vector4 rotation;

	public:

		Entity(Renderer* render);
		~Entity();

		Vector3 getPosition();
		void setPosition(Vector3 position);

		Vector3 getScale();
		void setScale(Vector3 scale);

		Vector4 getRotation();
		void setRotation(Vector4 rotarion);
	};
}