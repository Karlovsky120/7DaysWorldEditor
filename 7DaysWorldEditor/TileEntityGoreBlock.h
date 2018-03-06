#pragma once
#include "TileEntityLootContainer.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class TileEntityGoreBlock : public TileEntityLootContainer {
public:
	unsigned _int64 arz;

	TileEntityClassId getType() override;
	int read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) const override;

	TileEntityGoreBlock();
	~TileEntityGoreBlock();
};
