
#ifndef ASSETLOADER_H
#define ASSETLOADER_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <string>

#include <map>

#include "Model.h"

class AssetLoader 
{
public:
    AssetLoader();
    ~AssetLoader();

    void LoadModel(const std::string& file, Model* model);

private:
    void Process_aiNode(aiNode* node, const aiScene* scene, Model* model);
    Mesh Process_aiMesh(aiMesh* mesh, const aiScene* scene);

private: 
    std::map<std::string, Model> _cachedModels;
};

#endif // ASSETLOADER_H