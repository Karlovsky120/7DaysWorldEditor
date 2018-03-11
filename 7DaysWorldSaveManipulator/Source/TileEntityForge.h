#pragma once
#include "DllHeader.h"

#include "TileEntity.h"

#include "ItemStack.h"
#include "ItemValue.h"

#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class SDWSM_API TileEntityForge : public TileEntity {
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
	int read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) const override;

	TileEntityForge();
	~TileEntityForge();
};
