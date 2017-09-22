#include "TileEntityPowerSource.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "ItemStack.h"

TileEntityClassId TileEntityPowerSource::getType() {
	return PowerSource;
}

void TileEntityPowerSource::read(BinaryMemoryReader &reader) {
	TileEntityPowered::read(reader);

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

void TileEntityPowerSource::write(BinaryMemoryWriter &writer) {
	TileEntityPowered::write(writer);

	writer.write<bool>(flag);

	if (flag) {
		writer.write<bool>(isOn);

		if (Generator == powerItemType) {
			writer.write<unsigned short>(maxFuel);
			writer.write<unsigned short>(currentFuel);
		} else if (SolarPanel == powerItemType) {
			writer.write<unsigned short>(solarInput);
		}

		writer.writeMultipleComplex<ItemStack, unsigned short>(itemSlots);

		writer.write<unsigned short>(maxOutput);
		writer.write<unsigned short>(lastOutput);
	}
}

TileEntityPowerSource::TileEntityPowerSource() {}
TileEntityPowerSource::~TileEntityPowerSource() {}