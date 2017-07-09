#pragma once

#include <string>
#include <vector>

#include "TileEntityTrader.h"
#include "TraderData.h"

class BinaryMemoryReader;

class TileEntityVendingMachine : public TileEntityTrader
{
public:

	int *version;
	bool *vd;
	std::string *gd;
	std::string *xd;

	std::vector<std::string *> kd;

	unsigned _int64 *bd;

	TraderData traderData;

	unsigned _int64 *dd;

	TileEntityVendingMachine *read(BinaryMemoryReader *const reader) override;

	TileEntityVendingMachine();
	~TileEntityVendingMachine();
};

