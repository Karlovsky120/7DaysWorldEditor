#pragma once
#include "TileEntityPowered.h"

#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;
class ItemStack;

class TileEntityPowerSource : public TileEntityPowered {
public:
	TileEntityClassId getType() override;
	int read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) const override;

	TileEntityPowerSource();
	~TileEntityPowerSource();
};
