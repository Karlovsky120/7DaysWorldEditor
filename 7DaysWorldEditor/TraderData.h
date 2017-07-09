#pragma once

#include "ItemStack.h"

#include <vector>

class BinaryMemoryReader;

class TraderData
{
public:

	int *traderID;
	unsigned _int64 *lastInventoryUpdate;
	unsigned char *fileVersion;

	std::vector<ItemStack *> *primaryInventory;
	std::vector<std::vector<ItemStack *> *> tierItemGroups;

	int *availableMoney;
	std::vector<char *> jj;

	TraderData *read(BinaryMemoryReader *const reader);

	TraderData();
	~TraderData();
};

