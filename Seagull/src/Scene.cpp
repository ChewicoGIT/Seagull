#pragma once
#include "Scene.h"
#include <iostream>

int SG::Scene::Run() {

    int initGlResult = InitGL();
    if (initGlResult != 0)
        return initGlResult;

	Init();

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

int SG::Scene::InitGL() {

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "Seagull", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    return 0;

}