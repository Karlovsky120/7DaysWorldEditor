#pragma once
#include "DllHeader.h"

#include "TileEntityLootContainer.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class SDWSM_API TileEntityGoreBlock : public TileEntityLootContainer {
public:
	unsigned _int64 arz;

	TileEntityClassId getType() override;
	int read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) const override;

	TileEntityGoreBlock();
	~TileEntityGoreBlock();
};
