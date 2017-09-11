#include "TileEntitySign.h"

#include "BinaryMemoryReader.h"

void TileEntitySign::read(BinaryMemoryReader &reader) {
	TileEntity::read(reader);

	reader.read<int>(version);

	reader.read<bool>(vd);
	reader.read<std::string>(gd);
	reader.read<std::string>(xd);

	reader.readMultipleSimple<std::string, int>(kd);
	reader.read<std::string>(signText);
}

TileEntitySign::TileEntitySign() {}
TileEntitySign::~TileEntitySign() {}