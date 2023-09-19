#pragma once
#include <GL/glew.h>
#include "Vectors.h"
<<<<<<< HEAD

using namespace vectors;

namespace shape
{
	class Shape
=======
#include "Entity2D.h"

using namespace vectors;
using namespace Entity2D;

namespace shape
{
	class Shape : Entity2D
>>>>>>> parent of 88bb22a... half added draw shape
	{
		private: 
			
		float vertex[12];
		unsigned int index[6];
		unsigned int EBO; //Element Buffer Object.
		unsigned int VAO; //Vertex Array Object.
		unsigned int VBO; //Vertex Buffer Object.
		Vector4 color;
<<<<<<< HEAD

		public:
=======
>>>>>>> parent of 88bb22a... half added draw shape

		void initShape();
		void initVertex();
		void initIndex();
		void initElementBufferObject();
		void initVertexArrayObject();
		void initVertexBufferObject();
		void bindVertexAndBuffer();
		void deleteVertexAndBuffer();
<<<<<<< HEAD
=======

	public:

		Shape();
		~Shape();
		void createTriangle(Vector3 vertex1, Vector3 vertex2, Vector3 vertex3);
		void createRectangle(Vector3 vertex1, Vector3 vertex2, Vector3 vertex3, Vector3 vertex4);
		void drawShape();
>>>>>>> parent of 88bb22a... half added draw shape
	};
}