#include "TileEntityTrader.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "VersionCheck.h"

TileEntityTrader::TileEntityTrader() {}
TileEntityTrader::~TileEntityTrader() {}

TileEntityClassId TileEntityTrader::getType() const {
    return Trader;
}

int TileEntityTrader::read(BinaryMemoryReader &reader) {
    TileEntity::read(reader);

    reader.read<int>(version);
    VersionCheck::checkVersion(version, TILE_ENTITY_TRADER_VER, TILE_ENTITY_TRADER);

    traderData.read(reader);

    return 0;
}

void TileEntityTrader::write(BinaryMemoryWriter &writer) const {
    TileEntity::write(writer);

    writer.write<int>(version);
    traderData.write(writer);
}
