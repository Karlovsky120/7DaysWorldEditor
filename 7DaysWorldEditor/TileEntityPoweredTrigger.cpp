#include "TileEntityPoweredTrigger.h"

#include "BinaryMemoryReader.h"

void TileEntityPoweredTrigger::reader(BinaryMemoryReader &reader) {
	TileEntityPowered::read(reader);

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
}

TileEntityPoweredTrigger::TileEntityPoweredTrigger() {}
TileEntityPoweredTrigger::~TileEntityPoweredTrigger() {}