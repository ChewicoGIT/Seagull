#include "Interaction.h"
#include "src/Input.h"
#include "src/Graphics.h"

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
