#include "TileEntityTrader.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntityTrader::getType() {
	return Trader;
}

void TileEntityTrader::read(BinaryMemoryReader &reader) {
	TileEntity::read(reader);

	reader.read<int>(version);
	traderData.read(reader);
}

void TileEntityTrader::write(BinaryMemoryWriter &writer) {
	TileEntity::write(writer);

	writer.write<int>(version);
	traderData.write(writer);
}

TileEntityTrader::TileEntityTrader() {}
TileEntityTrader::~TileEntityTrader() {}