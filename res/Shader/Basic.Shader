#shader vertex
#version 330 core
            
layout (location = 0) in vec4 aPos;

uniform mat4 u_MVP;

void main()
{
    gl_Position = u_MVP * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}        

#shader fragment
#version 330 core
            
out vec4 FragColor;

uniform vec4 u_Color;
            
void main()
{
    FragColor = u_Color;
}        
