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
	colorTest = Vector4{ 1.0f, 1.0f, 1.0f, 1 };
	position = Vector3{ width/2,height/2,0 };
	scale = Vector3{ 200,200,1 };
	rotation = Vector3{ 0,0,0 };

	const char* path = "res/pingu.png";
	testTexture = new Texture(path, 200, 200, colorTest, GetRenderer(), position, scale, rotation);

	triangle = new Shape(Shape::typeShapes::Square, colorTest, GetRenderer(), position, scale, rotation);
}

void Game::update()
{

	if (inputSystem->getKey(inputSystem->a, inputSystem->Pressed))
	{
		testTexture->setRotationZ(1);
	}

	if (inputSystem->getKey(inputSystem->d, inputSystem->Pressed))
	{
		testTexture->setRotationZ(-1);
	}

	if (inputSystem->getKey(inputSystem->g, inputSystem->Pressed))
	{
		triangle->setRotationZ(1);
	}

	if (inputSystem->getKey(inputSystem->j, inputSystem->Pressed))
	{
		triangle->setRotationZ(-1);
	}

	testTexture->Draw();
	//triangle->Draw();
}

void Game::exit()
{
	delete triangle;
}