#pragma once
#include "Vectors.h"
#include "Entity.h"

using namespace vectors;
using namespace Entity;

namespace Entity2D
{
	class EXPORT Entity2D : public Entity
	{
	protected:
		Vector4 color;
		unsigned int VAO = 0; //Vertex Array Object.

		unsigned int VBO = 0; //Vertex Buffer Object.
		int vertexSize = 0;
		int atributeVertexSize = 3;
		float* vertexPositions = 0;

		unsigned int EBO = 0; //Element Buffer Object.
		int indexSize = 0;
		int* indexs = 0;

	public:
		Entity2D(Vector4 rgba, Renderer* render, Vector3 newPosition, Vector3 newScale, Vector3 newRotation);
		~Entity2D();
		
		void Draw();

		void setColor(Vector4 rgba);
		Vector4 getColor();
	};
}

