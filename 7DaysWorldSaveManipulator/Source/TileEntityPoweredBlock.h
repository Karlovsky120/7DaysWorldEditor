#pragma once
#include "DllHeader.h"

#include "TileEntityPowered.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class SDWSM_API TileEntityPoweredBlock : public TileEntityPowered {
public:
	bool uzz;

	TileEntityClassId getType() override;
	int read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer) const;

	TileEntityPoweredBlock();
	~TileEntityPoweredBlock();
};
