#pragma once
#include "Renderer.h"
#include "Entity2D.h"
#include "TextureImporter.h"

using namespace Entity2D;
using namespace textureImporter;

class Texture : public Entity2D
{
private:
	unsigned char* value;

public:
	Texture(string path, int width, int height, TextureImporter* textureImporter, Vector4 rgba, Renderer* render, Vector3 newPosition, Vector3 newScale, Vector3 newRotation);
	~Texture();
};

