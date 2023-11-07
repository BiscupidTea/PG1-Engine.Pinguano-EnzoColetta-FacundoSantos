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
	ShapePosition = Vector3{ width / 4,height / 4,0 };
	ShaperScale = Vector3{ 100,100,1 };;
	ShapeRotation = Vector3{ 0,0,0 };;

	square = new Shape(Shape::Square, ShaperColor, GetRenderer(), ShapePosition, ShaperScale, ShapeRotation);

	//Init Texture
	TextureColor = Vector4{ 1.0f, 1.0f, 1.0f, 1 };
	TexturePosition = Vector3{ width / 2,height / 2,0 };
	TextureScale = Vector3{ 200,200,1 };
	TextureRotation = Vector3{ 0,0,0 };

	const char* path = "res/Test_Sprite.png";
	testTexture = new Sprite(path, 200, 200, TextureColor, GetRenderer(), TexturePosition, TextureScale, TextureRotation);

	testTexture->setScale(Vector3{ 200,200,1 });

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
	testTexture->SetAnimation(idleAnimation);

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
	if (CollisionManager::CheckCollisionRecRec(square, testTexture))
	{
		cout << "Colision" << endl;
	}
	
	square->Draw();

	testTexture->Update();
	testTexture->Draw();
}

void Game::exit()
{
	delete square;

	delete testTexture;

	delete idleAnimation;
	delete walkRightAnimation;
	delete walkLeftAnimation;
	delete walkUpAnimation;
	delete walkDownAnimation;
	delete rotationLeftAnimation;
	delete rotationRightAnimation;
}