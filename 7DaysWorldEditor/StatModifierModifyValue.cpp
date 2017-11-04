#include "StatModifierModifyValue.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

StatModifierClassId StatModifierModifyValue::getType() {
	return ModifyValue;
}

void StatModifierModifyValue::write(BinaryMemoryWriter &writer) {
	StatModifier::write(writer);

	writer.write<float>(unknownV);
	writer.write<float>(unknownF);
}

int StatModifierModifyValue::readMore(BinaryMemoryReader &reader) {
	CHECK_VERSION_ZERO(StatModifier::readMore(reader));

	reader.read<float>(unknownV);
	reader.read<float>(unknownF);

	return 0;
}

StatModifierModifyValue::StatModifierModifyValue() {}
StatModifierModifyValue::~StatModifierModifyValue() {}