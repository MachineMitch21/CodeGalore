
#ifndef MESH_H
#define MESH_H

#include "Shader.h"
#include "Vertex.h"

class Mesh 
{
    friend class Renderer;
    friend class AssetLoader;
public:
    Mesh();
    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
    ~Mesh();

    void SetVertices(const std::vector<Vertex>& vertices);
    void SetIndices(const std::vector<unsigned int>& indices);

    void Draw();

    inline std::vector<Vertex>& GetVertices() { return _vertices; };
    inline std::vector<unsigned int>& GetIndices() { return _indices; };

protected:
    void GenBuffers();
    void SetupVertexArray();
    void SetupMesh();

private:
    std::vector<Vertex>         _vertices;
    std::vector<unsigned int>   _indices;
    GLuint                      _VAO;
    GLuint                      _VBO;
    GLuint                      _EBO;
};

#endif // MESH_H