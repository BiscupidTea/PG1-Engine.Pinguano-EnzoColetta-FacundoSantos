#pragma once
#include "Entity/Entity2D.h"

using namespace Entity2D;

namespace collisionManager
{
	class EXPORT CollisionManager : public Entity2D
	{
		public:

			static bool CheckCollisionRecRec(Entity2D* entityOne, Entity2D* entityTwo);
	};
}