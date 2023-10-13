#pragma once
#include "CoreEngine/Renderer.h"
#include "Entity/Entity2D.h"
#include "Tools/TextureImporter.h"

using namespace Entity2D;
using namespace textureImporter;

namespace texture
{
	class EXPORT Texture : public Entity2D
	{
	private:

		TextureImporter* textureImporter;
		unsigned int textureID;
		unsigned char* localBuffer;


	public:
		Texture(const char textureName, int width, int height, Vector4 rgba, Renderer* render, Vector3 newPosition, Vector3 newScale, Vector3 newRotation);
		~Texture();

		void CreateTexture();
		void Draw();
	};
}