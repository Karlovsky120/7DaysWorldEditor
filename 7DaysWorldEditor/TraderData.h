#pragma once
#include "ItemStack.h"

#include "SaveVersionCheck.h"

#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class TraderData : public SaveVersionCheck {
public:
	int traderID;
	unsigned _int64 lastInventoryUpdate;
	unsigned char fileVersion;

	std::vector<ItemStack> primaryInventory;
	std::vector<std::vector<ItemStack>> tierItemGroups;

	int availableMoney;
	std::vector<char> jj;

	int read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer);

	TraderData();
	~TraderData();
};

