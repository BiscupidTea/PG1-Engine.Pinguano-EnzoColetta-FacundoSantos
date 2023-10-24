#pragma once
#include "CoreEngine/Renderer.h"
#include "Entity/Entity2D.h"

using namespace Entity2D;

namespace sprite
{
	class EXPORT Sprite : public Entity2D
	{
	private:
		int width;
		int height;

	public:
		Sprite(const char* textureName, int width, int height, Vector4 rgba, Renderer* render, Vector3 newPosition, Vector3 newScale, Vector3 newRotation);
		~Sprite();

		void CreateSprite();
		void Draw();
	};
}