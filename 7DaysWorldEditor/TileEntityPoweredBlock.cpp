#include "TileEntityPoweredBlock.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntityPoweredBlock::getType() {
	return Powered;
}

void TileEntityPoweredBlock::read(BinaryMemoryReader &reader) {
	TileEntityPowered::read(reader);

	reader.read<bool>(uzz);
}

void TileEntityPoweredBlock::write(BinaryMemoryWriter &writer) {
	TileEntityPowered::write(writer);

	writer.write<bool>(uzz);
}

TileEntityPoweredBlock::TileEntityPoweredBlock() {}
TileEntityPoweredBlock::~TileEntityPoweredBlock() {}
