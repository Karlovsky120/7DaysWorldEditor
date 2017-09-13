#include "ItemStack.h"

#include "BinaryMemoryReader.h"

void ItemStack::read(BinaryMemoryReader &reader) {
	itemValue.read(reader);
	reader.read<short>(count);
}

ItemStack::ItemStack() {}
ItemStack::~ItemStack() {}
