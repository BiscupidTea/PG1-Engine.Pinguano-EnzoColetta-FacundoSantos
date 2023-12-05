#pragma once
#include "Shape.h"
#include "BaseGame.h"

using namespace baseEngine;

class Game : public BaseGame
{
private:
	Shape* triangle1;
	Shape* triangle2;
	Shape* triangle3;
	const char* windowName;

public:
	float width;
	float height;
	Vector4 colorTriangleBack;
	Vector4 colorTriangleFront;
	Vector3 position;
	Vector3 position2;
	Vector3 position3;
	Vector3 scale;
	Vector3 rotation;

	Game(float width, float height, const char* windowName);
	~Game();
	void init() override;
	void update() override;
	void exit() override;
};