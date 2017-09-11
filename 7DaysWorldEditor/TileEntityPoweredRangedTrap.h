#pragma once
#include "TileEntityPoweredBlock.h"

class BinaryMemoryReader;
class ItemStack;

class TileEntityPoweredRangedTrap : public TileEntityPoweredBlock {
public:
	std::string lrz;

	bool isLocked;
	std::vector<ItemStack> itemSlots;
	int targetType;

	void read(BinaryMemoryReader &reader);

	TileEntityPoweredRangedTrap();
	~TileEntityPoweredRangedTrap();
};