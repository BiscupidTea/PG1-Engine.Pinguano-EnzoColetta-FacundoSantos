#pragma once
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
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

		const char* shaderColorVulueName;

	public:
		unsigned int IDshader;

		void initShader(const char* filepath);
		void color(float red, float green, float blue, float alpha);
		void deleteShader();
		ShaderProgramSource ParseShader(const string& filepath);
		static unsigned int compileShader(unsigned int type, const string& source);
		static unsigned int createShader(const string& vertexShader, const string& fragmentShader);
	};

}

