#pragma once
#include "Shape.h"
#include "BaseGame.h"

using namespace baseEngine;

class Game : public BaseGame
{
private:
	Shape* triangle;
	const char* windowName;

public:
	float width;
	float height;

	Game(float width, float height, const char* windowName);
	~Game();
	void init() override;
	void update() override;
	void exit() override;
};