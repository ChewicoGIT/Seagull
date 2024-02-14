#pragma once
#include "src/core/Shader.h"
#include "src/SimpleShapes/Square.h"

namespace SG {

	class RenderObject;

	class Graphics
	{
	public:
		static void Initialize();
		static void DrawObject(RenderObject* object);
		static void DrawSquare() { DrawObject(square); }

	private:
		static Shader* basicShader;
		static Square* square;
		static bool initialized;

	};

}

