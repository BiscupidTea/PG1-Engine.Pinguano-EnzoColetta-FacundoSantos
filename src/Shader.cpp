#include <iostream>
#include "Shader.h"

namespace shader
{
	void Shader::initShader(const char* filepath)
	{
		ShaderProgramSource source = ParseShader(filepath);

		IDshader = createShader(source.VertexSource, source.FragmentSource);
		glUseProgram(IDshader);
	}
	
	//DEFINIR_EN_GRUPO
	//*************************************************************************************
	void Shader::color(float red, float green, float blue, float alpha)
	{
		shaderColorVulueName = "u_Color";
		int location = glGetUniformLocation(IDshader, shaderColorVulueName);
		errorLog.ShaderLocationError(location);
		glUniform4f(location, red, green, blue, alpha);
	}
	//*************************************************************************************

	void Shader::deleteShader()
	{
		glDeleteProgram(IDshader);
	}

	ShaderProgramSource Shader::ParseShader(const string& filepath)
	{
		ifstream stream(filepath);

		enum class ShaderType
		{
			NONE = -1, VERTEX = 0, FRAGMENT = 1
		};

		string line;

		stringstream _stringstream[2];

		ShaderType type = ShaderType::NONE;

		while (getline(stream, line))
		{
			if (line.find("#shader") != string::npos)
			{
				if (line.find("vertex") != string::npos)
				{
					type = ShaderType::VERTEX;
				}

				else if (line.find("fragment") != string::npos)
				{
					type = ShaderType::FRAGMENT;
				}
			}

			else
			{
				_stringstream[(int)type] << line << '\n';
			}

		}

		return { _stringstream[0].str(), _stringstream[1].str() };
	}

	unsigned int Shader::compileShader(unsigned int type, const string& source)
	{
		unsigned int _ID = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(_ID, 1, &src, nullptr);
		glCompileShader(_ID);

		int result;
		glGetShaderiv(_ID, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(_ID, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)_malloca(length * sizeof(char));
			glGetShaderInfoLog(_ID, length, &length, message);

			cout << "ERROR::FAILED TO COMPILE " << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << " SHADER" << endl;
			cout << message << endl;

			glDeleteShader(_ID);
			return 0;
		}

		return _ID;
	}

	unsigned int Shader::createShader(const string& vertexShader, const string& fragmentShader)
	{
		unsigned int _program = glCreateProgram();
		unsigned int _vertexShader = compileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int _fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

		glAttachShader(_program, _vertexShader);
		glAttachShader(_program, _fragmentShader);
		glLinkProgram(_program);
		glValidateProgram(_program);

		glDeleteShader(_vertexShader);
		glDeleteShader(_fragmentShader);

		return _program;
	}
}