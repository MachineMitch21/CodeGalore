#include "Mesh.h"


Mesh::Mesh()
{

}

Mesh::~Mesh()
{

}

void Mesh::SetVertices(const std::vector<float>& vertices)
{
    _vertices = vertices;
}

void Mesh::SetIndices(const std::vector<unsigned int>& indices)
{
    _indices = indices;
}

void Mesh::SetTextures(const std::vector<Texture2D>& textures)
{
    _textures = textures;
}

void Mesh::SetVertexLayout(const VertexBufferLayout& format)
{
    _vertexLayout = format;
}
