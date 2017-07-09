#pragma once

#include "TileEntity.h"

#include <vector>

class ItemStack;
class ItemValue;

class TileEntityCampfire: public TileEntity
{
public:

	unsigned _int64 *ib;

	std::vector<ItemStack *> gb;
	std::vector<ItemStack *> kb;

	ItemStack *xb;
	ItemStack *mb;

	int *hb;
	ItemValue *tb;

	bool *isCooking;
	float *db;

	TileEntityCampfire *read(BinaryMemoryReader *const reader) override;

	TileEntityCampfire();
	~TileEntityCampfire();
};

