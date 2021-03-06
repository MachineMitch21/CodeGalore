#include "VertexArray.h"

#include <GL/glew.h>

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &_rendererID);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &_rendererID);
}

void VertexArray::Bind() const
{
    glBindVertexArray(_rendererID);
}

void VertexArray::UnBind() const
{
    glBindVertexArray(0);
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
    Bind();
    vb.Bind();
    const auto& elements = layout.GetElements();

    unsigned int offset = 0;

    for (int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)(offset));

        offset += element.count * VertexBufferElement::SizeOfGLType(element.type);
    }
}
