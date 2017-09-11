#pragma once

#include "ItemValue.h"

#include <vector>

class BinaryMemoryReader;

class ItemStack
{
public:
	short count;
	ItemValue itemValue;

	//static std::vector<ItemStack *> *readItemStack(BinaryMemoryReader *const reader);
	void read(BinaryMemoryReader &reader);

	ItemStack();
	~ItemStack();
};

