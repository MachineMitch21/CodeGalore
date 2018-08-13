
#ifndef PRIMITIVECREATOR_H
#define PRIMITIVECREATOR_H

#include "Mesh.h"

class PrimitiveCreator 
{
public:
    
    static void CreateCube(Mesh* mesh);

protected:
    PrimitiveCreator();
    ~PrimitiveCreator();
};

#endif // PRIMITIVECREATOR_H