#pragma once
#include "CoreEngine/BaseGame.h"

using namespace baseEngine;

class Game : public BaseGame
{
private:
	const char* windowName;
	Shape* triangle1;
	Shape* triangle2;
	Shape* triangle3;
	
	Vector4 colorTriangleFront;
	Vector4 colorTriangleBack;

	Vector3 position;
	Vector3 position2;
	Vector3 position3;

	Vector3 scale;
	Vector3 rotation;

public:
	float width;
	float height;

	Game(float width, float height, const char* windowName);
	~Game();
	void init() override;
	void update() override;
	void exit() override;
};