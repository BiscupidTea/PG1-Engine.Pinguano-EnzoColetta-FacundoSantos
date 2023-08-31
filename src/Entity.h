#pragma once
#include "Vectors.h"

using namespace vectors;

namespace Entity
{
	class Entity
	{
		protected:

		Vector3 position;
		Vector3 scale;
		Vector4 rotation;

		public:

		Vector3 getPosition();
		void setPosition(Vector3 position);

		Vector3 getScale();
		void setScale(Vector3 scale);

		Vector4 getRotation();
		void setRotation(Vector4 rotarion);
	};
}