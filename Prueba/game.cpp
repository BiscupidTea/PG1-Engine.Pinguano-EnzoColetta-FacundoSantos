#include "game.h"

Game::Game(float width, float height, const char* windowName) : BaseGame(width, height, windowName)
{
	this->width = width;
	this->height = height;

	init();
}

Game::~Game()
{
	exit();
}

void Game::init()
{
	Vector4 colorTriangle = Vector4{ 1.0f, 0.4f, 0.4f, 1 };
	Vector3 position = Vector3{ width/2,height/2,0 };
	Vector3 scale = Vector3{ 200,200,1 };
	Vector3 rotation = Vector3{ 0,0,0 };
	triangle = new Shape(Shape::typeShapes::Square, colorTriangle, GetRenderer(), position, scale, rotation);
	triangle->setRotationZ(90);
}

void Game::update()
{
	triangle->Draw();
}

void Game::exit()
{
	delete triangle;
}