#pragma once
#include "Renderer.h"
#include "Entity2D.h"
#include "TextureImporter.h"

using namespace Entity2D;
using namespace textureImporter;

class Texture : public Entity2D
{
private:
	
	unsigned int m_RendererID;
	unsigned char* localBuffer;


public:
	Texture(const char path, int width, int height, unsigned int m_RendererID, TextureImporter* textureImporter, Vector4 rgba, Renderer* render, Vector3 newPosition, Vector3 newScale, Vector3 newRotation);
	~Texture();
	
	void Bind(unsigned int slot);
	void Unbind();
};

