#include "TileEntityPowered.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntityPowered::getType() {
	return TileEntityBase;
}

int TileEntityPowered::read(BinaryMemoryReader &reader) {
	CHECK_VERSION_ZERO(TileEntity::read(reader));

	reader.read<int>(tileEntityPoweredVersion);
	CHECK_VERSION(tileEntityPoweredVersion, TILE_ENTITY_POWERED);

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

	return 0;
}

void TileEntityPowered::write(BinaryMemoryWriter &writer) {
	TileEntity::write(writer);
	writer.write<int>(tileEntityPoweredVersion);
	writer.write<bool>(isPlayerPlaced);
	writer.write<unsigned char>(powerItemType);

#pragma warning (suppress: 4267)
	writer.writeConst<unsigned char>(intVectors.size());

	for (unsigned int i = 0; i < intVectors.size(); ++i) {
		Coordinate<int> item = intVectors[i];
		writer.write<int>(item.x);
		writer.write<int>(item.y);
		writer.write<int>(item.z);
	}

	writer.write<int>(kzz.x);
	writer.write<int>(kzz.y);
	writer.write<int>(kzz.z);

	writer.write<float>(centeredPitch);
	writer.write<float>(centeredYaw);
}

TileEntityPowered::TileEntityPowered() {}
TileEntityPowered::~TileEntityPowered() {}