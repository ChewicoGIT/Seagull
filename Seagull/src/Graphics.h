#pragma once
#include "src/core/Shader.h"

namespace SG {
	class Graphics
	{
	public:
		static void Initialize();

	private:
		static Shader* basicShader;
		static bool initialized;

	};

}

