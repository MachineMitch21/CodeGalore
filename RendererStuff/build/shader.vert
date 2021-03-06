
#version 330 core

layout (location = 0) in vec3 input_Pos;

uniform mat4 model;
uniform mat4 view; 
uniform mat4 proj;

uniform mat4 mvp;

void main()
{
    gl_Position = mvp * vec4(input_Pos, 1.0);
}