#include "TileEntityPoweredBlock.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntityPoweredBlock::getType() {
	return Powered;
}

int TileEntityPoweredBlock::read(BinaryMemoryReader &reader) {
	CHECK_VERSION_ZERO(TileEntityPowered::read(reader));

	//reader.read<bool>(uzz);

	return 0;
}

void TileEntityPoweredBlock::write(BinaryMemoryWriter &writer) {
	TileEntityPowered::write(writer);

	//writer.write<bool>(uzz);
}

TileEntityPoweredBlock::TileEntityPoweredBlock() {}
TileEntityPoweredBlock::~TileEntityPoweredBlock() {}
