#include "Texture.h"

Texture::Texture(string path, int width, int height, TextureImporter* textureImporter, Vector4 rgba, Renderer* render, Vector3 newPosition, Vector3 newScale, Vector3 newRotation) : Entity2D(rgba, render, newPosition, newScale, newRotation)
{
	value = textureImporter->GetTexture(path, 1, 1, 1);
}

Texture::~Texture()
{

}