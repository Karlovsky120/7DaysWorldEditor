#pragma once

#include <vector>

class BinaryMemoryReader;
class ItemValue;

class ItemStack
{
public:
	short *count;

	ItemValue *itemValue;

	static std::vector<ItemStack *> *readItemStack(BinaryMemoryReader *const reader);
	ItemStack *read(BinaryMemoryReader *const reader);

	ItemStack();
	~ItemStack();
};

