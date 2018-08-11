
#include "Renderer.h"

void Renderer::Draw(const Model& model, const Shader& shader)
{
    std::vector<Mesh> meshes = model.GetMeshes();
    for (unsigned int i = 0; i < meshes.size(); i++)
    {
        meshes[i].Draw(shader);
    }
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)
{
    shader.bind();
    va.Bind();
    ib.Bind();

    glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0);

    shader.unbind();
    ib.UnBind();
    va.UnBind();
}