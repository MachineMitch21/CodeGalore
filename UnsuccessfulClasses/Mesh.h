
#ifndef MESH_H
#define MESH_H

#include <vector>

#include "VertexBufferLayout.h"
#include "Texture2D.h"

class Mesh 
{
public:
    Mesh();
    ~Mesh();

    void SetVertices(const std::vector<float>& vertices);
    void SetIndices(const std::vector<unsigned int>& indices);
    void SetTextures(const std::vector<Texture2D>& textures);
    void SetVertexLayout(const VertexBufferLayout& format);

    inline const std::vector<float>&    GetVertices()       { return _vertices; };
    inline const std::vector<unsigned int>&     GetIndices()        { return _indices; };
    inline const std::vector<Texture2D>&        GetTextures()       { return _textures; };
    inline const VertexBufferLayout&            GetVertexLayout()   { return _vertexLayout; };

private:
    std::vector<float>  _vertices;
    std::vector<unsigned int>   _indices;
    std::vector<Texture2D>      _textures;
    VertexBufferLayout          _vertexLayout;
};

#endif // MESH_H
