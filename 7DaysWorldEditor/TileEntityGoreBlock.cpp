#include "TileEntityGoreBlock.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntityGoreBlock::getType() {
	return GoreBlock;
}

void TileEntityGoreBlock::read(BinaryMemoryReader &reader) {
	TileEntityLootContainer::read(reader);

	reader.read<unsigned _int64>(arz);
}

void TileEntityGoreBlock::write(BinaryMemoryWriter &writer) {
	TileEntityLootContainer::write(writer);

	writer.write<unsigned _int64>(arz);
}

TileEntityGoreBlock::TileEntityGoreBlock() {}
TileEntityGoreBlock::~TileEntityGoreBlock() {}