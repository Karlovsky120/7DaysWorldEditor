#pragma once
#include "TileEntity.h"

#include "TraderData.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class TileEntityTrader : public TileEntity {
public:
	int version;
	TraderData traderData;

	TileEntityClassId getType() override;
	int read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) override;

	TileEntityTrader();
	~TileEntityTrader();
};

