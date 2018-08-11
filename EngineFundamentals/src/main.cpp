
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp> 
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <stdio.h>
#include <math.h>

#include <vector>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "Shader.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include "Renderer.h"
#include "Mesh.h"

#include "Texture2D.h"



bool keys[1024];
bool buttons[32];



bool blockClose = true;

char pCurrentChar = ' ';


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void window_focus_callback(GLFWwindow* window, int focused)
{
    if (focused)
    {
        printf("Gained focus\n");
    }
    else
    {
        printf("Lost focus\n");
    }
}

void window_refresh_callback(GLFWwindow* window)
{
    glfwSwapBuffers(window);
}

void window_close_callback(GLFWwindow* window)
{

}

void window_character_callback(GLFWwindow* window, unsigned int codepoint)
{
    ImGui_ImplGlfw_CharCallback(window, codepoint);
    printf("%c", codepoint);
}

void window_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
    ImGuiIO& io = ImGui::GetIO();

    if (!io.WantCaptureKeyboard)
        keys[key] = (action != GLFW_RELEASE);
}

void window_mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
    ImGuiIO& io = ImGui::GetIO();

    if (!io.WantCaptureMouse)
        buttons[button] = (action != GLFW_RELEASE);
}

void window_drop_callback(GLFWwindow* window, int count, const char** paths)
{
    printf("\n");

    int i;
    for (i = 0; i < count; i++)
    {
        printf("%s\n", paths[i]);
    }
}

void window_position_callback(GLFWwindow* window, int xpos, int ypos)
{

}

void window_scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
}

