#pragma once
#include "Shape.h"
#include "BaseGame.h"

using namespace baseEngine;

class Game : public BaseGame
{
private:
	Shape* triangle;
	Shape* Aimy;
	const char* windowName;

public:
	float width;
	float height;
	Vector4 colorTriangle;
	Vector3 position;
	Vector3 scale;
	Vector3 rotation;

	Game(float width, float height, const char* windowName);
	~Game();
	void init() override;
	void update() override;
	void exit() override;
};