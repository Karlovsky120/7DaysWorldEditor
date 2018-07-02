#include "TileEntitySecure.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "VersionCheck.h"

TileEntitySecure::TileEntitySecure() {}
TileEntitySecure::~TileEntitySecure() {}

TileEntityClassId TileEntitySecure::getType() const {
    return TileEntityBase;
}

int TileEntitySecure::read(BinaryMemoryReader &reader) {
    TileEntityLootContainer::read(reader);

    reader.read<int>(version);
    VersionCheck::checkVersion(version, TILE_ENTITY_SECURE_VER, TILE_ENTITY_SECURE);

    reader.read<bool>(md);
    reader.read<bool>(vd);
    reader.read<std::string>(gd);

    reader.readMultipleSimple<std::string, int>(kd);
    reader.read<std::string>(xd);

    return 0;
}

void TileEntitySecure::write(BinaryMemoryWriter &writer) const {
    TileEntityLootContainer::write(writer);

    writer.write<int>(version);
    writer.write<bool>(md);
    writer.write<bool>(vd);
    writer.write<std::string>(gd);

    writer.writeMultipleSimple<std::string, int>(kd);
    writer.write<std::string>(xd);
}
