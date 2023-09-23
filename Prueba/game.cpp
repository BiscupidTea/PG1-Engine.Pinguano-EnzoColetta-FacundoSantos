#include "game.h"

Game::Game(int width,int height, const char* windowName) : BaseGame(width, height, windowName)
{
	init();
}

Game::~Game()
{
	exit();
}

void Game::init()
{
	Vector4 colorTriangle = Vector4{ 1.0f, 0.4f, 0.4f, 1 };
	triangle = new Shape(Shape::typeShapes::Triangle, colorTriangle, GetRenderer());
}

void Game::update()
{
	triangle->Draw();
}

void Game::exit()
{
	delete triangle;
}