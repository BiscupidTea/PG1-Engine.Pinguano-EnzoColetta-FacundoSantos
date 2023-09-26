#include "game.h"
#include <iostream>

using namespace std;

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
	colorTriangle = Vector4{ 1.0f, 0.5f, 0.0f, 1 };
	Vector4 colorTriangle2 = Vector4{ 1.0f, 0.0f, 0.5f, 1 };
	position = Vector3{ width / 2, height,0 };
	scale = Vector3{ 1,1,1 };
	rotation = Vector3{ 0,0,0 };

	Vector3	scale2 = Vector3{ 50,50,50 };

	Vector3 position2 = Vector3{ width - scale2.x, height /2,0 };

	triangle = new Shape(Shape::typeShapes::Triangle, colorTriangle, GetRenderer(), position, scale, rotation);
	Aimy = new Shape(Shape::typeShapes::Triangle, colorTriangle2, GetRenderer(), position2, scale2, rotation);
}

void Game::update()
{
	triangle->setPosition(Vector3{ triangle->getPosition().x, triangle->getPosition().y - 1.0f,0 });
	Vector3 scale = triangle->getScale();

	triangle->setScale({triangle->getScale().x + 1.f , triangle->getScale().y + 1.f ,1.f });

	triangle->Draw();
	Aimy->Draw();
}

void Game::exit()
{
	delete triangle;
	delete Aimy;
}