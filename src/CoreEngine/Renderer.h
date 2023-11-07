#include "Shader.h"
#include "CoreEngine/Window.h"
#include "Tools/Vectors.h"
#include "Tools/ErrorLog.h"
#include <GLFW/glfw3.h>
#include "..\libs\glm\include\glm.hpp"
#include "..\libs\glm\include\gtc\matrix_transform.hpp"
#include "..\libs\glm\include\gtc\type_ptr.hpp"
#include "Tools/TextureImporter.h"

#pragma once

using namespace window;
using namespace shader;
using namespace errorLog;
using namespace vectors;
using namespace glm;
using namespace textureImporter;

namespace renderer
{
	/// <summary>
	/// Class Renderer
	/// </summary>
	class Renderer
	{
	private:

		ErrorLog errorLog;
		Window* window;
		Shader shader;
		TextureImporter textureImporter;
		unsigned int primitiveShader;
		unsigned int textureShader;
		glm::mat4x4 projection;
		glm::mat4x4 view;

	public:

		Renderer(Window* window);
		~Renderer();
		/// <summary>
		/// Clear screen
		/// </summary>
		void StartDraw();
		/// <summary>
		/// Swap the front and back buffer of the specified window.
		/// </summary>
		/// <param name="window">Screen reference</param>
		void EndDraw();
		/// <summary>
		/// Processes all pending events.
		/// </summary>
		void Draw2DEntity(unsigned int VAO, int sizeIndex, Vector4 color, glm::mat4x4 model);

		void DrawTexture(unsigned int VAO, int sizeIndex, Vector4 color, glm::mat4x4 model, unsigned int& idTexture);

		void CreateVBuffer(float* positions, int* indexs, int positionsSize, int indexSize, int atributeVertexSize,
			unsigned int& VAO, unsigned int& VBO, unsigned int& EBO);

		void CreateVBuffer(float* positions, int* indexs, int positionsSize, int indexSize, int atributeVertexSize,
			unsigned int& VAO, unsigned int& VBO, unsigned int& EBO, int aColorSize, int aUVSize);
		void BindTexture(const char* textureName, unsigned& textureID);
		void deleteVertexAndBuffer(unsigned int& VAO, unsigned int& VBO, unsigned int& EBO);
	};
}