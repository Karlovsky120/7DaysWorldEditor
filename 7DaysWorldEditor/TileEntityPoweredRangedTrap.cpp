#include "TileEntityPoweredRangedTrap.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "ItemStack.h"

#include <string>

TileEntityClassId TileEntityPoweredRangedTrap::getType() {
	return PowerRangeTrap;
}

int TileEntityPoweredRangedTrap::read(BinaryMemoryReader &reader) {
	CHECK_VERSION_ZERO(TileEntityPoweredBlock::read(reader));

	if (RangedTrap == powerItemType) {
		reader.read<std::string>(lrz);
	}

	reader.read<bool>(flag);

	if (flag) {
		reader.read<bool>(isLocked);
		CHECK_VERSION_ZERO((reader.readMultipleComplex<ItemStack, unsigned short>(itemSlots)));

		reader.read<int>(targetType);
	}

	return 0;
}

void TileEntityPoweredRangedTrap::write(BinaryMemoryWriter &writer) {
	TileEntityPoweredBlock::write(writer);

	if (RangedTrap == powerItemType) {
		writer.write<std::string>(lrz);
	}

	writer.write<bool>(flag);

	if (flag) {
		writer.write<bool>(isLocked);
		writer.writeMultipleComplex<ItemStack, unsigned short>(itemSlots);

		writer.write<int>(targetType);
	}
}

TileEntityPoweredRangedTrap::TileEntityPoweredRangedTrap() {}
TileEntityPoweredRangedTrap::~TileEntityPoweredRangedTrap() {}