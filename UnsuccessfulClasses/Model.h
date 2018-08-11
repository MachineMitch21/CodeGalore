
#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"
#include "Shader.h"

#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"


class Model 
{
    
friend class Renderer;

public:
    Model();
    ~Model();

    bool Load(const std::string& filePath);
    
    void Draw();

private:
    void ProcessNode(aiNode* node, const aiScene* scene);
    Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);

private:
    std::vector<Mesh>   _meshes;

    VertexBuffer        _vertexBuffer;
    VertexArray         _vertexArray;
    IndexBuffer         _indexBuffer;    
};

#endif // MODEL_H