#pragma once
#include "src/core/Shader.h"
typedef struct GLFWwindow GLFWwindow;

namespace SG {
	
	class Input;
	class Scene
	{
	public:
		int Run();


	protected:

		virtual void Init() { }

		virtual void OnRender() { }
		virtual void OnUpdate() { }

	private :
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		static GLFWwindow* window;
		
		int InitGL();
		friend Input;

	};
}