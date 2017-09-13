#include "TileEntityWorkstation.h"

#include "BinaryMemoryReader.h"

void TileEntityWorkstation::read(BinaryMemoryReader &reader) {	
	TileEntity::read(reader);

	reader.read<unsigned char>(version);
	reader.read<unsigned _int64>(ib);

	reader.readMultipleComplex<ItemStack, unsigned char>(gb);
	reader.readMultipleComplex<ItemStack, unsigned char>(kb);
	reader.readMultipleComplex<ItemStack, unsigned char>(eg);
	reader.readMultipleComplex<ItemStack, unsigned char>(mb);
	reader.readMultipleComplex<RecipeQueueItem, unsigned char>(oe);

	reader.read<bool>(ye);
	reader.read<float>(fe);

	reader.readMultipleSimple<float, unsigned char>(qe);
}

TileEntityWorkstation::TileEntityWorkstation() {}
TileEntityWorkstation::~TileEntityWorkstation() {}