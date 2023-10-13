#shader vertex
#version 330 core

layout(location = 0) in vec4 aPos;
layout(location = 2) in vec2 texCoord;

uniform mat4 u_MVP;

out vec2 v_TexCoord;

void main()
{
	gl_Position = uniform mat4 u_MVP * pos;
	v_TexCoord = texCoord
}

#shader fragment
#version 330 core
layout(location = 0) in vec4 u_color;

in vec2 v_TexCoord;

// texture samplers
uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
	vec4 textColor = texture(u_Texture, v_TexCoord);
	color = textColor;
}