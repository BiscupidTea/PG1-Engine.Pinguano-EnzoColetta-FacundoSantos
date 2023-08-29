#pragma once
#include "Vectors.h"

using namespace vectors;

namespace shape
{
	class Shape
	{
		private: 
			
		float vertex[12];
		unsigned int index[6];
		Vector4 color;

		public:

		void initVertex();
		void initIndex();
		void initElementBuffer(unsigned int index[]);
		void initVertexArrayObject();
		void initVertexBufferObject(float vertex[]);
	};
}