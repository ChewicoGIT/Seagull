#include "Interaction.h"
#include "src/Input.h"
#include "src/Graphics.h"

#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <iostream>
#include <cmath>

bool SG::Interaction::lastFrameMouseState = false;
float SG::Interaction::fixedWorldPosX;
float SG::Interaction::fixedWorldPosY;

bool SG::Interaction::UserCameraPosition(float* xPosition, float* yPosition)
{
	bool isMousePressed = SG::Input::GetMouseButton();
	if (!isMousePressed) {
		lastFrameMouseState = false;
		return false;
	}

	float mouseX, mouseY;
	SG::Input::GetCursorPositionOnSpace(&mouseX, &mouseY);

	if (!lastFrameMouseState) {
		fixedWorldPosX = mouseX;
		fixedWorldPosY = mouseY;
		lastFrameMouseState = true;
		return false;
	}

	*xPosition = -mouseX + SG::Graphics::GetCameraXCenter() + fixedWorldPosX;
	*yPosition = -mouseY + SG::Graphics::GetCameraYCenter() + fixedWorldPosY;

	return true;
}

bool SG::Interaction::DirectionalArrow(float xDir, float yDir, float* affectedValue)
{


	return false;
}

bool SG::Interaction::MouseTriggerArea(Dimension* dimension)
{
	float mouseX, mouseY;
	if (!Input::GetMouseButton())
		return false;
	Input::GetCursorPositionOnSpace(&mouseX, &mouseY);

	//Generate transformations
	glm::mat4 transformation = glm::scale(glm::mat4(1.0f), glm::vec3(dimension->sizeX, dimension->sizeY, 1.0f));
	transformation = glm::rotate(glm::mat4(1.0f), dimension->rotation, glm::vec3(0, 0, 1.0f)) * transformation;
	transformation = glm::translate(glm::mat4(1.0f), glm::vec3(dimension->positionX, dimension->positionY, 0.0f)) * transformation;
	glm::mat4 inverseTransform = glm::inverse(transformation);
	glm::vec3 mouseRelativePosition = inverseTransform * glm::vec4(mouseX, mouseY, 0, 1.0f);

	if (mouseRelativePosition.x >= 0 &&
		mouseRelativePosition.x <= 1 &&
		mouseRelativePosition.y >= 0 &&
		mouseRelativePosition.y <= 1)
		return true;

	return false;
}
