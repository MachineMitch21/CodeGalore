
#include "Mesh.h"

#include "Texture2D.h"

#include <iostream>

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
    :   _vertices(vertices),
        _indices(indices)
{
    // // TODO: fix this to be more dynamic
    // _vertexLayout.Push(GL_FLOAT, 3);
    // _vertexLayout.Push(GL_FLOAT, 3);
    // _vertexLayout.Push(GL_FLOAT, 2);

    // _vertexBuffer = VertexBuffer(&_vertices[0], _vertices.size() * sizeof(Vertex));
    // _vertexArray.AddBuffer(_vertexBuffer, _vertexLayout);
    // _indexBuffer = IndexBuffer(&_indices[0], _indices.size());



    // _vertexArray.UnBind();

    SetupMesh();
}

Mesh::~Mesh()
{

}

void Mesh::Draw(const Shader& shader)
{
    shader.bind();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    shader.unbind();
}