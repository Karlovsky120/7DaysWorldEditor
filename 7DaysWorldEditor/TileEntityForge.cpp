#include "TileEntityForge.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntityForge::getType() {
	return Forge;
}

int TileEntityForge::read(BinaryMemoryReader &reader) {
	CHECK_VERSION_ZERO(TileEntity::read(reader));

	reader.read<unsigned _int64>(ib);

	CHECK_VERSION_ZERO((reader.readMultipleComplex<ItemStack, unsigned char>(gb, NO_VERSION)));
	CHECK_VERSION_ZERO((reader.readMultipleComplex<ItemStack, unsigned char>(kb, NO_VERSION)));

	CHECK_VERSION_ZERO(fd.read(reader));
	CHECK_VERSION_ZERO(mb.read(reader));

	reader.read<int>(hb);
	reader.read<short>(qd);
	reader.read<short>(yd);
	CHECK_VERSION(tb.read(reader), ITEM_VALUE);

	return 0;
}

void TileEntityForge::write(BinaryMemoryWriter &writer) {
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