#include "TileEntityWorkstation.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntityWorkstation::getType() {
	return Workstation;
}

int TileEntityWorkstation::read(BinaryMemoryReader &reader) {	
	CHECK_VERSION_ZERO(TileEntity::read(reader));

	reader.read<unsigned char>(version);
	CHECK_VERSION(version, TILE_ENTITY_WORKSTATION);
	reader.read<unsigned _int64>(ib);

	CHECK_VERSION_ZERO((reader.readMultipleComplex<ItemStack, unsigned char>(gb)));
	CHECK_VERSION_ZERO((reader.readMultipleComplex<ItemStack, unsigned char>(kb)));
	CHECK_VERSION_ZERO((reader.readMultipleComplex<ItemStack, unsigned char>(eg)));
	CHECK_VERSION_ZERO((reader.readMultipleComplex<ItemStack, unsigned char>(mb)));
	CHECK_VERSION_ZERO((reader.readMultipleComplex<RecipeQueueItem, unsigned char>(oe)));

	reader.read<bool>(ye);
	reader.read<float>(fe);

	reader.readMultipleSimple<float, unsigned char>(qe);

	reader.read<bool>(yhh);

	return 0;
}

void TileEntityWorkstation::write(BinaryMemoryWriter &writer) {
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