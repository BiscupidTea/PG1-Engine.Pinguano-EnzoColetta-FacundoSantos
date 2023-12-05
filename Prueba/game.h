#pragma once
#include "CoreEngine/BaseGame.h"

using namespace baseEngine;

class Game : public BaseGame
{
private:
	const char* windowName;
	Sprite* Sonic;
	Sprite* Pikachu;
	Sprite* Cartel;
	Sprite* Fondo;
	Sprite* Logo;
	Sprite* Credits;

	Vector3 lastTexturePos;
	Vector3 lastTexturePosP;

	Vector4 TextureColor;
	Vector3 TexturePosition;
	Vector3 TextureScale;
	Vector3 TextureRotation;

	Vector4 TextureColor2;
	Vector3 TexturePosition2;

	Animation* idleAnimationSonic;
	Animation* walkAnimationSonic;

	Animation* idleAnimationPikachu;
	Animation* walkAnimationPikachu;

	Animation* idleAnimationCartel;
	Animation* idleAnimationLogo;
	Animation* idleAnimationCreditos;

public:
	float width;
	float height;

	Game(float width, float height, const char* windowName);
	~Game();
	void init() override;
	void update() override;
	void exit() override;
};