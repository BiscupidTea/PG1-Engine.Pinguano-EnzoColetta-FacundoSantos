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
	Sonic = new Sprite(path, TextureColor, GetRenderer(), TexturePosition, TextureScale, TextureRotation);


	//Init Texture
	TexturePosition2 = Vector3{ width / 4,height / 2,0 };

	Cartel = new Sprite(path, TextureColor2, GetRenderer(), TexturePosition2, TextureScale, TextureRotation);

	path = "res/map.png";
	Fondo = new Sprite(path, TextureColor2, GetRenderer(), Vector3{ 0 + 450,0 + 507 / 2, 0 }, Vector3{ 900,507, 0 }, TextureRotation);

	path = "res/pikachu.png";
	Pikachu = new Sprite(path, TextureColor, GetRenderer(), Vector3{ width - 50, height/2 ,0 }, TextureScale, TextureRotation);
	Logo = new Sprite(path, TextureColor2, GetRenderer(), Vector3{ 0, height, 0 }, Vector3{ 400,300, 0 }, TextureRotation);
	Credits = new Sprite(path, TextureColor2, GetRenderer(), Vector3{ width, 0 ,0 }, Vector3{ 600,300, 0 }, TextureRotation);

	//Idle Animation
	walkAnimationSonic = new Animation();
	walkAnimationSonic->AddFrame(848, 203, 122 / 3, 48, 830, 465, 500, 3);

	idleAnimationSonic = new Animation();
	idleAnimationSonic->AddFrame(390, 98, 98 / 3, 43, 830, 465, 2500, 3);

	idleAnimationPikachu = new Animation();
	idleAnimationPikachu->AddFrame(131, 1138, 40, 48, 847, 397, 1000, 3);

	walkAnimationPikachu = new Animation();
	walkAnimationPikachu->AddFrame(525, 1090, 50, 48, 847, 397, 1000, 4);

	idleAnimationLogo = new Animation();
	idleAnimationLogo->AddFrame(200, 0, 340, 300, 847, 397, 2500, 1);

	idleAnimationCreditos = new Animation();
	idleAnimationCreditos->AddFrame(575, 25, 580, 125, 847, 397, 2500, 1);

	idleAnimationCartel = new Animation();
	idleAnimationCartel->AddFrame(133, 150, 49.5, 100, 832, 830, 465, 4);

	Sonic->SetAnimation(idleAnimationSonic);
	Pikachu->SetAnimation(idleAnimationPikachu);
	Cartel->SetAnimation(idleAnimationCartel);
	Logo->SetAnimation(idleAnimationLogo);
	Credits->SetAnimation(idleAnimationCreditos);
}

void Game::update()
{
	if (!CollisionManager::CheckCollisionRecRec(Sonic, Cartel))
	{
		lastTexturePos = Sonic->getPosition();
	}

	if (!CollisionManager::CheckCollisionRecRec(Sonic, Pikachu))
	{
		lastTexturePos = Sonic->getPosition();
	}

	if (!CollisionManager::CheckCollisionRecRec(Pikachu, Cartel))
	{
		lastTexturePosP = Pikachu->getPosition();
	}

	if (!CollisionManager::CheckCollisionRecRec(Pikachu, Sonic))
	{
		lastTexturePosP = Pikachu->getPosition();
	}
	Sonic->SetAnimation(idleAnimationSonic);
	Pikachu->SetAnimation(idleAnimationPikachu);

	//Inputs

	if (inputSystem->getKey(inputSystem->s, inputSystem->Pressed))
	{
		Sonic->SetAnimation(walkAnimationSonic);
		Sonic->setPosition(Vector3{ Sonic->getPosition().x, Sonic->getPosition().y - 1.0f,0 });
	}

	if (inputSystem->getKey(inputSystem->w, inputSystem->Pressed))
	{
		Sonic->SetAnimation(walkAnimationSonic);
		Sonic->setPosition(Vector3{ Sonic->getPosition().x, Sonic->getPosition().y + 1.0f,0 });
	}

	if (inputSystem->getKey(inputSystem->a, inputSystem->Pressed))
	{
		Sonic->SetAnimation(walkAnimationSonic);
		Sonic->setPosition(Vector3{ Sonic->getPosition().x - 1.0f, Sonic->getPosition().y ,0 });
	}

	if (inputSystem->getKey(inputSystem->d, inputSystem->Pressed))
	{
		Sonic->SetAnimation(walkAnimationSonic);
		Sonic->setPosition(Vector3{ Sonic->getPosition().x + 1.0f, Sonic->getPosition().y ,0 });
	}

	if (inputSystem->getKey(inputSystem->k, inputSystem->Pressed))
	{
		Pikachu->SetAnimation(walkAnimationPikachu);
		Pikachu->setPosition(Vector3{ Pikachu->getPosition().x, Pikachu->getPosition().y - 1.0f,0 });
	}

	if (inputSystem->getKey(inputSystem->i, inputSystem->Pressed))
	{
		Pikachu->SetAnimation(walkAnimationPikachu);
		Pikachu->setPosition(Vector3{ Pikachu->getPosition().x, Pikachu->getPosition().y + 1.0f,0 });
	}

	if (inputSystem->getKey(inputSystem->j, inputSystem->Pressed))
	{
		Pikachu->SetAnimation(walkAnimationPikachu);
		Pikachu->setPosition(Vector3{ Pikachu->getPosition().x - 1.0f, Pikachu->getPosition().y ,0 });
	}

	if (inputSystem->getKey(inputSystem->l, inputSystem->Pressed))
	{
		Pikachu->SetAnimation(walkAnimationPikachu);
		Pikachu->setPosition(Vector3{ Pikachu->getPosition().x + 1.0f, Pikachu->getPosition().y ,0 });
	}

	//Collider
	if (CollisionManager::CheckCollisionRecRec(Sonic, Cartel))
	{
		Sonic->setPosition(lastTexturePos);
	}

	if (CollisionManager::CheckCollisionRecRec(Sonic, Pikachu))
	{
		Sonic->setPosition(lastTexturePos);
	}

	if (CollisionManager::CheckCollisionRecRec(Pikachu, Cartel))
	{
		Pikachu->setPosition(lastTexturePosP);
	}

	if (CollisionManager::CheckCollisionRecRec(Pikachu, Sonic))
	{
		Pikachu->setPosition(lastTexturePosP);
	}

	Sonic->Update();
	Pikachu->Update();
	Cartel->Update();
	Logo->Update();
	Credits->Update();

	Fondo->Draw();
	Sonic->Draw();
	Pikachu->Draw();
	Cartel->Draw();
	Logo->Draw();
	Credits->Draw();
}

void Game::exit()
{
	delete Sonic;
	delete Pikachu;
	delete Cartel;

	delete idleAnimationSonic;
	delete walkAnimationSonic;
	delete idleAnimationPikachu;
	delete walkAnimationPikachu;

	delete idleAnimationCartel;
	delete idleAnimationCreditos;
	delete idleAnimationLogo;
}