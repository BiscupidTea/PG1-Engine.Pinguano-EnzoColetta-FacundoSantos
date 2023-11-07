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
	//Init Shape
	ShaperColor = Vector4{ 0.5f, 0.0f, 0.5f, 1 };;
	ShapePosition = Vector3{ width / 2,height / 2, 0 };
	ShaperScale = Vector3{ 64,64,1 };;
	ShapeRotation = Vector3{ 0,0,0 };;


	//Init Texture
	TextureColor = Vector4{ 1.0f, 1.0f, 1.0f, 1 };
	TexturePosition = Vector3{ width / 4,height / 4,0 };
	TextureScale = Vector3{ 64,64,1 };
	TextureRotation = Vector3{ 0,0,0 };

	const char* path = "res/pingu.png";
	testTexture2 = new Sprite(path, 64, 64, TextureColor, GetRenderer(), ShapePosition, TextureScale, TextureRotation);

	path = "res/Test_Sprite.png";
	testTexture = new Sprite(path, 64, 64, TextureColor, GetRenderer(), ShapePosition, ShaperScale, ShapeRotation);

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

	//Idle Animation
	idleAnimation = new Animation();
	idleAnimation->AddFrame(64, 64 * 14, 64, 64, 832, 1344, 1000, 7);

	testTexture->SetAnimation(walkDownAnimation);
}

void Game::update()
{
	if (!CollisionManager::CheckCollisionRecRec(testTexture, testTexture2))
	{
		lastTexturePos = testTexture->getPosition();
	}

	testTexture->SetAnimation(idleAnimation);
	testTexture2->SetAnimation(idleAnimation);

	//Inputs
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

	//Collider
	if (CollisionManager::CheckCollisionRecRec(testTexture, testTexture2))
	{
		testTexture->setPosition(lastTexturePos);
	}


	testTexture->Update();
	testTexture2->Update();
	testTexture->Draw();
	testTexture2->Draw();
}

void Game::exit()
{
	delete testTexture;
	delete testTexture2;

	delete idleAnimation;
	delete walkRightAnimation;
	delete walkLeftAnimation;
	delete walkUpAnimation;
	delete walkDownAnimation;
	delete rotationLeftAnimation;
	delete rotationRightAnimation;
}