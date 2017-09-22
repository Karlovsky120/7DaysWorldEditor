#pragma once
#include "TileEntity.h"

#include "ItemStack.h"
#include "ItemValue.h"

#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class TileEntityForge : public TileEntity {
public:
	unsigned _int64 ib;

	std::vector<ItemStack> gb;
	std::vector<ItemStack> kb;

	ItemStack fd;
	ItemStack mb;

	int hb;
	short qd;
	short yd;
	ItemValue tb;

	TileEntityClassId getType() override;
	void read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) override;

	TileEntityForge();
	~TileEntityForge();
};

