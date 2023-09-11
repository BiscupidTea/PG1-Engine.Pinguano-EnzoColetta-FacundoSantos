#include "ErrorLog/ErrorLog.h"

using namespace std;

namespace errorLog
{
	int ErrorLog::CheckGlfwInit()
	{
		if (!glfwInit())
		{
			cout << "Error to start glfw" << endl;

			return -1;
		}
		return 0;
	}

	void ErrorLog::CheckGlewInit()
	{
		if (glewInit() != GLEW_OK)
		{
			cout << "Error to start glew." << endl;
		}
	}

	void ErrorLog::GLClearError()
	{
		while (glGetError() != GL_NO_ERROR);
	}

	bool ErrorLog::GLLogCall(const char* function, const char* file, int line)
	{
		while (GLenum error = glGetError())
		{
			cout << "[OpenGL Error] (" << error << "): " << function << " " << file << ":" << line << endl;
			return false;
		}
		return true;
	}
}
