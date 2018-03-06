#include "TileEntityPoweredTrigger.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntityPoweredTrigger::getType() {
	return Trigger;
}

int TileEntityPoweredTrigger::read(BinaryMemoryReader &reader) {
	TileEntityPowered::read(reader);

	reader.read<unsigned char>(triggerType);

	if (Motion == triggerType) {
		reader.read<std::string>(lrz);
	}

	return 0;
}

void TileEntityPoweredTrigger::write(BinaryMemoryWriter &writer) const {
	TileEntityPowered::write(writer);

	writer.write<unsigned char>(triggerType);

	if (Motion == triggerType) {
		writer.write<std::string>(lrz);
	}
}

TileEntityPoweredTrigger::TileEntityPoweredTrigger() {}
TileEntityPoweredTrigger::~TileEntityPoweredTrigger() {}
