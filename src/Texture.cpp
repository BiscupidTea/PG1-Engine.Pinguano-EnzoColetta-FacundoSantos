#include "Texture.h"

namespace texture
{
	Texture::Texture(const char path, int width, int height, Vector4 rgba, Renderer* render, Vector3 newPosition, Vector3 newScale, Vector3 newRotation) : Entity2D(rgba, render, newPosition, newScale, newRotation)
	{
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		stbi_set_flip_vertically_on_load(1);

		*localBuffer = textureImporter->GetTexture(path, width, height, 0);

		if (localBuffer)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);
			glBindTexture(GL_TEXTURE_2D, 0);
		}
		
		else
		{
			cout << "Failed to load texture" << endl;
		}

		stbi_image_free(localBuffer);
	}

	Texture::~Texture()
	{

	}
}