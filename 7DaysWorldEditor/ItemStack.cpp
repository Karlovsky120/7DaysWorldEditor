#include "ItemStack.h"

#include "BinaryMemoryReader.h"
#include "ItemValue.h"

/*std::vector<ItemStack *> *ItemStack::readItemStack(BinaryMemoryReader *const reader) {
	std::vector<ItemStack *> *itemStackArray = new std::vector<ItemStack *>();
	reader->readMultipleComplex<ItemStack, unsigned short>(itemStackArray);

	return itemStackArray;
}*/

void ItemStack::read(BinaryMemoryReader &reader) {
	itemValue.read(reader);
	reader.read<short>(count);
}

ItemStack::ItemStack() {}
ItemStack::~ItemStack() {}
