#include "SpawnPoint.h"

#include "BinaryMemoryReader.h"

void SpawnPoint::read(BinaryMemoryReader &reader) {	
	reader.read<int>(pos.x);
	reader.read<int>(pos.y);
	reader.read<int>(pos.z);

	reader.read<float>(look.x);
	reader.read<float>(look.y);
	reader.read<float>(look.z);

	reader.read<float>(rot);
	reader.read<unsigned char>(pose);
	reader.read<unsigned short>(blockID);
}

SpawnPoint::SpawnPoint() {}
SpawnPoint::~SpawnPoint() {}