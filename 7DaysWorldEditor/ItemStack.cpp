#include "ItemStack.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

int ItemStack::read(BinaryMemoryReader &reader) {
	CHECK_VERSION_ZERO(itemValue.read(reader));
	reader.read<short>(count);
	return 0;
}

void ItemStack::write(BinaryMemoryWriter &writer) const {
	itemValue.write(writer);
	writer.write<short>(count);
}

ItemStack::ItemStack() {}
ItemStack::~ItemStack() {}
