#include "TileEntityCampfire.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntityCampfire::getType() {
	return Campfire;
}

void TileEntityCampfire::read(BinaryMemoryReader &reader) {
	TileEntity::read(reader);

	reader.read<unsigned _int64>(ib);

	reader.readMultipleComplex<ItemStack, unsigned char>(gb);
	reader.readMultipleComplex<ItemStack, unsigned char>(kb);

	xb.read(reader);
	mb.read(reader);

	reader.read<int>(hb);

	tb.read(reader);
	reader.read<bool>(isCooking);
	reader.read<float>(db);
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