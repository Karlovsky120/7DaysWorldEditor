#pragma once
#include "ItemValue.h"

#include <vector>

class BinaryMemoryReader;

class ItemStack {
public:
	short count;
	ItemValue itemValue;

	void read(BinaryMemoryReader &reader);

	ItemStack();
	~ItemStack();
};

