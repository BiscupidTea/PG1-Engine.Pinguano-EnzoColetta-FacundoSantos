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
	TextureColor = Vector4{ 1.0f, 1.0f, 1.0f, 1 };
	TexturePosition = Vector3{ width / 2,height / 2, 0 };
	TextureScale = Vector3{ 64,64,1 };;
	TextureRotation = Vector3{ 0,0,0 };;

	const char* path = "res/Sonic_Mania_Sprite_Sheet.png";
	Sonic = new Sprite(path, 64, 64, TextureColor, GetRenderer(), TexturePosition, TextureScale, TextureRotation);

	//Init Texture
	TexturePosition2 = Vector3{ width / 4,height / 2,0 };

	Cartel = new Sprite(path, 64, 64, TextureColor2, GetRenderer(), TexturePosition2, TextureScale, TextureRotation);

	path = "res/map.png";
	Fondo = new Sprite(path, 900, 507, TextureColor2, GetRenderer(), Vector3{ 0+450,0+507/2, 0 }, Vector3{ 900,507, 0 }, TextureRotation);

	//Idle Animation
	walkAnimation = new Animation();
	walkAnimation->AddFrame(848, 203, 122/3, 48, 830, 465, 1000, 3);

	idleAnimation = new Animation();
	idleAnimation->AddFrame(390, 98, 98 / 3, 43, 830, 465, 2500, 3);

	idleAnimationCartel = new Animation();
	idleAnimationCartel->AddFrame(133, 150, 49.5 , 100, 832, 830, 465, 4);

	Sonic->SetAnimation(idleAnimation);
	Cartel->SetAnimation(idleAnimationCartel);
}

void Game::update()
{
	if (!CollisionManager::CheckCollisionRecRec(Sonic, Cartel))
	{
		lastTexturePos = Sonic->getPosition();
	}
	Sonic->SetAnimation(idleAnimation);

	//Inputs
	if (inputSystem->getKey(inputSystem->q, inputSystem->Pressed))
	{
		Sonic->SetAnimation(walkAnimation);
		Sonic->setRotationZ(-1);
	}

	if (inputSystem->getKey(inputSystem->e, inputSystem->Pressed))
	{
		Sonic->SetAnimation(walkAnimation);
		Sonic->setRotationZ(1);
	}

	if (inputSystem->getKey(inputSystem->s, inputSystem->Pressed))
	{
		Sonic->SetAnimation(walkAnimation);
		Sonic->setPosition(Vector3{ Sonic->getPosition().x, Sonic->getPosition().y - 1.0f,0 });
	}

	if (inputSystem->getKey(inputSystem->w, inputSystem->Pressed))
	{
		Sonic->SetAnimation(walkAnimation);
		Sonic->setPosition(Vector3{ Sonic->getPosition().x, Sonic->getPosition().y + 1.0f,0 });
	}

	if (inputSystem->getKey(inputSystem->a, inputSystem->Pressed))
	{
		Sonic->SetAnimation(walkAnimation);
		Sonic->setPosition(Vector3{ Sonic->getPosition().x - 1.0f, Sonic->getPosition().y ,0 });
	}

	if (inputSystem->getKey(inputSystem->d, inputSystem->Pressed))
	{
		Sonic->SetAnimation(walkAnimation);
		Sonic->setPosition(Vector3{ Sonic->getPosition().x + 1.0f, Sonic->getPosition().y ,0 });
	}

	//Collider
	if (CollisionManager::CheckCollisionRecRec(Sonic, Cartel))
	{
		Sonic->setPosition(lastTexturePos);
	}

	Sonic->Update();
	Cartel->Update();

	Fondo->Draw();
	Sonic->Draw();
	Cartel->Draw();
}

void Game::exit()
{
	delete Sonic;
	delete Cartel;

	delete idleAnimation;
	delete idleAnimationCartel;
	delete walkAnimation;
}