#pragma once
#include "Shape.h"
#include "BaseGame.h"

using namespace baseEngine;

class Game : public BaseGame
{
private:
	Shape* triangle;
	const char* windowName;
	Vector4 colorTriangle;
	Vector3 position;
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