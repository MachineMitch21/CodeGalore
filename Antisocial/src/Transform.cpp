
#include "Transform.h"

Transform::Transform()
    :   _position(glm::vec3(0.0f)),
        _scale(glm::vec3(1.0f)),
        _rotation(glm::quat())
{

}

Transform::~Transform()
{

}

void Transform::SetPosition(glm::vec3 position)
{
    _position = position;
}

void Transform::SetScale(glm::vec3 scale)
{
    _scale = scale;
}

void Transform::SetRotationEuler(glm::vec3 rotEuler)
{
    _rotation = glm::quat(  glm::vec3(  glm::radians(rotEuler.x), 
                                        glm::radians(rotEuler.y), 
                                        glm::radians(rotEuler.z))
                        );
}

void Transform::SetRotation(glm::quat quatRot)
{
    _rotation = quatRot;
}

const glm::mat4 Transform::GetTransformationMatrix() const
{
    glm::mat4 model = glm::mat4(1.0f);
    
    glm::mat4 translation   = glm::translate(model, _position);
    glm::mat4 rotation      = glm::mat4_cast(_rotation);
    glm::mat4 scale         = glm::scale(model, _scale);

    model = translation * rotation * scale;

    return model;
}

const float* Transform::GetMatrixPointer() const 
{
    return glm::value_ptr(GetTransformationMatrix());
}