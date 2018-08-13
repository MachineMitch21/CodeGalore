
#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>

#include "Mesh.h"

class Renderer 
{
public:
    Renderer();
    ~Renderer();

    void Clear(float r, float g, float b, float a);
    bool Init();

    void Draw(GLuint vao, unsigned int count, Shader* shader);
    void Draw(Mesh* meshes, unsigned int numMeshes);

private:
};

#endif // RENDERER_H