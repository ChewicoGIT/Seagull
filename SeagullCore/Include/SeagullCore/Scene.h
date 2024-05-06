#pragma once
#include "DataStructures.h"

namespace sgc {
	class Scene
	{
	public:
		Scene(SceneData sceneData);
		unsigned int getTickCount();

	private:
		unsigned int tickCount = 0;
		SceneData sceneData;
		
		VoxelDatabase* voxelDatabase;
		
	};
}


