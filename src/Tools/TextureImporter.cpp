#include "Tools/TextureImporter.h"

namespace textureImporter
{
    unsigned char* TextureImporter::GetTexture(const char* path, int m_Width, int m_Height, int m_BPP)
    {
        //const char* defalutPath = "../res";

        unsigned char* m_LocalBuffer = stbi_load(path, &m_Width, &m_Height, &m_BPP, 0);

        return m_LocalBuffer;
    }
}