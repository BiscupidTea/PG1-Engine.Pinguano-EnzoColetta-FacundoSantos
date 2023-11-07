#pragma once
#include "CoreEngine/BaseGame.h"

using namespace baseEngine;

class Game : public BaseGame
{
private:
	const char* windowName;
	Shape* square;
	Sprite* testTexture;

	Vector3 lastTexturePos;

	Vector4 ShaperColor;
	Vector3 ShapePosition;
	Vector3 ShaperScale;
	Vector3 ShapeRotation;

	Vector4 TextureColor;
	Vector3 TexturePosition;
	Vector3 TextureScale;
	Vector3 TextureRotation;

	Animation* idleAnimation;
	Animation* walkRightAnimation;
	Animation* walkLeftAnimation;
	Animation* walkUpAnimation;
	Animation* walkDownAnimation;
	Animation* rotationLeftAnimation;
	Animation* rotationRightAnimation;

public:
	float width;
	float height;

	Game(float width, float height, const char* windowName);
	~Game();
	void init() override;
	void update() override;
	void exit() override;
};