#include "TileEntityPoweredTrigger.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityClassId TileEntityPoweredTrigger::getType() {
	return Trigger;
}

int TileEntityPoweredTrigger::read(BinaryMemoryReader &reader) {
	CHECK_VERSION_ZERO(TileEntityPowered::read(reader));

	reader.read<unsigned char>(triggerType);

	if (Motion == triggerType) {
		reader.read<std::string>(lrz);
	} else if (TripWire == triggerType) {
		reader.read<bool>(showTriggerOptions);
	} else if (Switch == triggerType) {
		reader.read<unsigned char>(property1);
		reader.read<unsigned char>(property2);
	}

	if (Motion == triggerType) {
		reader.read<int>(targetType);
	}

	return 0;
}

void TileEntityPoweredTrigger::write(BinaryMemoryWriter &writer) {
	TileEntityPowered::write(writer);

	writer.write<unsigned char>(triggerType);

	if (Motion == triggerType) {
		writer.write<std::string>(lrz);
	} else if (TripWire == triggerType) {
		writer.write<bool>(showTriggerOptions);
	} else if (Switch == triggerType) {
		writer.write<unsigned char>(property1);
		writer.write<unsigned char>(property2);
	}

	if (Motion == triggerType) {
		writer.write<int>(targetType);
	}
}

TileEntityPoweredTrigger::TileEntityPoweredTrigger() {}
TileEntityPoweredTrigger::~TileEntityPoweredTrigger() {}