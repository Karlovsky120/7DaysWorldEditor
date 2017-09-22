#include "TileEntitySecure.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntitySecure::getType() {
	return TileEntityBase;
}

void TileEntitySecure::read(BinaryMemoryReader &reader) {
	TileEntityLootContainer::read(reader);

	reader.read<int>(version);
	reader.read<bool>(md);
	reader.read<bool>(vd);
	reader.read<std::string>(gd);

	reader.readMultipleSimple<std::string, int>(kd);
	reader.read<std::string>(xd);
}

void TileEntitySecure::write(BinaryMemoryWriter &writer) {
	TileEntityLootContainer::write(writer);

	writer.write<int>(version);
	writer.write<bool>(md);
	writer.write<bool>(vd);
	writer.write<std::string>(gd);

	writer.writeMultipleSimple<std::string, int>(kd);
	writer.write<std::string>(xd);
}

TileEntitySecure::TileEntitySecure() {}
TileEntitySecure::~TileEntitySecure() {}