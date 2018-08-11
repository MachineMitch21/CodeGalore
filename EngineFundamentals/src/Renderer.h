#ifndef RENDERER_H
#define RENDERER_H

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Model.h"
#include "Shader.h"

class Renderer 
{
public:

    void Draw(const Model& model, const Shader& shader);
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);

private:

};

#endif // RENDERER_H