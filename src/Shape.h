#pragma once
#include <GL/glew.h>
#include "Vectors.h"
#include "Entity2D.h"

using namespace vectors;
using namespace Entity2D;

namespace shape
{
	class Shape : Entity2D
	{
	private:

		float vertex[12];
		unsigned int index[6];
		unsigned int EBO; //Element Buffer Object.
		unsigned int VAO; //Vertex Array Object.
		unsigned int VBO; //Vertex Buffer Object.
		Vector4 color;

	public:

		void initShape();
		void initVertex();
		void initIndex();
		void initElementBufferObject();
		void initVertexArrayObject();
		void initVertexBufferObject();
		void bindVertexAndBuffer();
		void deleteVertexAndBuffer();
		void initIndexRectangle();
		void initIndexTriangle();

	public:

		Shape();
		~Shape();
		void createTriangle(Vector3 vertex1, Vector3 vertex2, Vector3 vertex3);
		void createRectangle(Vector3 vertex1, Vector3 vertex2, Vector3 vertex3, Vector3 vertex4);
		void drawShape();
	};
}