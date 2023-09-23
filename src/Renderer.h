#include "Shader.h"
#include "Window.h"
#include "Vectors.h"
#include "ErrorLog.h"
#include <GLFW/glfw3.h>
#pragma once

using namespace window;
using namespace shader;
using namespace errorLog;
using namespace vectors;

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
		unsigned int shaderProgram;

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
		void Draw2DEntity(unsigned int VAO, int sizeIndex, Vector4 color);

		void CreateVBuffer(float* positions, int* indexs, int positionsSize, int indexSize, int atributeVertexSize,
			unsigned int& VAO, unsigned int& VBO, unsigned int& EBO);

		void deleteVertexAndBuffer(unsigned int& VAO, unsigned int& VBO, unsigned int& EBO);
	};
}