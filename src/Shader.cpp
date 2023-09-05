#include <iostream>
#include "Shader.h"

namespace Shader
{
	Shader::Shader()
	{


	}

	void Shader::CreateShader(string directionShader)
	{
        const char* line = ReadFile(directionShader);

        int newShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(newShader, 1, &line, NULL);
        glCompileShader(newShader);

        int  success;
        char infoLog[512];
        glGetShaderiv(newShader, GL_COMPILE_STATUS, &success);

        if (!success)
        {
            glGetShaderInfoLog(newShader, 512, NULL, infoLog);
            cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
        }
	}

    const char* ReadFile(string directionShader)
    {
        string contenido;
        ifstream archivo(directionShader);

        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                contenido += linea + "\n";
            }
            archivo.close();
        }
        else {
            cerr << "No se pudo abrir el archivo." << endl;
            return nullptr;
        }

        const char* resultado = contenido.c_str();
        return resultado;
    }
}