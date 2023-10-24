#include "Entity/Sprite.h"

namespace sprite
{
	Sprite::Sprite(const char* textureName, int width, int height, Vector4 rgba, Renderer* render, Vector3 newPosition, Vector3 newScale, Vector3 newRotation) : Entity2D(rgba, render, newPosition, newScale, newRotation)
	{
		this->width = width;
		this->height = height;

		CreateSprite();

		render->CreateVBuffer(vertexPositions, indexs, vertexSize, indexSize, atributeVertexSize, VAO, VBO, EBO, aColorSize, aUvSize);
		render->BindTexture(textureName, textureId);
	}

	Sprite::~Sprite()
	{

	}

	void Sprite::CreateSprite()
	{
		vertexSize = 36;

		vertexPositions = new float [vertexSize]
		{
			// positions			 // colors					// texture coords
			0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,   // top right
				0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,   // bottom right
				-0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,   // bottom left
				-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f    // top left 
		};

		indexSize = 6;
		indexs = new int[indexSize]
		{
			0, 1, 3,
				1, 2, 3
		};
	}

	void Sprite::Update()
	{
		if (!animation)
		{
			return;
		}
		else
		{
			animation->UpdateAnimation();
			SetUV(animation->GetCurrentFrame());
		}
	}

	void Sprite::Draw()
	{
		DrawTexture();
	}

	void Sprite::SetAnimation(Animation* animation)
	{
		this->animation = animation;
	}

	void Sprite::SetUV(Frame frame)
	{
		vertexPositions[7] = frame.uvArray->u;
		vertexPositions[8] = frame.uvArray->v;

		vertexPositions[16] = frame.uvArray->u;
		vertexPositions[17] = frame.uvArray->v;

		vertexPositions[25] = frame.uvArray->u;
		vertexPositions[26] = frame.uvArray->v;

		vertexPositions[34] = frame.uvArray->u;
		vertexPositions[35] = frame.uvArray->v;
	}

}