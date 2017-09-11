#include "TileEntityVendingMachine.h"

#include "BinaryMemoryReader.h"


void TileEntityVendingMachine::read(BinaryMemoryReader &reader) {
	TileEntityTrader::read(reader);

	reader.read<int>(version);

	reader.read<bool>(vd);
	reader.read<std::string>(gd);
	reader.read<std::string>(xd);

	reader.readMultipleSimple<std::string, int>(kd);

	reader.read<unsigned _int64>(bd);

	traderData.read(reader);

	//Ugly hack because this is stored the only thing not stored in the save file as it should be.
	if (traderData.traderID == 5) {
		reader.read<unsigned _int64>(dd);
	}
}

TileEntityVendingMachine::TileEntityVendingMachine() {}
TileEntityVendingMachine::~TileEntityVendingMachine() {}