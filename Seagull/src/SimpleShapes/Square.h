#pragma once
#include "src/core/RenderObject.h"

namespace SG {
	class Square : public SG::RenderObject 
	{
	public:
		Square();

	private:
		unsigned int VBO;

	};
}

