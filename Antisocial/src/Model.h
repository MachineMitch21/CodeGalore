
#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "Mesh.h"

class Model 
{
    friend class Renderer;
    friend class AssetLoader;
public:
    Model();
    ~Model();

    inline std::vector<Mesh>& GetMeshes() { return _meshes; };

private:
    std::vector<Mesh>   _meshes;
};

#endif // MODEL_H