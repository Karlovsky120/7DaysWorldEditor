#include "TileEntitySign.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "VersionCheck.h"

TileEntityClassId TileEntitySign::getType() {
	return Sign;
}

int TileEntitySign::read(BinaryMemoryReader &reader) {
	TileEntity::read(reader);

	reader.read<int>(version);
	VersionCheck::checkVersion(version, TILE_ENTITY_SIGN_VER, TILE_ENTITY_SIGN);

	reader.read<bool>(vd);
	reader.read<std::string>(gd);
	reader.read<std::string>(xd);

	reader.readMultipleSimple<std::string, int>(kd);
	reader.read<std::string>(signText);

	return 0;
}

void TileEntitySign::write(BinaryMemoryWriter &writer) const {
	TileEntity::write(writer);

	writer.write<int>(version);

	writer.write<bool>(vd);
	writer.write<std::string>(gd);
	writer.write<std::string>(xd);

	writer.writeMultipleSimple<std::string, int>(kd);
	writer.write<std::string>(signText);
}

TileEntitySign::TileEntitySign() {}
TileEntitySign::~TileEntitySign() {}
