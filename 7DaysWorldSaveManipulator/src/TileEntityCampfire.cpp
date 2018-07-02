#include "TileEntityCampfire.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "VersionCheck.h"

TileEntityCampfire::TileEntityCampfire() {}
TileEntityCampfire::~TileEntityCampfire() {}

TileEntityClassId TileEntityCampfire::getType() const {
    return Campfire;
}

int TileEntityCampfire::read(BinaryMemoryReader &reader) {
    TileEntity::read(reader);

    reader.read<unsigned _int64>(ib);
    reader.readMultipleComplex<ItemStack, unsigned char>(gb);
    reader.readMultipleComplex<ItemStack, unsigned char>(kb);

    xb.read(reader);
    mb.read(reader);

    reader.read<int>(hb);

    VersionCheck::checkVersion(tb.read(reader), ITEM_VALUE_VER, ITEM_VALUE);
    reader.read<bool>(isCooking);
    reader.read<float>(db);

    return 0;
}

void TileEntityCampfire::write(BinaryMemoryWriter &writer) const {
    TileEntity::write(writer);

    writer.write<unsigned _int64>(ib);

    writer.writeMultipleComplex<ItemStack, unsigned char>(gb);
    writer.writeMultipleComplex<ItemStack, unsigned char>(kb);

    xb.write(writer);
    mb.write(writer);

    writer.write<int>(hb);

    tb.write(writer);
    writer.write<bool>(isCooking);
    writer.write<float>(db);
}
