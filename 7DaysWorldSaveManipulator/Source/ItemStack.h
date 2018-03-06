#pragma once
#include "ItemValue.h"

#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class ItemStack {
public:
	short count;
	ItemValue itemValue;

	int read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer) const;

	ItemStack();
	~ItemStack();
};
