#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H 

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray 
{
public:
    VertexArray();
    ~VertexArray();

    void Bind() const;
    void UnBind() const;

    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

private:
    unsigned int _rendererID;

};

#endif // VERTEXARRAY_H