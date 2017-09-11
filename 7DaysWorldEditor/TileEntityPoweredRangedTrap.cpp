#include "TileEntityPoweredRangedTrap.h"

#include "BinaryMemoryReader.h"
#include "ItemStack.h"

#include <string>

void TileEntityPoweredRangedTrap::read(BinaryMemoryReader &reader) {
	TileEntityPoweredBlock::read(reader);

	if (RangedTrap == powerItemType) {
		reader.read<std::string>(lrz);
	}

	bool flag;
	reader.read<bool>(flag);

	if (flag) {
		reader.read<bool>(isLocked);
		reader.readMultipleComplex<ItemStack, unsigned short>(itemSlots);

		reader.read<int>(targetType);
	}
}

TileEntityPoweredRangedTrap::TileEntityPoweredRangedTrap() {}
TileEntityPoweredRangedTrap::~TileEntityPoweredRangedTrap() {}