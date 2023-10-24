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

	const char* path = "res/Penguin_Walk_Left.png";
	testTexture = new Sprite(path, 200, 200, colorTest, GetRenderer(), position, scale, rotation);
	
	walkAnimation = new Animation(0,0,133,141,1200,141,10);

	testTexture->SetAnimation(walkAnimation);
}

void Game::update()
{

	if (inputSystem->getKey(inputSystem->q, inputSystem->Pressed))
	{
		testTexture->setRotationZ(1);
	}

	if (inputSystem->getKey(inputSystem->e, inputSystem->Pressed))
	{
		testTexture->setRotationZ(-1);
	}

	if (inputSystem->getKey(inputSystem->s, inputSystem->Pressed))
	{
		testTexture->setPosition(Vector3{ testTexture->getPosition().x, testTexture->getPosition().y - 1.0f,0 });
	}

	if (inputSystem->getKey(inputSystem->w, inputSystem->Pressed))
	{
		testTexture->setPosition(Vector3{ testTexture->getPosition().x, testTexture->getPosition().y + 1.0f,0 });
	}

	if (inputSystem->getKey(inputSystem->a, inputSystem->Pressed))
	{
		testTexture->setPosition(Vector3{ testTexture->getPosition().x - 1.0f, testTexture->getPosition().y ,0 });
	}

	if (inputSystem->getKey(inputSystem->d, inputSystem->Pressed))
	{
		testTexture->setPosition(Vector3{ testTexture->getPosition().x + 1.0f, testTexture->getPosition().y ,0 });
	}

	testTexture->Update();
	testTexture->Draw();
}

void Game::exit()
{
	delete testTexture;
}