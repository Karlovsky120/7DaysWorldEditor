#include "TileEntityCampfire.h"

#include "BinaryMemoryReader.h"
#include "ItemStack.h"
#include "ItemValue.h"

TileEntityCampfire *TileEntityCampfire::read(BinaryMemoryReader *const reader)
{
	TileEntity::read(reader);

	reader->read<unsigned _int64>(&ib);

	reader->readMultipleComplex<ItemStack, unsigned char>(gb);
	reader->readMultipleComplex<ItemStack, unsigned char>(kb);

	xb = new ItemStack();
	xb->read(reader);
	mb = new ItemStack();
	mb->read(reader);

	reader->read<int>(&hb);
	tb = new ItemValue();
	tb->read(reader);
	reader->read<bool>(&isCooking);
	reader->read<float>(&db);

	return this;
}

TileEntityCampfire::TileEntityCampfire() {}
TileEntityCampfire::~TileEntityCampfire() {}