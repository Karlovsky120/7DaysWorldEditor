#include "TileEntityPoweredBlock.h"

#include "BinaryMemoryReader.h"


void TileEntityPoweredBlock::read(BinaryMemoryReader &reader) {
	TileEntityPowered::read(reader);
	reader.read<bool>(uzz);
}

TileEntityPoweredBlock::TileEntityPoweredBlock() {}
TileEntityPoweredBlock::~TileEntityPoweredBlock() {}
