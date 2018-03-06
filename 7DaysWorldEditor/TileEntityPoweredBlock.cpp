#include "TileEntityPoweredBlock.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntityPoweredBlock::getType() {
	return Powered;
}

int TileEntityPoweredBlock::read(BinaryMemoryReader &reader) {
	TileEntityPowered::read(reader);

	return 0;
}

void TileEntityPoweredBlock::write(BinaryMemoryWriter &writer) const {
	TileEntityPowered::write(writer);
}

TileEntityPoweredBlock::TileEntityPoweredBlock() {}
TileEntityPoweredBlock::~TileEntityPoweredBlock() {}
