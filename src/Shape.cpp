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

	void Shape::initIndexRectangle()
	{
		index[0] = 0;
		index[1] = 1;
		index[2] = 3;

		index[3] = 1;
		index[4] = 2;
		index[5] = 3;
	}

	void Shape::initIndexTriangle()
	{
		index[0] = 0;
		index[1] = 1;
		index[2] = 3;
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

	void Shape::createTriangle(Vector3 vertex1, Vector3 vertex2, Vector3 vertex3)
	{
		vertex[0] = vertex1.x;
		vertex[1] = vertex1.y;
		vertex[2] = vertex1.z;

		vertex[3] = vertex2.x;
		vertex[4] = vertex2.y;
		vertex[5] = vertex2.z;

		vertex[6] = vertex3.x;
		vertex[7] = vertex3.y;
		vertex[8] = vertex3.z;

		initIndexTriangle();
		initShape();
	}

	void Shape::createRectangle(Vector3 vertex1, Vector3 vertex2, Vector3 vertex3, Vector3 vertex4)
	{
		vertex[0] = vertex1.x;
		vertex[1] = vertex1.y;
		vertex[2] = vertex1.z;

		vertex[3] = vertex2.x;
		vertex[4] = vertex2.y;
		vertex[5] = vertex2.z;

		vertex[6] = vertex3.x;
		vertex[7] = vertex3.y;
		vertex[8] = vertex3.z;

		vertex[9] = vertex4.x;
		vertex[10] = vertex4.y;
		vertex[11] = vertex4.z;

		initIndexRectangle();
		initShape();
	}

	void Shape::drawShape()
	{
		bindVertexAndBuffer();
	}
}