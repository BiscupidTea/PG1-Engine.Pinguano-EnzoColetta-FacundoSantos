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
		Vector4 position;
		unsigned int VAO; //Vertex Array Object.

		unsigned int VBO; //Vertex Buffer Object.
		int vertexSize;
		int atributeVertexSize = 3;
		float* vertexPositions;

		unsigned int EBO; //Element Buffer Object.
		int indexSize;
		int* indexs;

	public:
		Entity2D(Vector4 rgba);
		~Entity2D();
		
		void Draw();

		void setColor(Vector4 rgba);
		Vector4 getColor();

		void setPosition(Vector4 position);
		Vector4 getPosition();
	};
}

