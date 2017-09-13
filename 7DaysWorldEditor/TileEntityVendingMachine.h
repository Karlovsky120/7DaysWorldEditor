#pragma once
#include "TileEntityTrader.h"

#include "TraderData.h"

#include <string>
#include <vector>

class BinaryMemoryReader;

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

	void read(BinaryMemoryReader &reader) override;

	TileEntityVendingMachine();
	~TileEntityVendingMachine();
};

