#include "CoreEngine/Renderer.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) errorLog.GLClearError();\
				x;\
				ASSERT(errorLog.GLLogCall(#x, __FILE__, __LINE__))

namespace renderer
{
	Renderer::Renderer(Window* window)
	{
		this->window = window;

		projection = glm::ortho(0.0f, window->getWidth(), 0.0f, window->getHeight(), 0.1f, 100.0f);
		vec3 cameraPosition = vec3(0, 0, 1);
		view = lookAt(cameraPosition, { 0,0,0 }, { 0,1,0 });

		ShaderProgramSource source;
		source = shader.ParseShader("res/Shader/Primitive.Shader");
		primitiveShader = shader.createShader(source.VertexSource, source.FragmentSource);

		source = shader.ParseShader("res/Shader/Texture.Shader");
		textureShader = shader.createShader(source.VertexSource, source.FragmentSource);
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

	void Renderer::Draw2DEntity(unsigned int VAO, int sizeIndex, Vector4 color, glm::mat4x4 model)
	{
		glUseProgram(primitiveShader);

		unsigned int transformLoc = glGetUniformLocation(primitiveShader, "u_MVP");
		mat4 MVP = projection * view * model;
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(MVP));

		glBindVertexArray(VAO);
		glUniform4f(glGetUniformLocation(primitiveShader, "u_Color"), color.x, color.y, color.z, color.w);
		glDrawElements(GL_TRIANGLES, sizeIndex, GL_UNSIGNED_INT, nullptr);
		glUseProgram(0);
	}

	void Renderer::DrawTexture(unsigned int VAO, int sizeIndex, Vector4 color, glm::mat4x4 model)
	{
		glUseProgram(textureShader);

		//unsigned int transformLoc = glGetUniformLocation(primitiveShader, "u_MVP");
		//mat4 MVP = projection * view * model;
		//glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(MVP));

		//glActiveTexture(GL_TEXTURE0);
		//glBindTexture(GL_TEXTURE_2D, texture1);

		//ourShader.use();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, sizeIndex, GL_UNSIGNED_INT, 0);
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