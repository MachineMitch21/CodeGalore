
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp> 
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"

#include "LogManager.h"

bool keys[1024];
bool buttons[32];

void window_framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void window_refresh_callback(GLFWwindow* window)
{
    glfwSwapBuffers(window);
}

void window_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
    ImGuiIO& io = ImGui::GetIO();

    if (!io.WantCaptureKeyboard)
        keys[key] = (action != GLFW_RELEASE);
}

void window_scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
}

void window_mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
    ImGuiIO& io = ImGui::GetIO();

    if (!io.WantCaptureMouse)
        buttons[button] = (action != GLFW_RELEASE);
}

void window_character_callback(GLFWwindow* window, unsigned int codepoint)
{
    ImGui_ImplGlfw_CharCallback(window, codepoint);
    printf("%c", codepoint);
}

int main(int argc, char** argv)
{
    GLFWwindow* window;

    memset(keys, 0, 1024);
    memset(buttons, 0, 32);

    if (!glfwInit())
    {
        LogManager::LogToConsole("GLFW ERROR -- Could not initialize GLFW");
        exit(-1);
    }

#ifdef _APPLE_
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif // _APPLE_

#ifdef _DEBUG
    LogManager::LogToConsole("-- DEBUG MODE --");
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#else
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_FALSE);
#endif // _DEBUG

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);

    window = glfwCreateWindow(800, 600, "RenderingPractice", NULL, NULL);

    if (!window)
    {
        LogManager::LogToConsole("GLFW ERROR -- Could not create GLFW window");
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();

    if (err != GLEW_OK)
    {
        LogManager::LogToConsole("GLEW ERROR -- Could not initialize GLEW");
        exit(-1);
    }

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glfwSetWindowAspectRatio(window, 16, 9);

    glfwSetFramebufferSizeCallback(window, window_framebuffer_size_callback);
    glfwSetWindowRefreshCallback(window, window_refresh_callback);
    glfwSetCharCallback(window, window_character_callback);
    glfwSetKeyCallback(window, window_key_callback);
    glfwSetMouseButtonCallback(window, window_mouse_button_callback);

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui_ImplGlfw_InitForOpenGL(window, false);
    ImGui_ImplOpenGL3_Init();

    ImGui::StyleColorsDark();

    bool test_active = true;

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 proj = glm::perspective(glm::radians(60.0f), 16.0f / 9.0f, 0.1f, 1000.0f);

    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    glm::mat4 mvp = proj * view * model;

    Shader shader("shader.vert", "shader.frag");

    Shader lightShader("flat_color.vert", "flat_color.frag");

    glm::vec3 lightPosition(3.0f, -1.0f, 1.0f);
    glm::vec4 lightColor(1.0f, 1.0f, 1.0f, 1.0f);

    lightShader.bind():
    lightShader.setMatrix4("mvp", glm::value_ptr(mvp));
    lightShader.unbind();

    shader.bind();
    shader.setMatrix4("model", glm::value_ptr(model));
    shader.setMatrix4("view", glm::value_ptr(view));
    shader.setMatrix4("proj", glm::value_ptr(proj));
    shader.setMatrix4("mvp", glm::value_ptr(mvp));
    shader.unbind();

    glFrontFace(GL_CCW);

    float vertices[] =
    {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    unsigned int indices[] = 
    {
        0, 1, 2
    };

    VertexArray va;
    va.Bind();
    VertexBuffer vb(vertices, sizeof(vertices));
    IndexBuffer ib(indices, sizeof(indices) / sizeof(unsigned int));
    VertexBufferLayout layout;
    layout.Push(GL_FLOAT, 3);
    va.AddBuffer(vb, layout);
    va.UnBind();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        if (test_active)
        {
            ImGui::Begin("Test", &test_active, ImGuiWindowFlags_MenuBar);

            if (ImGui::BeginMenuBar())
            {
                if (ImGui::BeginMenu("File"))
                {
                    if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
                    if (ImGui::MenuItem("Save", "Ctrl+S"))   { /* Do stuff */ }
                    if (ImGui::MenuItem("Close", "Ctrl+W"))  { test_active = false; }
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }
                
            // Display contents in a scrolling region
            ImGui::TextColored(ImVec4(1,1,0,1), "Important Stuff");
            ImGui::BeginChild("Scrolling");
            for (int n = 0; n < 50; n++)
                ImGui::Text("%04d: Some text", n);
            ImGui::EndChild();

            ImGui::End();
        }

        ImGui::Render();

        glfwMakeContextCurrent(window);
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        va.Bind();

        shader.bind();

        shader.setVector3("lightPos", lightPosition.x, lightPosition.y, lightPosition.z);
        shader.setVector4("lightColor", lightColor.x, lightColor.y, lightColor.z, lightColor.w);
        shader.setVector4("objectColor", 1.0f, 1.0f, 1.0f, 1.0f);

        glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0);
        shader.unbind();
        
        lightShader.bind();
        glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0);
        lightShader.unbind();

        va.UnBind();


        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwMakeContextCurrent(window);
        glfwSwapBuffers(window);
    }

    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}