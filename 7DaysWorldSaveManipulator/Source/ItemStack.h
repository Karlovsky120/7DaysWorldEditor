#pragma once
#include "DllHeader.h"

#include "ItemValue.h"

#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class SDWSM_API ItemStack {
public:
	short count;
	ItemValue itemValue;

	int read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer) const;

	ItemStack();
	~ItemStack();
};
