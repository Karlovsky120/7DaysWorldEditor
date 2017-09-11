#include "TileEntityPowerSource.h"

#include "BinaryMemoryReader.h"
#include "ItemStack.h"


void TileEntityPowerSource::reader(BinaryMemoryReader &reader) {
	TileEntityPowered::read(reader);

	bool flag;
	reader.read<bool>(flag);

	if (flag) {
		reader.read<bool>(isOn);

		if (Generator == powerItemType) {
			reader.read<unsigned short>(maxFuel);
			reader.read<unsigned short>(currentFuel);
		} else if (SolarPanel == powerItemType) {
			reader.read<unsigned short>(solarInput);
		}

		reader.readMultipleComplex<ItemStack, unsigned short>(itemSlots);

		reader.read<unsigned short>(maxOutput);
		reader.read<unsigned short>(lastOutput);
	}
}

TileEntityPowerSource::TileEntityPowerSource() {}
TileEntityPowerSource::~TileEntityPowerSource() {}