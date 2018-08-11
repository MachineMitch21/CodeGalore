
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp> 
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "Window.h"
#include "Shader.h"
#include "Texture2D.h"
#include "Transform.h"

void InitImGui(GLFWwindow* window)
{
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, false);
    ImGui_ImplOpenGL3_Init();
    ImGui::StyleColorsDark();
}

void BeginImGuiFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);

    ImGuiIO& io = ImGui::GetIO();

    if (!io.WantCaptureKeyboard)
    {
        // HANDLE KEYBOARD
    }
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
    ImGuiIO& io = ImGui::GetIO();

    if (!io.WantCaptureMouse)
    {
        // HANDLE MOUSE
    }
}

void char_callback(GLFWwindow* window, unsigned int codepoint)
{
    ImGui_ImplGlfw_CharCallback(window, codepoint);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
}

int main(int argc, char** argv)
{
    Window window("Antisocial", 800, 600);

    InitImGui(window.GetGlfwWindow());

    std::vector<float> vertices = 
    {
        // Front face
        -0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
         0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,

        // Right face
         0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
         0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,

         // Back face
         0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
         0.5f,  0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,

         // Left face 
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

        // Top face 
        -0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
         0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
         0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,

        // Bottom face 
        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
         0.5f, -0.5f,  0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f
    };

    std::vector<unsigned int> indices = 
    {
        0,  1,  2,
        0,  2,  3,
        4,  5,  6,
        4,  6,  7,
        8,  9,  10,
        8,  10, 11,
        12, 13, 14,
        12, 14, 15,
        16, 17, 18,
        16, 18, 19,
        20, 21, 22,
        20, 22, 23
    };

    glFrontFace(GL_CCW);

    GLuint vao, vbo, ebo;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float) * 3));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float) * 6));

    glBindVertexArray(0);

    Shader shader("res/shaders/color.vert", "res/shaders/color.frag");
    Shader diffuseLighting("res/shaders/diffuse_lighting.vert", "res/shaders/diffuse_lighting.frag");

    diffuseLighting.Bind();
    diffuseLighting.SetInteger("texture0", 0);
    diffuseLighting.UnBind();

    Texture2D testTexture("res/textures/test.jpeg");

    Transform colorModel;

    colorModel.SetPosition(glm::vec3(0.0f, 0.5f, 0.0f));
    colorModel.SetScale(glm::vec3(.5f));
    colorModel.SetRotationEuler(glm::vec3(0.0f, 45.0f, 0.0f));

    Transform diffuseModel;

    diffuseModel.SetPosition(glm::vec3(0.0f, -0.5f, 0.0f));
    diffuseModel.SetScale(glm::vec3(.5f));

    Transform lightModel;

    lightModel.SetScale(glm::vec3(.15f));

    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
    glm::mat4 proj = glm::perspective(glm::radians(60.0f), 16.0f / 9.0f, 0.1f, 1000.0f);

    glm::vec3 lightPos(-0.5f, 0.25f, 0.5f);
    glm::vec4 lightColor(1.0f, 1.0f, 1.0f, 1.0f);

    float attenCoef = 0.5f;
    float attenLinear = 0.5f;
    float attenSquare = 0.5f;

    float lightIntensity = 1.0f;

    glm::vec4 clearColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

    glfwWindowHint(GLFW_SAMPLES, 4);
    glEnable(GL_MULTISAMPLE);

    while (!window.IsClosed())
    {
        glfwPollEvents();
        BeginImGuiFrame();

        ImGui::Begin("Testing 1..2..3..");

        ImGui::SliderFloat("Attenuation coefficient", &attenCoef, 0.0f, 1.0f);
        ImGui::SliderFloat("Attenuation Linear", &attenLinear, 0.0f, 2.5f);
        ImGui::SliderFloat("Attenuation Square", &attenSquare, 0.0f, 2.5f);
        ImGui::SliderFloat3("Light Position", &lightPos.x, -10.0f, 10.0f);
        ImGui::ColorEdit4("Light Color", &lightColor.x);
        ImGui::Separator();
        ImGui::ColorEdit4("Clear Color", &clearColor.x);
        ImGui::SliderFloat("lightIntensity", &lightIntensity, 0.0f, 10.0f);

        ImGui::End();

        ImGui::Render();

        window.VerifyFrameBufferSize();
        window.Clear(clearColor.x, clearColor.y, clearColor.z, clearColor.w);

        glm::mat4 mvp = proj * view * colorModel.GetTransformationMatrix();

        shader.Bind();
        shader.SetVector4("objectColor", 1.0f, 0.0f, 0.0f, 1.0f);
        shader.SetMatrix4("mvp", glm::value_ptr(mvp));

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

        lightModel.SetPosition(lightPos);

        mvp = proj * view * lightModel.GetTransformationMatrix();

        shader.SetVector4("objectColor", lightColor.x, lightColor.y, lightColor.z, lightColor.w);
        shader.SetMatrix4("mvp", glm::value_ptr(mvp));

        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        shader.UnBind();

        diffuseModel.SetRotationEuler(glm::vec3(0.0f, glfwGetTime() * 10.0f, 0.0f));

        glm::mat4 diffuseModelMat = diffuseModel.GetTransformationMatrix();

        mvp = proj * view * diffuseModelMat;

        glm::mat3 normalMatrix = glm::mat3(glm::transpose(glm::inverse(diffuseModelMat)));

        diffuseLighting.Bind();
        diffuseLighting.SetMatrix4("mvp", glm::value_ptr(mvp));
        diffuseLighting.SetMatrix4("modelMatrix", glm::value_ptr(diffuseModelMat));
        diffuseLighting.SetMatrix3("normalMatrix", glm::value_ptr(normalMatrix));
        diffuseLighting.SetVector3("lightPos", lightPos.x, lightPos.y, lightPos.z);
        diffuseLighting.SetFloat("attenCoef", attenCoef);
        diffuseLighting.SetFloat("attenLinear", attenLinear);
        diffuseLighting.SetFloat("attenSquare", attenSquare);
        diffuseLighting.SetVector4("lightColor", lightColor.x, lightColor.y, lightColor.z, lightColor.w);
        diffuseLighting.SetFloat("lightIntensity", lightIntensity);

        glBindVertexArray(vao);
        testTexture.Bind();
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        testTexture.UnBind();
        glBindVertexArray(0);

        diffuseLighting.UnBind();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        window.Update();
    }

    int err;
    float test = diffuseLighting.GetFloat("attenCoef", &err);

    if (err != -1)
    {
        printf("%.2f\n", test);
    }
    
    std::vector<float> testVec3Query = diffuseLighting.GetVector3("lightPos", &err);

    if (err != -1)
    {
        printf("%.2f, %.2f, %.2f\n", testVec3Query[0], testVec3Query[1], testVec3Query[2]);
    }
    return 0;
}