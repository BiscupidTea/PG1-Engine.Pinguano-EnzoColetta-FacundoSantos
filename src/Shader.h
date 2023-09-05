#pragma once
#include <GL/glew.h>
#include <fstream>
#include <string>

using namespace std;

namespace Shader
{
	class Shader
	{
	private:

	public:

		Shader();

		void CreateShader(string directionShader);
		const char* ReadFile(string directionShader);
	};

}

