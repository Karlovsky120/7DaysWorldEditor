#pragma once
#include "TileEntityPowered.h"

class BinaryMemoryReader;

class TileEntityPoweredBlock : public TileEntityPowered {
public:
	bool uzz;

	void read(BinaryMemoryReader &reader);

	TileEntityPoweredBlock();
	~TileEntityPoweredBlock();
};

