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

	//Walk Down Animation
	walkDownAnimation = new Animation();
	walkDownAnimation->AddFrame(64, 64 * 10, 64, 64, 832, 1344, 1000, 8);

	//Walk Right Animation
	walkRightAnimation = new Animation();
	walkRightAnimation->AddFrame(64, 64 * 9, 64, 64, 832, 1344, 1000, 8);

	//Walk Left Animation
	walkLeftAnimation = new Animation();
	walkLeftAnimation->AddFrame(64, 64 * 11, 64, 64, 832, 1344, 1000, 8);

	//Walk Up Animation
	walkUpAnimation = new Animation();
	walkUpAnimation->AddFrame(64, 64 * 12, 64, 64, 832, 1344, 1000, 8);

	//Rotation Left Animation
	rotationRightAnimation = new Animation();
	rotationRightAnimation->AddFrame(64, 64 * 13, 64, 64, 832, 1344, 1000, 7);

	//Rotation Left Animation
	rotationLeftAnimation = new Animation();
	rotationLeftAnimation->AddFrame(64, 64 * 15, 64, 64, 832, 1344, 1000, 7);
	
	//Walk Down Animation
	idleAnimation = new Animation();
	idleAnimation->AddFrame(64, 64 * 14, 64, 64, 832, 1344, 1000, 7);

	testTexture->SetAnimation(walkDownAnimation);
}

void Game::update()
{
	testTexture->SetAnimation(idleAnimation);

	if (inputSystem->getKey(inputSystem->q, inputSystem->Pressed))
	{
		testTexture->SetAnimation(rotationLeftAnimation);
		testTexture->setRotationZ(-1);
	}

	if (inputSystem->getKey(inputSystem->e, inputSystem->Pressed))
	{
		testTexture->SetAnimation(rotationRightAnimation);
		testTexture->setRotationZ(1);
	}

	if (inputSystem->getKey(inputSystem->s, inputSystem->Pressed))
	{
		testTexture->SetAnimation(walkDownAnimation);
		testTexture->setPosition(Vector3{ testTexture->getPosition().x, testTexture->getPosition().y - 1.0f,0 });
	}

	if (inputSystem->getKey(inputSystem->w, inputSystem->Pressed))
	{
		testTexture->SetAnimation(walkUpAnimation);
		testTexture->setPosition(Vector3{ testTexture->getPosition().x, testTexture->getPosition().y + 1.0f,0 });
	}

	if (inputSystem->getKey(inputSystem->a, inputSystem->Pressed))
	{
		testTexture->SetAnimation(walkLeftAnimation);
		testTexture->setPosition(Vector3{ testTexture->getPosition().x - 1.0f, testTexture->getPosition().y ,0 });
	}

	if (inputSystem->getKey(inputSystem->d, inputSystem->Pressed))
	{
		testTexture->SetAnimation(walkRightAnimation);
		testTexture->setPosition(Vector3{ testTexture->getPosition().x + 1.0f, testTexture->getPosition().y ,0 });
	}

	testTexture->Update();
	testTexture->Draw();
}

void Game::exit()
{
	delete testTexture;
	delete idleAnimation;
	delete walkRightAnimation;
	delete walkLeftAnimation;
	delete walkUpAnimation;
	delete walkDownAnimation;
	delete rotationLeftAnimation;
	delete rotationRightAnimation;
}