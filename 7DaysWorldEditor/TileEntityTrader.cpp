#include "TileEntityTrader.h"

#include "BinaryMemoryReader.h"

void TileEntityTrader::read(BinaryMemoryReader &reader) {
	TileEntity::read(reader);

	reader.read<int>(version);
	traderData.read(reader);
}

TileEntityTrader::TileEntityTrader() {}
TileEntityTrader::~TileEntityTrader() {}