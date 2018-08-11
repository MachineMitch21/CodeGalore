
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp> 
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform 
{
public:
    Transform();
    ~Transform();

    void SetPosition(glm::vec3 position);
    void SetScale(glm::vec3 scale);
    void SetRotationEuler(glm::vec3 rotEuler);
    void SetRotation(glm::quat quatRot);

    const glm::mat4 GetTransformationMatrix() const;
    const float* GetMatrixPointer() const;

    inline const glm::vec3& GetPosition()   const { return _position;   };
    inline const glm::vec3& GetScale()      const { return _scale;      };
    inline const glm::quat& GetRotation()   const { return _rotation;   };

private:
    glm::vec3   _position;
    glm::vec3   _scale;
    glm::quat   _rotation;
};

#endif // TRANSFORM_H