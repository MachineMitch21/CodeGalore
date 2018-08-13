
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
#include "Renderer.h"
#include "Shader.h"
#include "Mesh.h"
#include "PrimitiveCreator.h"
#include "Model.h"
#include "AssetLoader.h"
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

    Renderer renderer;

    if (!renderer.Init())
    {
        printf("Could not initialize Renderer\n");
        window.Close();
    }

    Model model;

    AssetLoader assetLoader;
    assetLoader.LoadModel("res/models/Skull_Mountain.fbx", &model);

    Mesh cube;
    PrimitiveCreator::CreateCube(&cube);

    Shader cubeShader("res/shaders/diffuse_lighting.vert", "res/shaders/diffuse_lighting.frag");

    Texture2D cubeTexture("res/textures/test.jpeg");

    glm::vec4 clearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glm::vec3 cubePosition(0.0f);
    glm::vec3 cubeRotation(0.0f);

    glm::vec3 camPosition(0.0f, 0.0f, 3.0f);
    float camFieldOfView = 60.0f;

    float attenCoef = 0.5f;
    float attenLinear = 0.5f;
    float attenSquare = 0.5f;

    glm::vec3 lightPosition(-1.0f, 0.5f, 0.5f);
    glm::vec4 lightColor(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec4 objectColor(1.0f, 1.0f, 1.0f, 1.0f);
    float lightIntensity = 1.0f;

    Transform cubeTransform;
    cubeTransform.SetPosition(glm::vec3(0.0f));
    cubeTransform.SetRotationEuler(glm::vec3(0.0f));

    InitImGui(window.GetGlfwWindow());

    glfwWindowHint(GLFW_SAMPLES, 4);
    glEnable(GL_MULTISAMPLE);

    while (!window.IsClosed())
    {
        glfwPollEvents();

        glm::mat4 proj = glm::perspective(glm::radians(camFieldOfView), 16.0f / 9.0f, 0.1f, 100.0f);
        glm::mat4 view = glm::lookAt(camPosition, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

        BeginImGuiFrame();

        ImGui::Begin("Testing 1..2..3..");
        ImGui::InputFloat3("Cube position", &cubePosition.x);
        ImGui::InputFloat3("Cube rotation", &cubeRotation.x);
        ImGui::ColorEdit4("Clear Color", &clearColor.x);
        ImGui::ColorEdit4("Object Color", &objectColor.x);
        ImGui::InputFloat3("Camera Position", &camPosition.x);
        ImGui::InputFloat3("Light position", &lightPosition.x);
        ImGui::ColorEdit4("Light color", &lightColor.x);
        ImGui::InputFloat("Light intensity", &lightIntensity);
        ImGui::InputFloat("Attenuation Coefficient", &attenCoef);
        ImGui::InputFloat("Attenuation Linear", &attenLinear);
        ImGui::InputFloat("Attenuation Square", &attenSquare);
        ImGui::End();

        ImGui::Render();

        renderer.Clear(clearColor.x, clearColor.y, clearColor.z, clearColor.w);

        cubeTransform.SetPosition(cubePosition);
        cubeTransform.SetRotationEuler(cubeRotation);

        glm::mat4 cubeModelMatrix = cubeTransform.GetTransformationMatrix();

        glm::mat4 mvp = proj * view * cubeModelMatrix;
        glm::mat3 normalMatrix = glm::mat3(glm::transpose(glm::inverse(cubeModelMatrix)));

        cubeShader.Bind();
        cubeShader.SetMatrix4("mvp", glm::value_ptr(mvp));
        cubeShader.SetMatrix3("normalMatrix", glm::value_ptr(normalMatrix));
        cubeShader.SetMatrix4("modelMatrix", glm::value_ptr(cubeModelMatrix));
        cubeShader.SetFloat("attenCoef", attenCoef);
        cubeShader.SetFloat("attenLinear", attenLinear);
        cubeShader.SetFloat("attenSquare", attenSquare);
        cubeShader.SetVector3("lightPos", lightPosition.x, lightPosition.y, lightPosition.z);
        cubeShader.SetVector4("objectColor", objectColor.x, objectColor.y, objectColor.z, objectColor.w);
        cubeShader.SetVector4("lightColor", lightColor.x, lightColor.y, lightColor.z, lightColor.w);
        cubeShader.SetFloat("LightIntensity", lightIntensity);
        cubeShader.SetInteger("texture0", 0);

        cubeTexture.Bind();
        renderer.Draw(&cube, 1);
        cubeTexture.UnBind();

        cubeShader.UnBind();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        window.Update();
    }

    return 0;
}