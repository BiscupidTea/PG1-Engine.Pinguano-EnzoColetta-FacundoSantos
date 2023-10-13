#pragma once
#include "Renderer.h"
#include "Entity2D.h"
#include "TextureImporter.h"

using namespace Entity2D;
using namespace textureImporter;

namespace texture
{
	class Texture : public Entity2D
	{
	private:

		TextureImporter* textureImporter;
		unsigned int textureID;
		unsigned char* localBuffer;


	public:
		Texture(const char path, int width, int height, Vector4 rgba, Renderer* render, Vector3 newPosition, Vector3 newScale, Vector3 newRotation);
		~Texture();
	};
}