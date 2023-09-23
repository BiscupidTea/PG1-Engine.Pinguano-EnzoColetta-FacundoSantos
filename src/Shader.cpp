#include <iostream>
#include "Shader.h"

namespace shader
{
	Shader::Shader()
	{

	}

	Shader::~Shader()
	{
		
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

	GLuint Shader::compileShader(unsigned int type, const string& source)
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

	int Shader::createShader(const string& vertexShader, const string& fragmentShader)
	{
		GLuint program = glCreateProgram();
		GLuint _vertexShader = compileShader(GL_VERTEX_SHADER, vertexShader);
		GLuint _fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

		glAttachShader(program, _vertexShader);
		glAttachShader(program, _fragmentShader);
		glLinkProgram(program);

		glValidateProgram(program);

		glDeleteShader(_vertexShader);
		glDeleteShader(_fragmentShader);

		return program;
	}
}