#pragma once
#include "TileEntity.h"

#include "Coordinate.h"
#include "ItemStack.h"

#include <vector>

class BinaryMemoryReader;

class TileEntityLootContainer : public TileEntity {
public:
	unsigned short lootListIndex;
	Coordinate<unsigned short> ad;
	bool bTouched;
	unsigned int worldTimeTouched;
	bool bPlayerBackpack;

	std::vector<ItemStack> items;

	bool bPlayerStorage;

	void read(BinaryMemoryReader &reader) override;

	TileEntityLootContainer();
	~TileEntityLootContainer();
};

