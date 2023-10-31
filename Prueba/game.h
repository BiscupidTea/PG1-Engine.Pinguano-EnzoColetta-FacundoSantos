#pragma once
#include "CoreEngine/BaseGame.h"

using namespace baseEngine;

class Game : public BaseGame
{
private:
	const char* windowName;
	Sprite* testTexture;

	Vector4 colorTest;
	Vector3 position;
	Vector3 scale;
	Vector3 rotation;

	Animation* walkRightAnimation;
	Animation* walkLeftAnimation;
	Animation* walkUpAnimation;
	Animation* walkDownAnimation;

public:
	float width;
	float height;

	Game(float width, float height, const char* windowName);
	~Game();
	void init() override;
	void update() override;
	void exit() override;
};