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

	//Init Texture
	TextureColor2 = Vector4{ 1.0f, 1.0f, 1.0f, 1 };
	TexturePosition2 = Vector3{ width / 4,height / 4,0 };
	TextureScale2 = Vector3{ 64,64,1 };
	TextureRotation2 = Vector3{ 0,0,0 };

	const char* path = "res/Sonic_Mania_Sprite_Sheet.png";
	Letter = new Sprite(path, 49, 48, TextureColor2, GetRenderer(), TexturePosition2, TextureScale2, TextureRotation2);

	//Idle Animation
	idleAnimation = new Animation();
	idleAnimation->AddFrame(133, 92, 49, 48, 830, 465, 1000, 5);


	//Background
	BackgroundPos = Vector3{ width / 2,height /2,0 };
	BackgroundScale = Vector3{ 640, 480,1 };

	const char* pathBackground = "res/Background.png";
	BackGround = new Sprite(pathBackground, width, height, TextureColor2, GetRenderer(), BackgroundPos, BackgroundScale, TextureRotation2);

	//RunAnimation
	PlayerPos = Vector3{ width / 2,height / 2,0 };

	Player = new Sprite(path, 35, 50, TextureColor2, GetRenderer(), PlayerPos, TextureScale2, TextureRotation2);

	runAnimation = new Animation();
	runAnimation->AddFrame(286, 250, 35, 50, 830, 465, 50, 3);

	playerIdle = new Animation();
	playerIdle->AddFrame(286, 250, 35, 50, 830, 465, 50, 1);

	Letter->SetAnimation(idleAnimation);
	Player->SetAnimation(playerIdle);
}

void Game::update()
{
	if (!CollisionManager::CheckCollisionRecRec(Player, Letter))
	{
		lastTexturePos = Player->getPosition();
	}

	Letter->SetAnimation(idleAnimation);
	Player->SetAnimation(playerIdle);

	//Inputs
	if (inputSystem->getKey(inputSystem->q, inputSystem->Pressed))
	{
		Player->SetAnimation(runAnimation);
		Player->setRotationZ(-1);
	}

	if (inputSystem->getKey(inputSystem->e, inputSystem->Pressed))
	{
		Player->SetAnimation(runAnimation);
		Player->setRotationZ(1);
	}

	if (inputSystem->getKey(inputSystem->s, inputSystem->Pressed))
	{
		Player->SetAnimation(runAnimation);
		Player->setPosition(Vector3{ Player->getPosition().x, Player->getPosition().y - 5.0f,0 });
	}

	if (inputSystem->getKey(inputSystem->w, inputSystem->Pressed))
	{
		Player->SetAnimation(runAnimation);
		Player->setPosition(Vector3{ Player->getPosition().x, Player->getPosition().y + 5.0f,0 });
	}

	if (inputSystem->getKey(inputSystem->a, inputSystem->Pressed))
	{
		Player->SetAnimation(runAnimation);
		Player->setPosition(Vector3{ Player->getPosition().x - 5.0f, Player->getPosition().y ,0 });
	}

	if (inputSystem->getKey(inputSystem->d, inputSystem->Pressed))
	{
		Player->SetAnimation(runAnimation);
		Player->setPosition(Vector3{ Player->getPosition().x + 5.0f, Player->getPosition().y ,0 });
	}

	//Collider
	if (CollisionManager::CheckCollisionRecRec(Player, Letter))
	{
		Player->setPosition(lastTexturePos);
	}

	Letter->Update();
	Player->Update();

	BackGround->Draw();
	Letter->Draw();
	Player->Draw();
}

void Game::exit()
{
	delete Letter;

	delete idleAnimation;
}