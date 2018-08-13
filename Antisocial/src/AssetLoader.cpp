
#include "AssetLoader.h"

AssetLoader::AssetLoader()
{

}

AssetLoader::~AssetLoader()
{

}

void AssetLoader::LoadModel(const std::string& file, Model* model)
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(file,  aiProcess_Triangulate       |
                                                    aiProcess_CalcTangentSpace  );

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        printf("ASSIMP ERROR -- %s\n", importer.GetErrorString());
        model = NULL;
        return;
    }

    Process_aiNode(scene->mRootNode, scene, model);
}

void AssetLoader::Process_aiNode(aiNode* node, const aiScene* scene, Model* model)
{
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        model->_meshes.push_back(Process_aiMesh(mesh, scene));
    }

    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        Process_aiNode(node->mChildren[i], scene, model);
    }
}

Mesh AssetLoader::Process_aiMesh(aiMesh* mesh, const aiScene* scene)
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
