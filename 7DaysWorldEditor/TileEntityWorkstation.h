#pragma once
#include "TileEntity.h"

#include "ItemStack.h"
#include "RecipeQueueItem.h"

#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class TileEntityWorkstation : public TileEntity {
public:
	unsigned char version;
	unsigned _int64 ib;

	std::vector<ItemStack> gb;
	std::vector<ItemStack> kb;
	std::vector<ItemStack> eg;
	std::vector<ItemStack> mb;

	std::vector<RecipeQueueItem> oe;

	bool ye;
	float fe;
	std::vector<float> qe;

	bool yhh;

	TileEntityClassId getType() override;
	void read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) override;

	TileEntityWorkstation();
	~TileEntityWorkstation();
};

