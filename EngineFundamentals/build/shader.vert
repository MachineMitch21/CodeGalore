
#version 330 core

layout (location = 0) in vec3 input_Pos;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

out vec3 VertexPos;
out vec3 WorldPos;
out vec3 Normal;
out vec2 TexCoord;

uniform mat4 mvp;

void main()
{
    vec4 worldPos = mvp * vec4(input_Pos, 1.0);

    gl_Position = worldPos;
    VertexPos = input_Pos;
    WorldPos = worldPos.xyz;
    Normal = normal;
    TexCoord = texCoord;
}