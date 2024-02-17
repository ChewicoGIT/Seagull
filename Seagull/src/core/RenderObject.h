#pragma once

namespace SG {

	class Graphics;

	class RenderObject
	{
	protected:
		unsigned int VAO;
		unsigned int IBO;

		friend Graphics;
	};
}

