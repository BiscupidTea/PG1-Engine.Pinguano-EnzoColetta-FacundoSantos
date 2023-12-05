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
	//Triangle 1
	colorTriangleFront = Vector4{ 1.0f, 1.0f, 0.0f, 1 };
	colorTriangleBack = Vector4{ 1.0f, 1.0f, 0.0f, 1 };
	position = Vector3{ width / 2, height / 2,-50 };
	scale = Vector3{ 60.0f, 60.0f,60.0f };
	rotation = Vector3{ 0,0,0 };
	triangle1 = new Shape(Shape::typeShapes::Triangle, colorTriangleFront, GetRenderer(), position, scale, rotation);

	//Triangle 2
	position2 = Vector3{ width / 2.21f, height / 2.65f, -50 };
	triangle2 = new Shape(Shape::typeShapes::Triangle, colorTriangleFront, GetRenderer(), position2, scale, rotation);

	//Triangle 3
	position3 = Vector3{ width / 1.83f, height / 2.65f, -50 };
	triangle3 = new Shape(Shape::typeShapes::Triangle, colorTriangleFront, GetRenderer(), position3, scale, rotation);
}

void Game::update()
{
	triangle1->setRotationY(1);
	triangle2->setRotationY(1);
	triangle3->setRotationY(1);

	triangle1->Draw();
	triangle2->Draw();
	triangle3->Draw();
}

void Game::exit()
{
	delete triangle1;
	delete triangle2;
	delete triangle3;
}