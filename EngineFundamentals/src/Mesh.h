
#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>

#include <vector>

#include "Shader.h"

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"

struct Vertex 
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoord;
};

class Mesh 
{
public:
    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
    ~Mesh();

    // void SetVertices(std::vector<Vertex> vertices);

    void Draw(const Shader& shader);

    inline const std::vector<Vertex>&       GetVertices()   const { return _vertices; };
    inline const std::vector<unsigned int>& GetIndices()    const { return _indices; };

    inline const VertexArray& GetVertexArray() const { return _vertexArray; };
    inline const IndexBuffer& GetIndexBuffer() const { return _indexBuffer; };

private:
    void SetupMesh()
    {
                // create buffers/arrays
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
        // load data into vertex buffers
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        // A great thing about structs is that their memory layout is sequential for all its items.
        // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
        // again translates to 3/2 floats which translates to a byte array.
        glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);  

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int), &_indices[0], GL_STATIC_DRAW);

        // set the vertex attribute pointers
        // vertex Positions
        glEnableVertexAttribArray(0);	
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        // vertex normals
        glEnableVertexAttribArray(1);	
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
        // vertex texture coords
        glEnableVertexAttribArray(2);	
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoord));

        glBindVertexArray(0);
    }

private:
    std::vector<Vertex>         _vertices;
    std::vector<unsigned int>   _indices;

    GLuint  VAO, VBO, EBO;

    VertexArray         _vertexArray;
    VertexBuffer        _vertexBuffer;
    VertexBufferLayout  _vertexLayout;
    IndexBuffer         _indexBuffer;
};

#endif // MESH_H