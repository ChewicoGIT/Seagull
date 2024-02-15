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

	private:
		static void Initialize();
		static Shader* basicShader;
		static Square* square;

		friend Scene;

	};

}

