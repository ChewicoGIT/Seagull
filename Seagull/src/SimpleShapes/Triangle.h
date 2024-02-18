#pragma once
#include "src/core/RenderObject.h"

namespace SG {
	class Triangle : public SG::RenderObject
	{
	public:
		Triangle();

	private:
		unsigned int VBO;

	};
}