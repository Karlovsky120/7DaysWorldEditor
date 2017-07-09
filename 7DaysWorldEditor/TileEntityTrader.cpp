#include "TileEntityTrader.h"

#include "BinaryMemoryReader.h"

TileEntityTrader *TileEntityTrader::read(BinaryMemoryReader *const reader) {

	TileEntity::read(reader);

	reader->read<int>(&version);
	traderData.read(reader);

	return this;
}

TileEntityTrader::TileEntityTrader() {}
TileEntityTrader::~TileEntityTrader() {}