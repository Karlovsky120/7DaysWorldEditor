#include "TileEntityPowerSource.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "ItemStack.h"

TileEntityPowerSource::TileEntityPowerSource() {}
TileEntityPowerSource::~TileEntityPowerSource() {}

TileEntityClassId TileEntityPowerSource::getType() const {
	return PowerSource;
}

int TileEntityPowerSource::read(BinaryMemoryReader &reader) {
	TileEntityPowered::read(reader);

	return 0;
}

void TileEntityPowerSource::write(BinaryMemoryWriter &writer) const {
	TileEntityPowered::write(writer);
}
