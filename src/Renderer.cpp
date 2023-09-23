#include "Renderer.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) errorLog.GLClearError();\
				x;\
				ASSERT(errorLog.GLLogCall(#x, __FILE__, __LINE__))

namespace renderer
{
	Renderer::Renderer(Window* window)
	{
		this->window = window;
		ShaderProgramSource source = shader.ParseShader("res/Shader/Basic.Shader");
		shaderProgram = shader.createShader(source.VertexSource, source.FragmentSource);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glUseProgram(shaderProgram);
	}

	Renderer::~Renderer()
	{

	}
	void Renderer::StartDraw()
	{
		GLCall(glClearColor(0.1f, 0.3f, 0.3f, 1.0f));
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Renderer::EndDraw()
	{
		GLCall(glfwSwapBuffers(window->getWindow()));
		GLCall(glfwPollEvents());
	}

	void Renderer::Draw2DEntity(unsigned int VAO, int sizeIndex, Vector4 color)
	{
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glUniform4f(glGetUniformLocation(shaderProgram, "u_Color"), color.x, color.y, color.z, color.w);
		glDrawElements(GL_TRIANGLES, sizeIndex, GL_UNSIGNED_INT, nullptr);
		glUseProgram(0);
	}

	void Renderer::CreateVBuffer(float* positions, int* indexs, int positionsSize, int indexSize, int atributeVertexSize, unsigned int& VAO, unsigned int& VBO, unsigned int& EBO)
	{
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * positionsSize, positions, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * indexSize, indexs, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, atributeVertexSize, GL_FLOAT, GL_FALSE, sizeof(float) * atributeVertexSize, (void*)0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}

	void Renderer::deleteVertexAndBuffer(unsigned int& VAO, unsigned int& VBO, unsigned int& EBO)
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}
}