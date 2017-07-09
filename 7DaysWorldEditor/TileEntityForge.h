#pragma once

#include "TileEntity.h"

#include <vector>

class BinaryMemoryReader;
class ItemStack;
class ItemValue;

class TileEntityForge : public TileEntity
{
public:
	unsigned _int64 *ib;

	std::vector<ItemStack *> gb;
	std::vector<ItemStack *> kb;

	ItemStack *fd;
	ItemStack *mb;

	int *hb;
	short *qd;
	short *yd;
	ItemValue *tb;

	TileEntityForge *read(BinaryMemoryReader *const reader);

	TileEntityForge();
	~TileEntityForge();
};

