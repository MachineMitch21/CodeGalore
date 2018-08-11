
#include "Model.h"


Model::Model()
{

}

Model::~Model()
{

}

bool Model::Load(const std::string& filePath)
{
    Assimp::Importer importer;

    const aiScene* scene = importer.ReadFile(filePath, aiProcess_Triangulate | aiProcess_FlipUVs);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        printf("ASSIMP ERROR -- %s\n", importer.GetErrorString());
        return false;
    }

    ProcessNode(scene->mRootNode, scene);

    return true;
}

void Model::ProcessNode(aiNode* node, const aiScene* scene)
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

Mesh Model::ProcessMesh(aiMesh* mesh, const aiScene* scene)
{
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture2D> textures;

    VertexBufferLayout layout;

    layout.Push(GL_FLOAT, 3);
    layout.Push(GL_FLOAT, 3);

    bool has_texCoords = false;

    int offset = 8;

    if (mesh->mTextureCoords[0])
    {
        has_texCoords = true;
    }

    for (unsigned int i = 0; i < mesh->mNumVertices; i += offset)
    {
        float* curVertPos   = &mesh->mVertices[i].x;
        float* curNorm      = &mesh->mNormals[i].x;

        vertices.assign(curVertPos, curVertPos + 3);
        vertices.assign(curNorm, curNorm + 3);
        
        if (has_texCoords)
        {
            float* curTexCoord = &mesh->mTextureCoords[0][i].x;
            vertices.assign(curTexCoord, curTexCoord + 2);
        }
    }

    if (has_texCoords)
    {
        layout.Push(GL_FLOAT, 2);
    }

    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++)
        {
            indices.push_back(face.mIndices[j]);
        }
    }

    if (mesh->mMaterialIndex >= 0)
    {
        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

        printf("Texture count: %d\n", material->GetTextureCount(aiTextureType_DIFFUSE));

        for (unsigned int i = 0; i < material->GetTextureCount(aiTextureType_DIFFUSE); i++)
        {
            aiString str;
            material->GetTexture(aiTextureType_DIFFUSE, i, &str);

            printf("Texture-name: %s\n", str.C_Str());

            Texture2D texture(std::string(str.C_Str()));
            textures.push_back(texture);
        }
    }

    Mesh outputMesh;
    outputMesh.SetVertices(vertices);
    outputMesh.SetIndices(indices);
    outputMesh.SetTextures(textures);
    outputMesh.SetVertexLayout(layout);

    
    _vertexArray.Bind();
    _vertexBuffer = VertexBuffer(&outputMesh.GetVertices()[0], outputMesh.GetVertices().size() * sizeof(float));

    _vertexArray.AddBuffer(_vertexBuffer, outputMesh.GetVertexLayout());

    _indexBuffer = IndexBuffer(&indices[0], indices.size());
    return outputMesh;
}