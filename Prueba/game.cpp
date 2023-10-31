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
	position = Vector3{ width / 2,height / 2,0 };
	scale = Vector3{ 200,200,1 };
	rotation = Vector3{ 0,0,0 };

	const char* path = "res/Test_Sprite.png";
	testTexture = new Sprite(path, 200, 200, colorTest, GetRenderer(), position, scale, rotation);

	testTexture->setScale(Vector3{ 400,400,1 });

	walkRightAnimation = new Animation();
	walkRightAnimation->AddFrame(64, 64 * 10, 64, 64, 832, 1344, 1000, 8);

	testTexture->SetAnimation(walkRightAnimation);
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