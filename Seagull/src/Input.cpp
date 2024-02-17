#include "Input.h"
#include "GLFW/glfw3.h"
#include "src/Scene.h"
#include "src/Graphics.h"

void SG::Input::GetCursorPositionOnSpace(float* xPosition, float* yPosition)
{
	double xpos, ypos;
	glfwGetCursorPos(Scene::window, &xpos, &ypos);
	
	xpos /= SG::Graphics::GetScreenHeight();
	ypos /= SG::Graphics::GetScreenHeight();

	xpos -= ((float)SG::Graphics::GetScreenWidth() / (float)SG::Graphics::GetScreenHeight()) / 2.0f;
	ypos -= 0.5f;

	xpos *= SG::Graphics::GetCameraHeight();
	ypos *= -SG::Graphics::GetCameraHeight();

	xpos += SG::Graphics::GetCameraXCenter();
	ypos += SG::Graphics::GetCameraYCenter();

	*xPosition = xpos;
	*yPosition = ypos;

}
