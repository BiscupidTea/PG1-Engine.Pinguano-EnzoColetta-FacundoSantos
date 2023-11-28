#pragma once
#include "CoreEngine/Renderer.h"
#include "Entity/Entity2D.h"
#include "Entity/Animation.h"

using namespace Entity2D;
using namespace animation;

namespace sprite
{
	class EXPORT Sprite : public Entity2D
	{
	private:
		Animation* animation;

	public:
		Sprite(const char* textureName, Vector4 rgba, Renderer* render, Vector3 newPosition, Vector3 newScale, Vector3 newRotation);
		~Sprite();

		void CreateSprite();
		void Update();
		void Draw();
		void SetAnimation(Animation* animation);
		void SetUV(Frame frame);
	};
}