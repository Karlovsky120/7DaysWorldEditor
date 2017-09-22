#pragma once
#include "TileEntityPowered.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class TileEntityPoweredBlock : public TileEntityPowered {
public:
	bool uzz;

	TileEntityClassId getType() override;
	void read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer);

	TileEntityPoweredBlock();
	~TileEntityPoweredBlock();
};

