
#ifndef VERTEXBUFFERLAYOUT_H
#define VERTEXBUFFERLAYOUT_H

#include <GL/glew.h>

#include <vector>

struct VertexBufferElement 
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int SizeOfGLType(unsigned int type)
    {
        switch(type)
        {
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;     
            case GL_UNSIGNED_BYTE:  return 1;     
            default:                return 0;                   
        }
    }

};

class VertexBufferLayout 
{
public:
    VertexBufferLayout();
    ~VertexBufferLayout();

    void Push(unsigned int type, unsigned int count, unsigned char normalized = GL_FALSE);

    inline const std::vector<VertexBufferElement>& GetElements() const { return _elements; };
    inline unsigned int GetStride() const { return _stride; };

private:
    std::vector<VertexBufferElement> _elements;
    unsigned int _stride;
};

#endif // VERTEXBUFFERLAYOUT_H