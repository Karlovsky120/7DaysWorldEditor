#include "TileEntitySecureLootContainer.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntitySecureLootContainer::getType() {
	return SecureLoot;
}

int TileEntitySecureLootContainer::read(BinaryMemoryReader &reader) {
	CHECK_VERSION_ZERO(TileEntityLootContainer::read(reader));

	reader.read<int>(version);
	CHECK_VERSION(version, TILE_ENTITY_SECURE_LOOT_CONTAINER);

	reader.read<bool>(md);
	reader.read<bool>(vd);
	reader.read<std::string>(gd);
	reader.read<std::string>(xd);

	reader.readMultipleSimple<std::string, int>(kd);

	return 0;
}

void TileEntitySecureLootContainer::write(BinaryMemoryWriter &writer) {
	TileEntityLootContainer::write(writer);

	writer.write<int>(version);
	writer.write<bool>(md);
	writer.write<bool>(vd);
	writer.write<std::string>(gd);
	writer.write<std::string>(xd);

	writer.writeMultipleSimple<std::string, int>(kd);
}

TileEntitySecureLootContainer::TileEntitySecureLootContainer() {}
TileEntitySecureLootContainer::~TileEntitySecureLootContainer() {}