#pragma once

#include "TileEntityTrader.h"

#include "TraderData.h"

#include <string>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class TileEntityVendingMachine : public TileEntityTrader {
public:
	int version;
	bool vd;
	std::string gd;
	std::string xd;

	std::vector<std::string> kd;

	unsigned _int64 bd;

	TraderData traderData;

	unsigned _int64 dd;

	TileEntityClassId getType() override;
	int read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) const override;

	TileEntityVendingMachine();
	~TileEntityVendingMachine();
};
