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
	TextureColor = Vector4{ 0.5f, 0.0f, 0.5f, 1 };;
	TexturePosition = Vector3{ width / 2,height / 2, 0 };
	TextureScale = Vector3{ 64,64,1 };;
	TextureRotation = Vector3{ 0,0,0 };;

	const char* path = "res/Player_Sprite.png";
	Player = new Sprite(path, 64, 64, TextureColor, GetRenderer(), TexturePosition, TextureScale, TextureRotation);
	textureCollider = new Shape(Shape::Square, TextureColor, GetRenderer(), TexturePosition, TextureScale, TextureRotation);

	//Init Texture
	TextureColor2 = Vector4{ 1.0f, 1.0f, 1.0f, 1 };
	TexturePosition2 = Vector3{ width / 4,height / 4,0 };
	TextureScale2 = Vector3{ 64,64,1 };
	TextureRotation2 = Vector3{ 0,0,0 };

	path = "res/Enemy_Sprite.png";
	Enemy = new Sprite(path, 64, 64, TextureColor2, GetRenderer(), TexturePosition2, TextureScale2, TextureRotation2);
	textureCollider2 = new Shape(Shape::Square, TextureColor2, GetRenderer(), TexturePosition2, TextureScale2, TextureRotation2);

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

	idleAnimationEnemy = new Animation();
	idleAnimationEnemy->AddFrame(64, 64 * 14, 64, 64, 832, 1344, 1000, 7);

	Player->SetAnimation(idleAnimation);
	Enemy->SetAnimation(idleAnimationEnemy);
}

void Game::update()
{
	if (!CollisionManager::CheckCollisionRecRec(Player, Enemy))
	{
		lastTexturePos = Player->getPosition();
	}

	Player->SetAnimation(idleAnimation);
	Enemy->SetAnimation(idleAnimationEnemy);

	//Inputs
	if (inputSystem->getKey(inputSystem->q, inputSystem->Pressed))
	{
		Player->SetAnimation(rotationLeftAnimation);
		Player->setRotationZ(-1);
	}

	if (inputSystem->getKey(inputSystem->e, inputSystem->Pressed))
	{
		Player->SetAnimation(rotationRightAnimation);
		Player->setRotationZ(1);
	}

	if (inputSystem->getKey(inputSystem->s, inputSystem->Pressed))
	{
		Player->SetAnimation(walkDownAnimation);
		Player->setPosition(Vector3{ Player->getPosition().x, Player->getPosition().y - 1.0f,0 });
	}

	if (inputSystem->getKey(inputSystem->w, inputSystem->Pressed))
	{
		Player->SetAnimation(walkUpAnimation);
		Player->setPosition(Vector3{ Player->getPosition().x, Player->getPosition().y + 1.0f,0 });
	}

	if (inputSystem->getKey(inputSystem->a, inputSystem->Pressed))
	{
		Player->SetAnimation(walkLeftAnimation);
		Player->setPosition(Vector3{ Player->getPosition().x - 1.0f, Player->getPosition().y ,0 });
	}

	if (inputSystem->getKey(inputSystem->d, inputSystem->Pressed))
	{
		Player->SetAnimation(walkRightAnimation);
		Player->setPosition(Vector3{ Player->getPosition().x + 1.0f, Player->getPosition().y ,0 });
	}

	//Collider
	if (CollisionManager::CheckCollisionRecRec(Player, Enemy))
	{
		Player->setPosition(lastTexturePos);
	}

	textureCollider->setPosition(Player->getPosition());
	textureCollider2->setPosition(Enemy->getPosition());

	Player->Update();
	Enemy->Update();

	//textureCollider->Draw();
	Player->Draw();

	//textureCollider2->Draw();
	Enemy->Draw();
}

void Game::exit()
{
	delete Player;
	delete Enemy;

	delete idleAnimation;
	delete walkRightAnimation;
	delete walkLeftAnimation;
	delete walkUpAnimation;
	delete walkDownAnimation;
	delete rotationLeftAnimation;
	delete rotationRightAnimation;
}