#pragma once

#include "TileEntityLootContainer.h"

class BinaryMemoryReader;

class TileEntityGoreBlock : public TileEntityLootContainer
{
public:
	unsigned _int64 arz;

	void read(BinaryMemoryReader &reader);

	TileEntityGoreBlock();
	~TileEntityGoreBlock();
};

