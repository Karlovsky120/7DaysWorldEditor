#include "TileEntityPoweredBlock.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityPoweredBlock::TileEntityPoweredBlock() {}
TileEntityPoweredBlock::~TileEntityPoweredBlock() {}

TileEntityClassId TileEntityPoweredBlock::getType() const {
    return Powered;
}

int TileEntityPoweredBlock::read(BinaryMemoryReader &reader) {
    TileEntityPowered::read(reader);

    return 0;
}

void TileEntityPoweredBlock::write(BinaryMemoryWriter &writer) const {
    TileEntityPowered::write(writer);
}
