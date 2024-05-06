#include "SeagullCore/Scene.h"


sgc::Scene::Scene(SceneData _sceneData)
	: sceneData(_sceneData)
{

}

unsigned int sgc::Scene::getTickCount() {
	return tickCount;
}

inline VoxelData sgc::Scene::getVoxel(int x, int y, int z)
{
	return VoxelData();
}
