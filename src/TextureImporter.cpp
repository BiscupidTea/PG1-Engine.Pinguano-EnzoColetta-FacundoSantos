#include "TextureImporter.h"

namespace textureImporter
{
    unsigned char TextureImporter::GetTexture(const char& path, int m_Width, int m_Height, int m_BPP)
    {
        const char* defalutPath = "PG1-Engine.Pinguano-EnzoColetta-FacundoSantos/Prueba/res";

        m_LocalBuffer = stbi_load(defalutPath + path, &m_Width, &m_Height, &m_BPP, 4);

        return *m_LocalBuffer;
    }
}