int main(int argc, char** argv)
{
    GLFWwindow* window;

    memset(keys, 0, 1024);
    memset(buttons, 0, 32);

    if (!glfwInit())
    {
        printf(" -- GLFW INITIALIZATION ERROR -- \n");
        return -1;
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);


#ifdef _DEBUG
    printf(" -- DEBUG MODE -- \n");
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#else
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_FALSE);
#endif // _DEBUG

    window = glfwCreateWindow(800, 600, "Engine", NULL, NULL);

    if (!window)
    {
        printf("GLFW WINDOW CREATION ERROR -- ");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);


    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        printf(" -- GLEW INITIALIZATION ERROR -- \n");
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDisable(GL_BLEND);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);


    glfwSetWindowAspectRatio(window, 16, 9);


    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetWindowFocusCallback(window, window_focus_callback);
    glfwSetWindowRefreshCallback(window, window_refresh_callback);
    glfwSetWindowCloseCallback(window, window_close_callback);
    glfwSetCharCallback(window, window_character_callback);
    glfwSetKeyCallback(window, window_key_callback);
    glfwSetDropCallback(window, window_drop_callback);
    glfwSetWindowPosCallback(window, window_position_callback);
    glfwSetMouseButtonCallback(window, window_mouse_button_callback);
    glfwSetScrollCallback(window, window_scroll_callback);

    Shader shader("shader.vert", "shader.frag");
    Texture2D tex("res/stone_wall_texture.jpg");

    shader.bind();

    shader.setInteger("texture0", 0);

    shader.unbind();

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

    VertexArray va;

    VertexBuffer vb(&vertices[0], vertices.size() * sizeof(vertices[0]));
    VertexBufferLayout layout;

    layout.Push(GL_FLOAT, 3, GL_FALSE);
    layout.Push(GL_FLOAT, 3, GL_FALSE);
    layout.Push(GL_FLOAT, 2, GL_FALSE);

    va.AddBuffer(vb, layout);

    IndexBuffer ib(&indices[0], indices.size());

    va.UnBind();
    vb.UnBind();
    ib.UnBind();

    glm::mat4 proj = glm::perspective(glm::radians(45.0f), 16.0f / 9.0f, 0.01f, 1000.0f);

    glm::vec3 modelTrans(0.0f, 0.0f, 0.0f);
    glm::vec3 modelRot(0.0f, 0.0f, 0.0f);
    glm::vec3 modelScale(1.0f, 1.0f, 1.0f);

    Renderer renderer;

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui_ImplGlfw_InitForOpenGL(window, false);
    ImGui_ImplOpenGL3_Init();

    ImGui::StyleColorsDark();

    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    bool test_show = true;

    glm::vec4 lightColor(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec3 lightPos(-1.0f, 1.0f, 2.0f);

    glm::vec4 objectColor(1.0f, 1.0f, 1.0f, 1.0f);

    float camZPos = 5.0f;

    Shader lightShader("flat_color.vert", "flat_color.frag");

    float oldTimeSinceStart = 0.0f;
    float deltaTime = 0.0f;

    float attenCoef = 1.0f;
    float attenLinearFalloff = 0.1f;
    float attenSquareFalloff = 1.0f;

    float blend = 0.0f;

    Model model("Skull_Mountain.fbx");

    Shader diffuseShader("diffuse.vert", "diffuse.frag");

    Texture2D diffuse("Skull_Mountain_Tex/Skull_Mountain_d.jpg");


    while (!glfwWindowShouldClose(window))
    {

        float timeSinceStart = glfwGetTime();
        deltaTime = timeSinceStart - oldTimeSinceStart;
        oldTimeSinceStart = timeSinceStart;

        lightPos.x = sin(glfwGetTime()) * 2.0f;

        if (modelRot.y > 360.0f)
        {
            modelRot.y = 0.0f;
        }

        modelRot.y += 10.0f * deltaTime;

        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Testing 1..2..3..", &test_show, ImGuiWindowFlags_MenuBar);
        
        static float f = 0.0f;
        static int counter = 0;
        ImGui::Text("Test Window");                           // Display some text (you can use a format string too)
        ImGui::InputFloat3("Position", &modelTrans.x);            // Edit 1 float using a slider from 0.0f to 1.0f    
        ImGui::InputFloat3("Rotation", &modelRot.x);
        ImGui::InputFloat3("Scale", &modelScale.x);
        ImGui::SliderFloat("Blend Factor", &blend, 0.0f, 1.0f);
        ImGui::SliderFloat("Attenuation Coefficient", &attenCoef, 0.0f, 1.0f);
        ImGui::SliderFloat("Attenuation Linear Falloff", &attenLinearFalloff, 0.0f, 1.0f);
        ImGui::SliderFloat("Attenuation Square Falloff", &attenSquareFalloff, 0.0f, 1.0f);
        ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
        ImGui::ColorEdit4("Object color", (float*)&objectColor.x);
        ImGui::ColorEdit4("Light color", (float*)&lightColor.x);
        ImGui::InputFloat("CamZPos", &camZPos);

        ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our windows open/close state
        ImGui::Checkbox("Another Window", &show_another_window);

        if (ImGui::Button("Button"))                            // Buttons return true when clicked (NB: most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        
        ImGui::End();

        float angle = glfwGetTime() * 25.0f;


        glm::mat4 modl = glm::mat4(1.0f);
        glm::mat4 trans = glm::translate(modl, modelTrans);

        glm::quat q = glm::quat(glm::vec3(glm::radians(modelRot.x), glm::radians(modelRot.y), glm::radians(modelRot.z)));
        glm::mat4 rotation = glm::mat4_cast(q);

        glm::mat4 scale = glm::scale(modl, modelScale);

        modl = trans * rotation * scale;

        float camX = sin(glfwGetTime()) * 2.0f;
        float camZ = cos(glfwGetTime()) * 2.0f;

        glm::mat4 view;

        view = glm::lookAt( glm::vec3(0.0f, 0.0f, camZPos),
                            glm::vec3(0.0f, 0.0f, 0.0f),
                            glm::vec3(0.0f, 1.0f, 0.0f)     );

        ImGui::Render();
        int display_w, display_h;
        glfwMakeContextCurrent(window);
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.bind();

        glm::mat3 normalMat = glm::mat3(glm::transpose(glm::inverse(modl)));
        shader.setMatrix3("normalMat", glm::value_ptr(normalMat));

        shader.setMatrix4("model", glm::value_ptr(modl));

        glm::mat4 mvp = proj * view * modl;
        shader.setMatrix4("mvp", glm::value_ptr(mvp));

        shader.setMatrix4("view", glm::value_ptr(view));

        glm::mat4 mv = view * modl;
        shader.setMatrix4("mv", glm::value_ptr(mv));

        shader.setVector3("lightPos", lightPos.x, lightPos.y, lightPos.z);
        shader.setVector4("lightColor", lightColor.x, lightColor.y, lightColor.z, lightColor.w);

        shader.setFloat("attenCoef", attenCoef);
        shader.setFloat("attenLinearFalloff", attenLinearFalloff);
        shader.setFloat("attenSquareFalloff", attenSquareFalloff);

        shader.setFloat("textureBlend", blend);

        shader.setVector4("objectColor", objectColor.x, objectColor.y, objectColor.z, 1.0f);

        shader.setVector4("ambientColor", (float)clear_color.x / 255.0f, (float)clear_color.y / 255.0f, (float)clear_color.z / 255.0f, 1.0f);

        shader.setFloat("ambientIntensity", 0.075f);
        shader.unbind();

        diffuseShader.bind();
        diffuseShader.setInteger("texture0", 0);
        diffuseShader.setMatrix4("mvp", glm::value_ptr(mvp));
        diffuseShader.unbind();

        //tex.Bind();
        diffuse.Bind();
        renderer.Draw(model, shader);
        diffuse.UnBind();
        // renderer.Draw(va, ib, shader);
        //tex.UnBind();

        lightShader.bind();

        glm::mat4 lightModel(1.0f);

        glm::mat4 lightTrans = glm::translate(lightModel, lightPos);

        glm::mat4 lightScale = glm::scale(lightModel, glm::vec3(.15f, .1f, .15f));

        lightModel = lightTrans * lightScale;
        glm::mat4 lightMVP = proj * view * lightModel;

        lightShader.setMatrix4("mvp", glm::value_ptr(lightMVP));
        lightShader.setVector4("objectColor", lightColor.x, lightColor.y, lightColor.z, lightColor.w);
        lightShader.unbind();

        renderer.Draw(va, ib, lightShader);
        
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwMakeContextCurrent(window);

        glfwSwapBuffers(window);
    }

    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}
