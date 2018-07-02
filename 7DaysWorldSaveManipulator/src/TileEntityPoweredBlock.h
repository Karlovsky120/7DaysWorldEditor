#pragma once

#include "TileEntityPowered.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class TileEntityPoweredBlock : public TileEntityPowered {
public:
	bool uzz;

	TileEntityPoweredBlock();
	~TileEntityPoweredBlock();

	TileEntityClassId getType() const override;
	int read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) const override;
};
