#include "TileEntityVendingMachine.h"

#include "BinaryMemoryReader.h"


TileEntityVendingMachine *TileEntityVendingMachine::read(BinaryMemoryReader *const reader)
{
	TileEntityTrader::read(reader);

	reader->read<int>(&version);

	reader->read<bool>(&vd);
	reader->read<std::string>(&gd);
	reader->read<std::string>(&xd);

	reader->readMultipleSimple<std::string, int>(kd);

	traderData.read(reader);

	if (*traderData.traderID == 5) {
		reader->read<unsigned _int64>(&dd);
	}

	return this;
}

TileEntityVendingMachine::TileEntityVendingMachine() {}
TileEntityVendingMachine::~TileEntityVendingMachine() {}