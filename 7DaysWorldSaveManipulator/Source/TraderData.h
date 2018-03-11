#pragma once
#include "DllHeader.h"

#include "ItemStack.h"

#include "VersionCheck.h"

#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class SDWSM_API TraderData {
public:
	int traderID;
	unsigned _int64 lastInventoryUpdate;
	unsigned char fileVersion;

	std::vector<ItemStack> primaryInventory;
	std::vector<std::vector<ItemStack>> tierItemGroups;

	int availableMoney;
	std::vector<char> jj;

	int read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer) const;

	TraderData();
	~TraderData();
};
