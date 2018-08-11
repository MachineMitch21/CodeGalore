
#version 330 core

layout (location = 0) in vec3 input_Pos;
layout (location = 1) in vec3 Normal;
layout (location = 2) in vec2 TexCoord;

uniform mat4 mvp;

out vec2 texCoord; 

void main()
{
    gl_Position = mvp * vec4(input_Pos, 1.0);
    texCoord = TexCoord;
}