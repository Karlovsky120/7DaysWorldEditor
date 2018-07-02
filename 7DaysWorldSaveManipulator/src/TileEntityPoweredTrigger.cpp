#include "TileEntityPoweredTrigger.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityPoweredTrigger::TileEntityPoweredTrigger() {}
TileEntityPoweredTrigger::~TileEntityPoweredTrigger() {}

TileEntityClassId TileEntityPoweredTrigger::getType() const {
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
