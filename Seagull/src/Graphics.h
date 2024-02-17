#pragma once
#include "src/core/Shader.h"
#include "src/SimpleShapes/Square.h"

namespace SG {

	class Scene;
	class RenderObject;

	class Graphics
	{
	public:
		static void DrawObject(RenderObject* object);
		static void DrawSquare() { DrawObject(square); }
		static void SetColor(float r, float g, float b, float a);
		static void SetDimensions(float sizeX, float sizeY, float posX, float posY);
		static void SetCamera(float height, float xCenter, float yCenter);

		static float GetScreenWidth() { return screenWidth; }
		static float GetScreenHeight() { return screenHeight; }
		static int GetFrame() { return frameCount; }

	private:
		static void Initialize();
		static void PreRender();
		static Shader* basicShader;
		static Square* square;

		static int screenWidth, screenHeight;
		static float xCenter, yCenter;
		static float height;
		static int frameCount;

		friend Scene;

	};

}

