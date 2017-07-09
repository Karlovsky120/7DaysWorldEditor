#include "ItemStack.h"

#include "BinaryMemoryReader.h"
#include "ItemValue.h"

 std::vector<ItemStack *> *ItemStack::readItemStack(BinaryMemoryReader *const reader)
{
	std::vector<ItemStack *> *itemStackArray = new std::vector<ItemStack *>();
	reader->readMultipleComplex<ItemStack, unsigned short>(*itemStackArray);

	return itemStackArray;
}

ItemStack *ItemStack::read(BinaryMemoryReader *const reader)
{
	ItemValue *itemValue = new ItemValue();
	itemValue->read(reader);
	reader->read<short>(&count);
	return this;
}

ItemStack::ItemStack() {}
ItemStack::~ItemStack() {}
