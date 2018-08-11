
#version 330 core

out vec4 FragColor;

in vec3 VertexPos;
in vec3 Normal;
in vec2 TexCoord;

uniform vec4 ambientColor;
uniform float ambientIntensity;

uniform mat4 model;
uniform mat4 view;
uniform mat3 normalMat;

uniform vec3 lightPos;
uniform vec4 lightColor;

uniform vec4 objectColor;

uniform sampler2D texture0;

uniform float attenCoef;
uniform float attenLinearFalloff;
uniform float attenSquareFalloff;

uniform float textureBlend;

float diffuse(vec3 worldPos)
{
    vec3 lightDir = (lightPos - worldPos);

    vec3 worldNormal = normalize(normalMat * Normal);

    float d = max(dot(worldNormal, lightDir), 0.0);

    return d; 
}


void main()
{
    vec4 textureSample = texture(texture0, TexCoord);

    vec4 texColBlend = mix(textureSample, objectColor, textureBlend);

    vec3 worldPos = (model * vec4(VertexPos, 1.0)).xyz;

    float d = diffuse(worldPos);
    vec3 diffuse = d * lightColor.xyz;

    float dist = distance(worldPos, lightPos);

    float atten = 1.0 / (attenCoef + (attenLinearFalloff * dist + attenSquareFalloff * pow(dist, 2)));

    FragColor = texColBlend * (atten * ((ambientColor * ambientIntensity) + (vec4(diffuse, 1.0))));;
}