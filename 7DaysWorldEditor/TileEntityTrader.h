#pragma once

#include "TileEntity.h"
#include "TraderData.h"

class TileEntityTrader : public TileEntity
{
public:
	int *version;
	TraderData traderData;

	TileEntityTrader *read(BinaryMemoryReader *const reader);

	TileEntityTrader();
	~TileEntityTrader();
};

