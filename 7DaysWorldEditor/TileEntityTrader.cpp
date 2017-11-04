#include "TileEntityTrader.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntityTrader::getType() {
	return Trader;
}

int TileEntityTrader::read(BinaryMemoryReader &reader) {
	CHECK_VERSION_ZERO(TileEntity::read(reader));

	reader.read<int>(version);
	CHECK_VERSION(version, TILE_ENTITY_TRADER);

	traderData.read(reader);

	return 0;
}

void TileEntityTrader::write(BinaryMemoryWriter &writer) {
	TileEntity::write(writer);

	writer.write<int>(version);
	traderData.write(writer);
}

TileEntityTrader::TileEntityTrader() {}
TileEntityTrader::~TileEntityTrader() {}