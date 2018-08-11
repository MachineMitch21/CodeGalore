
#ifndef MESH_H
#define MESH_H

#include <vector>

#include "VertexBufferFormat.h"

struct Vertex 
{
    std::vector<void*> Data;
};

struct Texture 
{
    unsigned int    ID;
    std::string     Type;
};

class Mesh 
{
public:
    Mesh();
    ~Mesh();

    void SetVertices(const std::vector<Vertex>& vertices);
    void SetIndices(const std::vector<unsigned int>& indices);
    void SetTextures(const std::vector<Texture>& textures);
    void SetVertexFormat(const VertexBufferFormat& format);

    inline const std::vector<Vertex>&       GetVertices()       { return _vertices; };
    inline const std::vector<unsigned int>& GetIndices()        { return _indices; };
    inline const std::vector<Texture>&      GetTextures()       { return _textures; };
    inline const VertexBufferFormat&        GetVertexFormat()   { return _vertexFormat; };

private:
    std::vector<Vertex>         _vertices;
    std::vector<unsigned int>   _indices;
    std::vector<Texture>        _textures;
    VertexBufferFormat          _vertexFormat;
};

#endif // MESH_H
