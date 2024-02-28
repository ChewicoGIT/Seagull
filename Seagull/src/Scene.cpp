#pragma once
#include "Scene.h"
#include <iostream>

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include "src/Graphics.h"

#include <chrono>
#include <thread> 

using namespace std::chrono;
GLFWwindow* SG::Scene::window;

int SG::Scene::Run() {

    int initGlResult = InitGL();
    if (initGlResult != 0)
        return initGlResult;

	Init();

    const double targetFrameDuration = 1.0 / 60.0;
    steady_clock::time_point lastFrameTime = steady_clock::now();
    double deltaTime = 0.0;

    while (!glfwWindowShouldClose(window))
    {
        // Calculate time elapsed since last frame
        steady_clock::time_point currentFrameTime = steady_clock::now();
        duration<double> timeElapsed = duration_cast<duration<double>>(currentFrameTime - lastFrameTime);
        deltaTime += timeElapsed.count();
        lastFrameTime = currentFrameTime;

        // Render only if enough time has passed
        if (deltaTime >= targetFrameDuration)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            SG::Graphics::PreRender();

            OnRender();

            glfwSwapBuffers(window);

            // Reset delta time for next frame
            deltaTime -= targetFrameDuration;

            Graphics::frameCount++;
            glfwPollEvents();
        }
        else
        {
            // Sleep to cap frame rate
            std::this_thread::sleep_for(milliseconds(1));
        }
    }

    glfwTerminate();
    return 0;
}

int SG::Scene::InitGL() {

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, "Seagull", NULL, NULL);
    if (!window)
    {
        std::cout << "Error at creating window";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    Graphics::screenWidth = 800;
    Graphics::screenHeight = 600;
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, &framebuffer_size_callback);

    glClearColor(0.01f, 0.04f, 0.08f, 1.0f);

    SG::Graphics::Initialize();

    SG::Graphics::SetCamera(8, 0, 0);

    glfwWindowHint(GLFW_SAMPLES, 8);
    glEnable(GL_MULTISAMPLE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    return 0;

}

void SG::Scene::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    Graphics::screenWidth = width;
    Graphics::screenHeight = height;
    glViewport(0, 0, width, height);
}
