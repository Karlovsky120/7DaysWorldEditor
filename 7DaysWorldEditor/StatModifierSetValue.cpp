#include "StatModifierSetValue.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

StatModifierClassId StatModifierSetValue::getType() {
	return SetValue;
}

void StatModifierSetValue::write(BinaryMemoryWriter &writer) {
	StatModifier::write(writer);

	writer.write<float>(unknownV);
	writer.write<float>(unknownF);
}

int StatModifierSetValue::readMore(BinaryMemoryReader &reader) {
	CHECK_VERSION_ZERO(StatModifier::readMore(reader));

	reader.read<float>(unknownV);
	reader.read<float>(unknownF);

	return 0;
}

StatModifierSetValue::StatModifierSetValue() {}
StatModifierSetValue::~StatModifierSetValue() {}
