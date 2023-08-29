#include <GL/glew.h>
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

        float vertices[] = 
        {
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
           -0.5f, -0.5f, 0.0f,  // bottom left
           -0.5f,  0.5f, 0.0f   // top left 
        };

        unsigned int indices[] = 
        {
            0, 1, 3,
            1, 2, 3 
        };

        unsigned int EBO; //Element Buffer Object.
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        unsigned int VBO; //Vertex Buffer Object.
        unsigned int VAO; //Vertex Array Object.
        
        glGenVertexArrays(1 , &VAO);
        
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        //***********************************************************************

        /* Loop until the user closes the window */
        while (!window.windowShouldClose(window.getWindow()))
        {
            /* Render here */
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            renderer.clear();

            //Separate in functions
            //***********************************************************************
            glUseProgram(shaderProgram);
            glBindVertexArray(VAO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
            //glDrawArrays(GL_TRIANGLES, 0, 3);
            //***********************************************************************

            /* Swap front and back buffers */
            renderer.swapBuffers(window.getWindow());

            /* Poll for and process events */
            renderer.pollEvents();
        }

        //Separate in functions
        //***********************************************************************
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        //***********************************************************************
    }

    void BaseGame::closeEngine()
    {
        window.closeWindow();
    }
}