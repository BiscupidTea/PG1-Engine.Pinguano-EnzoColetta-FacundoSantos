#pragma once
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

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

	public:
		unsigned int IDshader;

		void initShader(const char* filepath);
		void deleteShader();
		ShaderProgramSource ParseShader(const string& filepath);
		static unsigned int compileShader(unsigned int type, const string& source);
		static unsigned int createShader(const string& vertexShader, const string& fragmentShader);
	};

}

