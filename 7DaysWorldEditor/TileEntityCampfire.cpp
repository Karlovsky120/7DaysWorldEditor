#include "TileEntityCampfire.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntityCampfire::getType() {
	return Campfire;
}

int TileEntityCampfire::read(BinaryMemoryReader &reader) {
	CHECK_VERSION_ZERO(TileEntity::read(reader));

	reader.read<unsigned _int64>(ib);
	CHECK_VERSION_ZERO((reader.readMultipleComplex<ItemStack, unsigned char>(gb, NO_VERSION)));
	CHECK_VERSION_ZERO((reader.readMultipleComplex<ItemStack, unsigned char>(kb, NO_VERSION)));

	CHECK_VERSION_ZERO(xb.read(reader));
	CHECK_VERSION_ZERO(mb.read(reader));

	reader.read<int>(hb);

	CHECK_VERSION(tb.read(reader), ITEM_VALUE);
	reader.read<bool>(isCooking);
	reader.read<float>(db);

	return 0;
}

void TileEntityCampfire::write(BinaryMemoryWriter &writer) {
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

TileEntityCampfire::TileEntityCampfire() {}
TileEntityCampfire::~TileEntityCampfire() {}