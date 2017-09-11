#pragma once

#include "Coordinate.h"
#include "TileEntity.h"

#include <vector>

class BinaryMemoryReader;
class ItemStack;

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

