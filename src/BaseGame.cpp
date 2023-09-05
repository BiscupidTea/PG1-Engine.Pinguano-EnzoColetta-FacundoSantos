#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BaseGame.h"

using namespace std;

namespace baseEngine
{
    struct ShaderProgramSource
    {
        string VertexSource;
        string FragmentSource;
    };

    static ShaderProgramSource ParseShader(const string& filepath)
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

    static unsigned int compileShader(unsigned int type, const string& source)
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

    static unsigned int createShader(const string& vertexShader, const string& fragmentShader)
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

    int BaseGame::initEngine()
    {
        int width = 640;
        int height = 480;

        const char* windowName = "Pinguano-Engine";

        GLFWmonitor* monitor = NULL;
        GLFWwindow* share = NULL;

        if (!glfwInit())
        {
            return -1;
        }

        window.initWindow(width, height, windowName, monitor, share);

        if (glewInit() != GLEW_OK)
        {
            cout << "Error to start glew." << endl;
        }
    }

    void BaseGame::updateEngine()
    {
        ShaderProgramSource source = ParseShader("res/Shader/Basic.Shader");

        unsigned int shader = createShader(source.VertexSource, source.FragmentSource);
        glUseProgram(shader);

        //Shape
        //***********************************************************************
        shape.initShape();
        //***********************************************************************

        /* Loop until the user closes the window */
        while (!window.windowShouldClose(window.getWindow()))
        {
            renderer.RenderScreen(window, shape, shader);
        }

        shape.deleteVertexAndBuffer();
    }

    void BaseGame::closeEngine()
    {
        window.closeWindow();
    }
}