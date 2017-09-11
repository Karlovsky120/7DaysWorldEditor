#include "TileEntityGoreBlock.h"

#include "BinaryMemoryReader.h"

void TileEntityGoreBlock::read(BinaryMemoryReader &reader) {
	TileEntityLootContainer::read(reader);
	reader.read<unsigned _int64>(arz);
}

TileEntityGoreBlock::TileEntityGoreBlock() {}
TileEntityGoreBlock::~TileEntityGoreBlock() {}