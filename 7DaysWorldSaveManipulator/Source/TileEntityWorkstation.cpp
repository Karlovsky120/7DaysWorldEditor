#include "TileEntityWorkstation.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "VersionCheck.h"

TileEntityClassId TileEntityWorkstation::getType() {
	return Workstation;
}

int TileEntityWorkstation::read(BinaryMemoryReader &reader) {
	TileEntity::read(reader);

	reader.read<unsigned char>(version);
	VersionCheck::checkVersion(version, TILE_ENTITY_WORKSTATION_VER, TILE_ENTITY_WORKSTATION);
	reader.read<unsigned _int64>(ib);

	reader.readMultipleComplex<ItemStack, unsigned char>(gb);
	reader.readMultipleComplex<ItemStack, unsigned char>(kb);
	reader.readMultipleComplex<ItemStack, unsigned char>(eg);
	reader.readMultipleComplex<ItemStack, unsigned char>(mb);
	reader.readMultipleComplex<RecipeQueueItem, unsigned char>(oe);

	reader.read<bool>(ye);
	reader.read<float>(fe);

	reader.readMultipleSimple<float, unsigned char>(qe);

	reader.read<bool>(yhh);

	return 0;
}

void TileEntityWorkstation::write(BinaryMemoryWriter &writer) const {
	TileEntity::write(writer);

	writer.write<unsigned char>(version);
	writer.write<unsigned _int64>(ib);

	writer.writeMultipleComplex<ItemStack, unsigned char>(gb);
	writer.writeMultipleComplex<ItemStack, unsigned char>(kb);
	writer.writeMultipleComplex<ItemStack, unsigned char>(eg);
	writer.writeMultipleComplex<ItemStack, unsigned char>(mb);
	writer.writeMultipleComplex<RecipeQueueItem, unsigned char>(oe);

	writer.write<bool>(ye);
	writer.write<float>(fe);

	writer.writeMultipleSimple<float, unsigned char>(qe);

	writer.write<bool>(yhh);
}

TileEntityWorkstation::TileEntityWorkstation() {}
TileEntityWorkstation::~TileEntityWorkstation() {}
