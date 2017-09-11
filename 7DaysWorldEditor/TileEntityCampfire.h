#pragma once

#include "ItemStack.h"
#include "ItemValue.h"
#include "TileEntity.h"

#include <vector>

class BinaryMemoryReader;

class TileEntityCampfire: public TileEntity
{
public:
	unsigned _int64 ib;

	std::vector<ItemStack> gb;
	std::vector<ItemStack> kb;

	ItemStack xb;
	ItemStack mb;

	int hb;
	ItemValue tb;

	bool isCooking;
	float db;

	void read(BinaryMemoryReader &reader) override;

	TileEntityCampfire();
	~TileEntityCampfire();
};

