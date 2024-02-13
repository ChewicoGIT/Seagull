#pragma once
#include "src/core/Shader.h"
typedef struct GLFWwindow GLFWwindow;

namespace SG {

	class Scene
	{
	public:
		int Run();

	protected:

		virtual void Init() { }

		virtual void OnRender() { }
		virtual void OnUpdate() { }

	private :

		static GLFWwindow* window;
		
		int InitGL();

	};
}