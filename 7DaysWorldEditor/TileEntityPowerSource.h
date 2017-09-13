#pragma once
#include "TileEntityPowered.h"

#include <vector>

class ItemStack;

class TileEntityPowerSource : public TileEntityPowered {
public:
	bool isOn;

	unsigned short maxFuel;
	unsigned short currentFuel;

	unsigned short solarInput;
	std::vector<ItemStack> itemSlots;

	unsigned short maxOutput;
	unsigned short lastOutput;

	void reader(BinaryMemoryReader &reader);

	TileEntityPowerSource();
	~TileEntityPowerSource();
};

