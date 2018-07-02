#pragma once

#include "TileEntity.h"

#include "ItemStack.h"
#include "ItemValue.h"

#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class TileEntityCampfire : public TileEntity {
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

	TileEntityClassId getType() override;
	int read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) const override;

	TileEntityCampfire();
	~TileEntityCampfire();
};
