#pragma once
#include <GL/glew.h>
#include "Vectors.h"

using namespace vectors;

namespace shape
{
	class Shape
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
	};
}