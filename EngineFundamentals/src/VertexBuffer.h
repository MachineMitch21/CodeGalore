#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

class VertexBuffer 
{
public:
    VertexBuffer();
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void Bind() const;
    void UnBind() const;
private:
    unsigned int _rendererID;
};

#endif // VERTEXBUFFER_H