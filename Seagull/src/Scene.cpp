#pragma once
#include "Scene.h"
#include <iostream>

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include "src/Graphics.h"

GLFWwindow* SG::Scene::window;

int SG::Scene::Run() {

    int initGlResult = InitGL();
    if (initGlResult != 0)
        return initGlResult;

	Init();

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        OnRender();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

int SG::Scene::InitGL() {

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, "Seagull", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    glViewport(0, 0, 800, 600);

    glClearColor(0.01f, 0.12f, 0.18f, 1.0f);

    SG::Graphics::Initialize();
    
    return 0;

}