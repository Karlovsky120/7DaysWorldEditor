#include "TileEntityLootContainer.h"

#include "BinaryMemoryReader.h"
#include "ItemStack.h"

TileEntityLootContainer *TileEntityLootContainer::read(BinaryMemoryReader *const reader)
{
	TileEntity::read(reader);

	reader->read<unsigned short>(&lootListIndex);
	reader->read<unsigned short>(&ad.x);
	reader->read<unsigned short>(&ad.y);

	reader->read<bool>(&bTouched);
	reader->read<unsigned int>(&worldTimeTouched);
	reader->read<bool>(&bPlayerBackpack);

	short *itemsLength;
	reader->read<short>(&itemsLength);
	*itemsLength = std::min((int)*itemsLength, *ad.x * *ad.y);

	reader->readMultipleComplex<ItemStack, short>(items, itemsLength);
	reader->read<bool>(&bPlayerStorage);

	return this;
}

TileEntityLootContainer::TileEntityLootContainer() {}
TileEntityLootContainer::~TileEntityLootContainer() {}