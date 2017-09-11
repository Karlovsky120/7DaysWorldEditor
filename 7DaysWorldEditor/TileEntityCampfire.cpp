#include "TileEntityCampfire.h"

#include "BinaryMemoryReader.h"
#include "ItemStack.h"
#include "ItemValue.h"

void TileEntityCampfire::read(BinaryMemoryReader &reader)
{
	TileEntity::read(reader);

	reader.read<unsigned _int64>(ib);

	reader.readMultipleComplex<ItemStack, unsigned char>(gb);
	reader.readMultipleComplex<ItemStack, unsigned char>(kb);

	xb.read(reader);
	mb.read(reader);

	reader.read<int>(hb);

	tb.read(reader);
	reader.read<bool>(isCooking);
	reader.read<float>(db);
}

TileEntityCampfire::TileEntityCampfire() {}
TileEntityCampfire::~TileEntityCampfire() {}