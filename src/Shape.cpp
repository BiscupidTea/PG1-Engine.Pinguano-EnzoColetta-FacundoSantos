#include "Shape.h"

namespace shape
{
	Shape::Shape(typeShapes typeShapes, Vector4 rgba, Renderer* render, Vector3 newPosition, Vector3 newScale, Vector3 newRotation) : Entity2D(rgba, render, newPosition, newScale, newRotation)
	{
		switch (typeShapes)
		{
		case shape::Shape::Triangle:
			createTriangle();
			break;
		case shape::Shape::Square:
			createRectangle();
			break;
		default:
			break;
		}
	}

	Shape::~Shape()
	{

	}

	void Shape::createTriangle()
	{
		vertexSize = 9;
		vertexPositions = new float[vertexSize]
		{
			0.0f, 0.5f, 0.0f,
				0.5f, -0.5f, 0.0f,
				-0.5f, -0.5f, 0.0f
		};

		indexSize = 3;
		indexs = new int[indexSize]
		{
			0, 1, 2
		};

		atributeVertexSize = 3;
		render->CreateVBuffer(vertexPositions, indexs, vertexSize, indexSize, atributeVertexSize, VAO, VBO, EBO);
	}

	void Shape::createRectangle()
	{
		vertexSize = 12;
		vertexPositions = new float[vertexSize] {
			0.5f, 0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			-0.5f, 0.5f, 0.0f
		};
		indexSize = 6;
		indexs = new int[indexSize] {
			0, 1, 2,
			2, 3, 0
		};

		atributeVertexSize = 3;
		render->CreateVBuffer(vertexPositions, indexs, vertexSize, indexSize, atributeVertexSize, VAO, VBO, EBO);
	}
}