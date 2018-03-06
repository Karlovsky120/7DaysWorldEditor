#include "TileEntityForge.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "VersionCheck.h"

TileEntityClassId TileEntityForge::getType() {
	return Forge;
}

int TileEntityForge::read(BinaryMemoryReader &reader) {
	TileEntity::read(reader);

	reader.read<unsigned _int64>(ib);

	reader.readMultipleComplex<ItemStack, unsigned char>(gb);
	reader.readMultipleComplex<ItemStack, unsigned char>(kb);

	fd.read(reader);
	mb.read(reader);

	reader.read<int>(hb);
	reader.read<short>(qd);
	reader.read<short>(yd);
	VersionCheck::checkVersion(tb.read(reader), ITEM_VALUE_VER, ITEM_VALUE);

	return 0;
}

void TileEntityForge::write(BinaryMemoryWriter &writer) const {
	TileEntity::write(writer);

	writer.write<unsigned _int64>(ib);

	writer.writeMultipleComplex<ItemStack, unsigned char>(gb);
	writer.writeMultipleComplex<ItemStack, unsigned char>(kb);

	fd.write(writer);
	mb.write(writer);

	writer.write<int>(hb);
	writer.write<short>(qd);
	writer.write<short>(yd);
	tb.write(writer);
}

TileEntityForge::TileEntityForge() {}
TileEntityForge::~TileEntityForge() {}
