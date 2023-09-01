#include <iostream>
#include "BaseGame.h"

using namespace std;

namespace baseEngine
{
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
        //Separate in functions
        //***********************************************************************
        const char* vertexShaderSource = R"HERE(
            #version 330 core
            
            layout (location = 0) in vec3 aPos;
            
            void main()
            {
               gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
            }        
        )HERE";
           
        const char* fragmentShaderSource = R"HERE(
            #version 330 core
            
            out vec4 FragColor;
            
            void main()
            {
                FragColor = vec4(1.0f, 0.5f, 0.4f, 1.0);
            }        
        )HERE";

        //Vertex Shader.
        int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);

        int  success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
        }

        //Fragment Shader.
        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);

        glGetProgramiv(fragmentShader, GL_LINK_STATUS, &success);
        if (!success) 
        {
            glGetProgramInfoLog(fragmentShader, 512, NULL, infoLog);
            cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
        }

        //Link Shaders
        int shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

        if (!success)
        {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);

            cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        //Shape
        //***********************************************************************
        shape.initShape();
        //***********************************************************************

        /* Loop until the user closes the window */
        while (!window.windowShouldClose(window.getWindow()))
        {
            renderer.RenderScreen(window, shape, shaderProgram);
        }

        shape.deleteVertexAndBuffer();
    }

    void BaseGame::closeEngine()
    {
        window.closeWindow();
    }
}