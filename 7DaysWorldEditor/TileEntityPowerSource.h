#pragma once
#include "TileEntityPowered.h"

#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;
class ItemStack;

class TileEntityPowerSource : public TileEntityPowered {
public:
	bool flag;

	bool isOn;

	unsigned short maxFuel;
	unsigned short currentFuel;

	unsigned short solarInput;
	std::vector<ItemStack> itemSlots;

	unsigned short maxOutput;
	unsigned short lastOutput;

	TileEntityClassId getType() override;
	void read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) override;

	TileEntityPowerSource();
	~TileEntityPowerSource();
};

