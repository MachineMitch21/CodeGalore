#ifndef MODEL_H
#define MODEL_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"


class Model 
{
public:
    Model(const std::string& filePath);
    ~Model();

    inline const std::vector<Mesh>& GetMeshes() const { return _meshes; };

private:
    void LoadModel(const std::string& filePath)
    {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(filePath,  aiProcess_Triangulate   |
                                                            aiProcess_CalcTangentSpace);

        if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        {
            printf("ASSIMP ERROR -- %s\n", importer.GetErrorString());
            return;
        }    

        ProcessNode(scene->mRootNode, scene);
    }

    void ProcessNode(aiNode* node, const aiScene* scene)
    {
        for (unsigned int i = 0; i < node->mNumMeshes; i++)
        {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            _meshes.push_back(ProcessMesh(mesh, scene));
        }

        for (unsigned int i = 0; i < node->mNumChildren; i++)
        {
            ProcessNode(node->mChildren[i], scene);
        }
    }

    Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene)
    {
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        
        for (unsigned int i = 0; i < mesh->mNumVertices; i++)
        {
            Vertex vertex;
            glm::vec3 temp;

            temp.x = mesh->mVertices[i].x;
            temp.y = mesh->mVertices[i].y;
            temp.z = mesh->mVertices[i].z;
            vertex.Position = temp;

            temp.x = mesh->mNormals[i].x;
            temp.y = mesh->mNormals[i].y;
            temp.z = mesh->mNormals[i].z;
            vertex.Normal = temp;

            if (mesh->mTextureCoords[0])
            {
                glm::vec2 coords;

                coords.x = mesh->mTextureCoords[0][i].x;
                coords.y = mesh->mTextureCoords[0][i].y;
                vertex.TexCoord = coords;
            }
            vertices.push_back(vertex);
        }

        for (unsigned int i = 0; i < mesh->mNumFaces; i++)
        {
            aiFace face = mesh->mFaces[i];

            for (unsigned int j = 0; j < face.mNumIndices; j++)
            {
                indices.push_back(face.mIndices[j]);
            }
        }

        return Mesh(vertices, indices);
    }

private:
    std::vector<Mesh> _meshes;
};

#endif // MODEL_H