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
	colorTriangle = Vector4{ 1.0f, 0.0f, 0.0f, 1 };
	position = Vector3{ 0,0,0 };
	scale = Vector3{ 200,200,1 };
	rotation = Vector3{ 0,0,0 };
	triangle = new Shape(Shape::typeShapes::Triangle, colorTriangle, GetRenderer(), position, scale, rotation);
}

void Game::update()
{
	position = { position.x + width/10000, position.y + height/10000, position.z };

	triangle->setPosition(position);
	triangle->setRotationZ(rotation.z + 1);

	triangle->Draw();
}

void Game::exit()
{
	delete triangle;
}