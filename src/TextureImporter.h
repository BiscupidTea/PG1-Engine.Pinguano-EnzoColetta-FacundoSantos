#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <string>
#pragma once

using namespace std;

namespace textureImporter
{
	class TextureImporter
	{
		private:

			unsigned char* m_LocalBuffer;

		public:

			unsigned char GetTexture(string& path, int m_Width, int m_Height, int m_BPP);
	};
}