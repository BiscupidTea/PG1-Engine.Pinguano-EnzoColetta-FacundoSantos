#include "Shader.h"
#include "CoreEngine/Window.h"
#include "Vectors.h"
#include "ErrorLog.h"
#include <GLFW/glfw3.h>
#include "..\libs\glm\include\glm.hpp"
#include "..\libs\glm\include\gtc\matrix_transform.hpp"
#include "..\libs\glm\include\gtc\type_ptr.hpp"

#pragma once

using namespace window;
using namespace shader;
using namespace errorLog;
using namespace vectors;
using namespace glm;

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

		void DrawTexture(unsigned int VAO, int sizeIndex, Vector4 color, glm::mat4x4 model);

		void CreateVBuffer(float* positions, int* indexs, int positionsSize, int indexSize, int atributeVertexSize,
			unsigned int& VAO, unsigned int& VBO, unsigned int& EBO);

		void deleteVertexAndBuffer(unsigned int& VAO, unsigned int& VBO, unsigned int& EBO);
	};
}