#include "TileEntityLootContainer.h"

#include "BinaryMemoryReader.h"
#include "ItemStack.h"

void TileEntityLootContainer::read(BinaryMemoryReader &reader) {
	TileEntity::read(reader);

	reader.read<unsigned short>(lootListIndex);
	reader.read<unsigned short>(ad.x);
	reader.read<unsigned short>(ad.y);

	reader.read<bool>(bTouched);
	reader.read<unsigned int>(worldTimeTouched);
	reader.read<bool>(bPlayerBackpack);

	short itemsLength;
	reader.read<short>(itemsLength);
	itemsLength = ((((int)itemsLength) < (ad.x * ad.y)) ? itemsLength : (ad.x * ad.y));

	reader.readMultipleComplex<ItemStack, short>(items, itemsLength);
	reader.read<bool>(bPlayerStorage);
}

TileEntityLootContainer::TileEntityLootContainer() {}
TileEntityLootContainer::~TileEntityLootContainer() {}