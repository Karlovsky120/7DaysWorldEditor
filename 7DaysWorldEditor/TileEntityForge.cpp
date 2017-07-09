#include "TileEntityForge.h"

#include "BinaryMemoryReader.h"
#include "ItemStack.h"
#include "ItemValue.h"

TileEntityForge *TileEntityForge::read(BinaryMemoryReader *const reader)
{
	TileEntity::read(reader);

	reader->read<unsigned _int64>(&ib);

	reader->readMultipleComplex<ItemStack, unsigned char>(gb);
	reader->readMultipleComplex<ItemStack, unsigned char>(kb);

	fd = new ItemStack();
	fd->read(reader);
	mb = new ItemStack();
	mb->read(reader);

	reader->read<int>(&hb);
	reader->read<short>(&qd);
	reader->read<short>(&yd);
	tb = new ItemValue();
	tb->read(reader);

	return this;
}

TileEntityForge::TileEntityForge() {}
TileEntityForge::~TileEntityForge() {}