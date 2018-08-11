
#include "VertexBufferLayout.h"


VertexBufferLayout::VertexBufferLayout()
    :   _stride(0)
{

}

VertexBufferLayout::~VertexBufferLayout()
{

}

void VertexBufferLayout::Push(unsigned int type, unsigned int count, unsigned char normalized)
{
    _elements.push_back({type, count, normalized});
    _stride += count * VertexBufferElement::SizeOfGLType(type);
}
