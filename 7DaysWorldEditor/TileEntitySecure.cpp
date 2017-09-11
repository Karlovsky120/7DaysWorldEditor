#include "TileEntitySecure.h"

#include "BinaryMemoryReader.h"


void TileEntitySecure::read(BinaryMemoryReader &reader) {
	TileEntityLootContainer::read(reader);

	reader.read<int>(version);
	reader.read<bool>(md);
	reader.read<bool>(vd);
	reader.read<std::string>(gd);

	reader.readMultipleSimple<std::string, int>(kd);
	reader.read<std::string>(xd);
}

TileEntitySecure::TileEntitySecure() {}
TileEntitySecure::~TileEntitySecure() {}