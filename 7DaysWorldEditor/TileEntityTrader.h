#pragma once

#include "TileEntity.h"
#include "TraderData.h"

class BinaryMemoryReader;

class TileEntityTrader : public TileEntity {
public:
	int version;
	TraderData traderData;

	void read(BinaryMemoryReader &reader);

	TileEntityTrader();
	~TileEntityTrader();
};

