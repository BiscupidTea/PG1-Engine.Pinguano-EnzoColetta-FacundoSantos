#include "Tools/CollisionManager.h"

namespace collisionManager
{
	bool CollisionManager::CheckCollisionBoxBox(Entity2D& entityOne, Entity2D& entityTwo)
	{
		bool collisionX = entityOne.getPosition().x + entityOne.getScale().x >= entityTwo.getPosition().x &&
						  entityTwo.getPosition().x + entityTwo.getScale().x >= entityOne.getPosition().x;

		bool collisionY = entityOne.getPosition().y + entityOne.getScale().y >= entityTwo.getPosition().y &&
						  entityTwo.getPosition().y + entityTwo.getScale().y >= entityOne.getPosition().y;

		return collisionX && collisionY;
	}
}