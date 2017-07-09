#pragma once

#include "Coordinate.h"
#include "TileEntity.h"

#include <algorithm>
#include <vector>

class ItemStack;

class TileEntityLootContainer :public TileEntity
{
public:

	unsigned short *lootListIndex;
	Coordinate<unsigned short> ad;
	bool *bTouched;
	unsigned int *worldTimeTouched;
	bool *bPlayerBackpack;

	std::vector<ItemStack *> items;

	bool *bPlayerStorage;

	TileEntityLootContainer *read(BinaryMemoryReader *const reader) override;

	TileEntityLootContainer();
	~TileEntityLootContainer();
};

