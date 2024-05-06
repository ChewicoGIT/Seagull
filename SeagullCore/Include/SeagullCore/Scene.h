#pragma once

namespace sgc {
	class Scene
	{
	public:
		Scene();

		unsigned int getTickCount();

	private:

		unsigned int tickCount = 0;

	};
}


