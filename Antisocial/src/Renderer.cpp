
#include "Renderer.h"

#include <cstdio>

Renderer::Renderer()
{
    
}

Renderer::~Renderer()
{

}

bool Renderer::Init()
{
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();

    if (err != GLEW_OK)
    {
        printf("GLEW ERROR -- Could not inialize GLEW\n");
        return false;
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glDepthMask(GL_TRUE);

    glEnable(GL_STENCIL_TEST);

    glFrontFace(GL_CCW);

    return true;
}

void Renderer::Clear(float r, float g, float b, float a)
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glClearColor(r, g, b, a);
}

void Renderer::Draw(Mesh* meshes, unsigned int numMeshes)
{
    for (unsigned int i = 0; i < numMeshes; i++)
    {
        meshes[i].Draw();
    }
}

void Renderer::Draw(GLuint vao, unsigned int count, Shader* shader)
{
    shader->Bind();
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    shader->UnBind();
}