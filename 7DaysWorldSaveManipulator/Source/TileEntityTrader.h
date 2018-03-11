#pragma once
#include "DllHeader.h"

#include "TileEntity.h"

#include "TraderData.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class SDWSM_API TileEntityTrader : public TileEntity {
public:
	int version;
	TraderData traderData;

	TileEntityClassId getType() override;
	int read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) const override;

	TileEntityTrader();
	~TileEntityTrader();
};
