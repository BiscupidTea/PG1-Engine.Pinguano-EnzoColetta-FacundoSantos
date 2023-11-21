#pragma once
#include "CoreEngine/BaseGame.h"

using namespace baseEngine;

class Game : public BaseGame
{
private:
	const char* windowName;
	Sprite* Sonic;
	Sprite* Cartel;
	Sprite* Fondo;

	Vector3 lastTexturePos;

	Vector4 TextureColor;
	Vector3 TexturePosition;
	Vector3 TextureScale;
	Vector3 TextureRotation;

	Vector4 TextureColor2;
	Vector3 TexturePosition2;

	Animation* idleAnimation;
	Animation* walkAnimation;

	Animation* idleAnimationCartel;

public:
	float width;
	float height;

	Game(float width, float height, const char* windowName);
	~Game();
	void init() override;
	void update() override;
	void exit() override;
};