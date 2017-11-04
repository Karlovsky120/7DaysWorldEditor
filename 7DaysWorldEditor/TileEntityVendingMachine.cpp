#include "TileEntityVendingMachine.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntityVendingMachine::getType() {
	return VendingMachine;
}

int TileEntityVendingMachine::read(BinaryMemoryReader &reader) {
	CHECK_VERSION_ZERO(TileEntityTrader::read(reader));

	reader.read<int>(version);
	CHECK_VERSION(version, TILE_ENTITY_VENDING_MACHINE);

	reader.read<bool>(vd);
	reader.read<std::string>(gd);
	reader.read<std::string>(xd);

	reader.readMultipleSimple<std::string, int>(kd);

	reader.read<unsigned _int64>(bd);

	CHECK_VERSION_ZERO(traderData.read(reader));

	// Ugly assumption because this is the only thing not stored in the save file as it should be.
	// If there are rentable vending machines in game which are not regular vanilla, any chunk that
	// has them cannot be read properly.
	if (traderData.traderID == 5) {
		reader.read<unsigned _int64>(dd);
	}

	return 0;
}

void TileEntityVendingMachine::write(BinaryMemoryWriter &writer) {
	TileEntityTrader::write(writer);

	writer.write<int>(version);

	writer.write<bool>(vd);
	writer.write<std::string>(gd);
	writer.write<std::string>(xd);

	writer.writeMultipleSimple<std::string, int>(kd);

	writer.write<unsigned _int64>(bd);

	traderData.write(writer);

	//Ugly assumption because this is the only thing not stored in the save file as it should be.
	//If there are rentable vending machines in game which are not regular vanilla, any chunk that
	//has them cannot be read properly.
	if (traderData.traderID == 5) {
		writer.write<unsigned _int64>(dd);
	}
}

TileEntityVendingMachine::TileEntityVendingMachine() {}
TileEntityVendingMachine::~TileEntityVendingMachine() {}