#pragma once

#include "ItemStack.h"
#include "ItemValue.h"
#include "TileEntity.h"

#include <vector>

class BinaryMemoryReader;

class TileEntityForge : public TileEntity
{
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

	void read(BinaryMemoryReader &reader);

	TileEntityForge();
	~TileEntityForge();
};

