#pragma once
#include "Shape.h"
#include "BaseGame.h"

using namespace baseEngine;

class Game : public BaseGame
{
private:
	Shape* triangle;
	int width;
	int height;
	const char* windowName;

public:
	Game(int width, int height, const char* windowName);
	~Game();
	void init() override;
	void update() override;
	void exit() override;
};