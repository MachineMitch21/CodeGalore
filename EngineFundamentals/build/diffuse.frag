
#version 330 core

in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D texture0;

void main()
{
    vec4 texSample = texture(texture0, texCoord);

    FragColor = texSample;
}