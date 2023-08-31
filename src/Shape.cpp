#include "Shape.h"

namespace shape
{
	void Shape::initShape()
	{
		initVertex();

		initIndex();

		initElementBufferObject();

		initVertexArrayObject();

		initVertexBufferObject();
	}

	void Shape::initVertex()
	{
		vertex[0] = 0.5f;
		vertex[1] = 0.5f;
		vertex[2] = 0.0f;

		vertex[3] = 0.5f;
		vertex[4] = -0.5f;
		vertex[5] = 0.0f;
		
		vertex[6] = -0.5f;
		vertex[7] = -0.5f;
		vertex[8] = 0.0f;
		
		vertex[9] = -0.5f;
		vertex[10] = 0.5f;
		vertex[11] = 0.0f;
	}

	void Shape::initIndex()
	{
		index[0] = 0;
		index[1] = 1;
		index[2] = 3;

		index[3] = 1;
		index[4] = 2;
		index[5] = 3;
	}

	void Shape::initElementBufferObject()
	{
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);
	}

	void Shape::initVertexArrayObject()
	{     
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);
	}

	void Shape::initVertexBufferObject()
	{
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Shape::bindVertexAndBuffer()
	{
		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	}

	void Shape::deleteVertexAndBuffer()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}
}