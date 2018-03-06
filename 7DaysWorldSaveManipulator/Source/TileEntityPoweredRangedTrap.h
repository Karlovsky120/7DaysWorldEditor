#pragma once
#include "TileEntityPoweredBlock.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;
class ItemStack;

class TileEntityPoweredRangedTrap : public TileEntityPoweredBlock {
public:
	std::string lrz;

	bool flag;

	bool isLocked;
	std::vector<ItemStack> itemSlots;
	int targetType;

	TileEntityClassId getType() override;
	int read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer) const;

	TileEntityPoweredRangedTrap();
	~TileEntityPoweredRangedTrap();
};
