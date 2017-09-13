#include "TileEntityForge.h"

#include "BinaryMemoryReader.h"

void TileEntityForge::read(BinaryMemoryReader &reader) {
	TileEntity::read(reader);

	reader.read<unsigned _int64>(ib);

	reader.readMultipleComplex<ItemStack, unsigned char>(gb);
	reader.readMultipleComplex<ItemStack, unsigned char>(kb);

	fd.read(reader);
	mb.read(reader);

	reader.read<int>(hb);
	reader.read<short>(qd);
	reader.read<short>(yd);
	tb.read(reader);
}

TileEntityForge::TileEntityForge() {}
TileEntityForge::~TileEntityForge() {}