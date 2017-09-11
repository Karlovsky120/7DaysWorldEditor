#include "TileEntityPowered.h"

#include "BinaryMemoryReader.h"

void TileEntityPowered::read(BinaryMemoryReader &reader) {
	TileEntity::read(reader);
	reader.read<int>(tileEntityPoweredVersion);
	reader.read<bool>(isPlayerPlaced);
	reader.read<unsigned char>(powerItemType);

	unsigned char intVectorCount;
	reader.read<unsigned char>(intVectorCount);

	for (int i = 0; i < intVectorCount; ++i) {
		Coordinate<int> item;
		reader.read<int>(item.x);
		reader.read<int>(item.y);
		reader.read<int>(item.z);

		intVectors.push_back(item);
	}

	reader.read<int>(kzz.x);
	reader.read<int>(kzz.y);
	reader.read<int>(kzz.z);

	reader.read<float>(centeredPitch);
	reader.read<float>(centeredYaw);
}

TileEntityPowered::TileEntityPowered() {}
TileEntityPowered::~TileEntityPowered() {}