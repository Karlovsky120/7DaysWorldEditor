#include "TileEntitySecure.h"

#include "BinaryMemoryReader.h"


TileEntitySecure *TileEntitySecure::read(BinaryMemoryReader *const reader)
{
	TileEntityLootContainer::read(reader);

	reader->read<int>(&version);
	reader->read<bool>(&md);
	reader->read<bool>(&vd);
	reader->read<std::string>(&gd);

	reader->readMultipleSimple<std::string, int>(kd);
	reader->read<std::string>(&xd);

	return this;
}

TileEntitySecure::TileEntitySecure() {}
TileEntitySecure::~TileEntitySecure() {}