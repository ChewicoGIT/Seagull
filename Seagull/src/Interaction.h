#pragma once
namespace SG {
	class Interaction
	{
	public:
		static bool UserCameraPosition(float* xPosition, float* yPosition);

	private:
		//For calculating mouse camera scroll in space
		static bool lastFrameMouseState;
		static float fixedWorldPosX, fixedWorldPosY;
	};
}

