#include "TileEntityGoreBlock.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityGoreBlock::TileEntityGoreBlock() {}
TileEntityGoreBlock::~TileEntityGoreBlock() {}

TileEntityClassId TileEntityGoreBlock::getType() const {
    return GoreBlock;
}

int TileEntityGoreBlock::read(BinaryMemoryReader &reader) {
    TileEntityLootContainer::read(reader);
    reader.read<unsigned _int64>(arz);

    return 0;
}

void TileEntityGoreBlock::write(BinaryMemoryWriter &writer) const {
    TileEntityLootContainer::write(writer);

    writer.write<unsigned _int64>(arz);
}
