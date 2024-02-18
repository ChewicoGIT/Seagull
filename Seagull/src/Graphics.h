#pragma once
#include "src/core/Shader.h"
#include "src/SimpleShapes/Square.h"
#include "src/SimpleShapes/Triangle.h"
#include "src/Dimension.h"

namespace SG {

	class Scene;
	class RenderObject;

	class Graphics
	{

	private:

		static inline void SetDimensions(float sizeX, float sizeY, float posX, float posY);

		static void Initialize();
		static void PreRender();
		static Shader* basicShader;
		static Square* square;
		static Triangle* triangle;

		static int screenWidth, screenHeight;
		static float xCenter, yCenter;
		static float height;
		static int frameCount;

		friend Scene;

	public:
		static void DrawObject(RenderObject* object, Dimension* dimension);
		static void DrawSquare(Dimension* dimension) { DrawObject(square, dimension); }
		static void DrawTriangle(Dimension* dimension) { DrawObject(triangle, dimension); }

		static void DrawInfiniteGrid(float thickness, float spacing);
		static void SetColor(float r, float g, float b, float a);
		static void SetCamera(float height, float xCenter, float yCenter);

		static inline float GetScreenWidth() { return screenWidth; }
		static inline float GetScreenHeight() { return screenHeight; }
		static inline int GetFrame() { return frameCount; }
		static inline float GetCameraHeight() { return height; }
		static inline float GetCameraXCenter() { return xCenter; }
		static inline float GetCameraYCenter() { return yCenter; }


	};

}

