#pragma once

namespace SG {
	class Graphics;

	class Shader
	{

	public:
		Shader();
		~Shader();
	private:
		unsigned int shaderProgram;
		void Use();

		friend Graphics;

	};
}

