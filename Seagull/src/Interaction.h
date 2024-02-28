#pragma once
#include "src/Dimension.h"

namespace SG {
	class Interaction
	{
	public:
		static bool UserCameraPosition(float* xPosition, float* yPosition);
		static bool DirectionalArrow(float xDir, float yDir, float* affectedValue);
		static bool MouseTriggerArea(Dimension* dimensions);

	private:
		//For calculating mouse camera scroll in space
		static bool lastFrameMouseState;
		static float fixedWorldPosX, fixedWorldPosY;
	};
}

