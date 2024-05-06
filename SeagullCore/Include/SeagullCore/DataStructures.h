#pragma once
#include <cstdint>

namespace sgc {
	class VoxelDatabase;

	struct SceneData {
		int chunkSizeX = 5, chunkSizeY = 2, chunkSizeZ = 5;

	};

}

namespace vs {
	struct VoxelData {
		uint16_t blockID = 0;
		uint16_t lightInfo = 0;
	};
}