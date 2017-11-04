#pragma once
#include "TileEntity.h"

#include "Coordinate.h"
#include "ItemStack.h"

#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class TileEntityLootContainer : public TileEntity {
public:
	unsigned short lootListIndex;
	Coordinate<unsigned short> ad;
	bool bTouched;
	unsigned int worldTimeTouched;
	bool bPlayerBackpack;

	std::vector<ItemStack> items;

	bool bPlayerStorage;

	TileEntityClassId getType() override;
	int read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) override;

	TileEntityLootContainer();
	~TileEntityLootContainer();
};

