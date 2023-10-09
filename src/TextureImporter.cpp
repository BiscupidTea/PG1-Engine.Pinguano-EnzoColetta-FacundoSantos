#include "TextureImporter.h"

namespace textureImporter
{
	unsigned char TextureImporter::GetTexture(string& path, int m_Width, int m_Height, int m_BPP)
	{
		stbi_set_flip_vertically_on_load(1);
		
		m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

		return *m_LocalBuffer;
	}
}
