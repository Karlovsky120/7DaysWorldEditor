#include "TileEntitySecureLootContainer.h"

#include "BinaryMemoryReader.h"

TileEntitySecureLootContainer *TileEntitySecureLootContainer::read(BinaryMemoryReader *const reader)
{
	TileEntityLootContainer::read(reader);

	reader->read<int>(&version);
	reader->read<bool>(&md);
	reader->read<bool>(&vd);
	reader->read<std::string>(&gd);
	reader->read<std::string>(&xd);

	reader->readMultipleSimple<std::string, int>(kd);

	return this;
}

TileEntitySecureLootContainer::TileEntitySecureLootContainer() {}
TileEntitySecureLootContainer::~TileEntitySecureLootContainer() {}