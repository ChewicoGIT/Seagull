#pragma once
#include <GLFW/glfw3.h>

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