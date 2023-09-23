#pragma once
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <GL/glew.h>
#include "ErrorLog.h"

using namespace std;
using namespace errorLog;

struct ShaderProgramSource
{
	string VertexSource;
	string FragmentSource;
};

namespace shader
{
	class Shader
	{
	private:

		ErrorLog errorLog;
		unsigned int IDshader;

	public:

		Shader();
		~Shader();
		static ShaderProgramSource ParseShader(const string& filepath);
		static GLuint compileShader(unsigned int type, const string& source);
		static int createShader(const string& vertexShader, const string& fragmentShader);
		void SetVec4(const std::string& name, float x, float y, float z, float w) const { glUniform4f(glGetUniformLocation(IDshader, name.c_str()), x, y, z, w); }
	};

}

